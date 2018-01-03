/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC18F45K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    // edit 4 bits in CIOCON register (CAN IO control)
    CIOCONbits.CLKSEL = 1;  // CAN clk select
    CIOCONbits.ENDRHI = 1;  // enable drive high (CANTX drives VDD when recessive)
    CIOCONbits.TX2SRC = 0;  // CANTX2 pin data source (output CANTX)
    CIOCONbits.TX2EN = 1;   // CANTX pin enable (output CANRX or CAN clk based on TX2SRC)
    
    bool int1_state = false;
    uint8_t message = 0;
    RA1 = 1;
    
//    double VDD = 5000.0;    // input voltage 5V
//    double x = VDD / 4096.0;
//    
//    uint8_t ADC_result_H, ADC_result_L, CCP_result_H, CCP_result_L;
//    adc_result_t ADCResult;
//    uint16_t CCP_result;

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // ADC
//        ADCResult = ADC_GetConversion(0x05) * x;
//        ADC_result_H = ADCResult >> 8;
//        ADC_result_L = ADCResult;
        int1_state = INT1_GetInterruptState();
        if(int1_state) {
            message = 0xFF;
            RB4 = 0;
        } else {
            message = 0x0;
            RB4 = 1;
        }
        uCAN_MSG test;
        test.frame.idType=dSTANDARD_CAN_MSG_ID_2_0B;
        test.frame.id=0x174;
        test.frame.dlc=2;
        test.frame.data0 = message;
        test.frame.data1 = message;
//        test.frame.data0=ADC_result_H;
//        test.frame.data1=ADC_result_L;
//        test.frame.data2=ADC_result_H;
//        test.frame.data3=ADC_result_L;
//        test.frame.data4=ADC_result_H;
//        test.frame.data5=ADC_result_L;
//        test.frame.data6=ADC_result_H;
//        test.frame.data7=ADC_result_L;
        
        CAN_transmit(&test);
        
//        uint16_t result = ADC_GetConversion(0x05) * x;
//        ADC_result_H = result >> 8;
//        ADC_result_L = result;
//        // input capture
//        CCP_result = 16000000.0 / time_diff;
//        CCP_result_H = CCP_result >> 8;
//        CCP_result_L = CCP_result;
//        uint16_t result = ADC_GetConversion(analog2) * x;
//        ADC_result_H = result >> 8;
//        ADC_result_L = result;
//        uint16_t result = ADC_GetConversion(analog2) * x;
//        ADC_result_H = result >> 8;
//        ADC_result_L = result;
//        test.frame.idType=dSTANDARD_CAN_MSG_ID_2_0B;
//        test.frame.id=0x175;
//        test.frame.dlc=8;
//        test.frame.data0=ADC_result_H;
//        test.frame.data1=ADC_result_L;
//        test.frame.data2=CCP_result_H;
//        test.frame.data3=CCP_result_L;
//        test.frame.data4=ADC_result_H;
//        test.frame.data5=ADC_result_L;
//        test.frame.data6=ADC_result_H;
//        test.frame.data7=ADC_result_L;
        
//        CAN_transmit(&test);
        //for(int i = 0; i<10; ++i);
        // Add your application code
    }
}
/**
 End of File
*/