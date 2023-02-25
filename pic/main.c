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


#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

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
    /*
     * uint_8 tempHigh = ...; //relatively high temperature
     * uint_8 tempLow = ...; //relatively low temperature
     * uint_8 humHigh = ...; //relatively high humidity
     * uint_8 humLow = ...; //relatively low humidity
     * uint_8 windHigh
     * 
     * danger(int level, boolean reset){
     *      //add danger level;
     *      //move stepper according to danger
     * }
     */

    while (1)
    {
        // Add your application code
        /*
         * if (reset button press){
         *      danger(0,true);
         * }
         * 
         * windSpeed = Read ANA0 // The wind speed
         * humidity = Read ANA1 //The humidity
         * temperature = Read ANA2 //The temperature
         * 
         * windSpeedCalc = ... //From input value to calculated wind speed
         * humidityCalc = ... //From input value to calculated humidity
         * temperature = ... //From input value to calculated temperature
         * 
         * if (temperature > tempHigh && humidityCalc < humLow){
         *      danger(3, false);
         * }
         * if (temperature < tempLow && humidityCalc > humHigh){
         *      danger(2, false);
         * }
         * if (windSpeedCalc > windHigh){
         *      danger(1, false);
         * }
         * 
         * dangerLevelCalc=...;
         */
    }
}
/**
 End of File
*/
