/**
  CCP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp2.c

  @Summary
    This is the generated driver implementation file for the CCP2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for CCP2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.3
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "ccp2.h"

/**
  Section: Capture Module APIs
*/

void CCP2_Initialize(void)
{
    // Set the CCP2 to the options selected in the User Interface

    // CCP2M 16th rising edge; DC2B 0; 
    CCP2CON = 0x07;    

    // CCPR2L 0; 
    CCPR2L = 0x00;    

    // CCPR2H 0; 
    CCPR2H = 0x00;    
    
    // Selecting Timer 1
    CCPTMRSbits.C2TSEL = 0x0;

    // Clear the CCP2 interrupt flag
    PIR3bits.CCP2IF = 0;

    // Enable the CCP2 interrupt
    PIE3bits.CCP2IE = 1;
}

void CCP2_CaptureISR(void)
{
    CCP_PERIOD_REG_T module;

    // Clear the CCP2 interrupt flag
    PIR3bits.CCP2IF = 0;
    
    // Copy captured value.
    module.ccpr2l = CCPR2L;
    module.ccpr2h = CCPR2H;
//    if(read_available){ //can read the timer difference
//        read_available = !read_available;
        if(prev_reading >= module.ccpr2_16Bit)   time_diff = 0xFFFF - (prev_reading - module.ccpr2_16Bit);
        else    time_diff = module.ccpr2_16Bit - prev_reading;
//    }
//    else    read_available = !read_available;
    //Reading = module.ccpr2_16Bit;
    //return prev_reading;
    // Return 16bit captured value
    //CCP2_CallBack(module.ccpr2_16Bit);
    prev_reading = module.ccpr2_16Bit;
}

void CCP2_CallBack(uint16_t capturedValue)
{
//    // Add your code here
//    if(cycle_num == 0){
//        curTime = TMR2_ReadTimer();
//        cycle_num++;
//    }
//    else{
//        if(cycle_num<10)    cycle_num++;
//        else if(cycle_num == 10){
//        cycle_num=0;
//        read_available=true;
//        uint16_t newTime=TMR2_ReadTimer();
////        if(curTime>newTime) 
//            time_diff = newTime-curTime;
////        else    time_diff = newTime + timer1ReloadVal - curTime;
//        }
//    }
}

//uint16_t CCP2_GetReading(){
//    return Reading;
//}
//
//bool CCP2_CaptureAvailable(){
//     return read_available;
//}

/**
 End of File
*/