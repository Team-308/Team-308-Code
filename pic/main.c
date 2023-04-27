/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18LF27K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#pragma LVP = ON
/*
                         Main application
 */

uint8_t data1;
uint8_t data12;
int ii;
float value;

bool loop = true;

void EUSART1intrrupt(void){
    EUSART1_Receive_ISR();

    if(EUSART1_is_rx_ready()){
        data1 = EUSART1_Read();
        data12 = EUSART1_Read();
        while(loop){
            if(EUSART1_is_tx_ready()){
                loop = false;
            }
        }
        loop = true;
        EUSART1_Write(data1);
        EUSART1_Write(data12);
        while(loop){
            if(EUSART1_is_tx_done()){
                loop = false;
            }
        }
    }
    
    LED_0_Toggle();
}

void main(void)
{
    volatile uint8_t rxData;
    uint8_t humid;
    uint8_t wind;
    int wind_V;
    int humid_V;
    // Initialize the device
    SYSTEM_Initialize();
    TMR2_Initialize();
    TMR2_Start();
    SPI1_Initialize();
    SPI2_Initialize();
    EUSART1_Initialize();
    PWM4_Initialize();
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    EUSART1_SetRxInterruptHandler(EUSART1intrrupt);

    while (1)
    {
        wind_V = Wind_Pin_GetValue();
        humid_V = Humid_Pin_GetValue();
        
        if(wind_V && humid_V>0){
            if(wind_V>3.17){
                SS_pin_SetHigh();
                DIR_Pin_SetHigh();
            }else{
                SS_pin_SetHigh();
                DIR_Pin_SetLow();
            }
        }else{
                SS_pin_SetHigh();
        }
        
        // Add your application code
        wind = SPI1_ReadByte();
        
        humid = SPI2_ReadByte();
        // Logic to echo received data
            if(EUSART1_is_rx_ready())
            {
                rxData = EUSART1_Read();
                if(EUSART1_is_tx_ready())
                {
                    EUSART1_Write(rxData);
                }
            }
        
            uint8_t dir1 = 0b11001111;
            uint8_t dir2 = 0b11001101;
            uint8_t receive;

        SPI1_Open(SPI1_DEFAULT);
        SS_pin_SetLow();
        printf("Send: %u\r\n",dir1);

        receive = SPI1_ExchangeByte(dir1);
        printf("Receive: %u\r\n",receive);
        SS_pin_SetHigh();
        SPI1_Close();

        

        SPI1_Open(SPI1_DEFAULT);
        SS_pin_SetLow();
        printf("Send: %u\r\n",dir2);

        receive = SPI1_ExchangeByte(dir2);
        printf("Receive: %u\r\n",receive);
        SS_pin_SetHigh();
        SPI1_Close();
        
        if(ii>=100){
            ii=0;
        }
        value= (float) ii/10;
        printf("W: %u + H: %u  \r\n", wind, humid);
        
        
    }
}
/**
 End of File
*/
