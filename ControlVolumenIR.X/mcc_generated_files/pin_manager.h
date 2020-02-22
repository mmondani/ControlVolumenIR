/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16F1825
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_ROJO aliases
#define LED_ROJO_TRIS                 TRISAbits.TRISA2
#define LED_ROJO_LAT                  LATAbits.LATA2
#define LED_ROJO_PORT                 PORTAbits.RA2
#define LED_ROJO_WPU                  WPUAbits.WPUA2
#define LED_ROJO_ANS                  ANSELAbits.ANSA2
#define LED_ROJO_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_ROJO_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_ROJO_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_ROJO_GetValue()           PORTAbits.RA2
#define LED_ROJO_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_ROJO_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_ROJO_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ROJO_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_ROJO_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_ROJO_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set POT2_INC aliases
#define POT2_INC_TRIS                 TRISAbits.TRISA4
#define POT2_INC_LAT                  LATAbits.LATA4
#define POT2_INC_PORT                 PORTAbits.RA4
#define POT2_INC_WPU                  WPUAbits.WPUA4
#define POT2_INC_ANS                  ANSELAbits.ANSA4
#define POT2_INC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT2_INC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT2_INC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT2_INC_GetValue()           PORTAbits.RA4
#define POT2_INC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT2_INC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT2_INC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT2_INC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT2_INC_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT2_INC_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set POT1_INC aliases
#define POT1_INC_TRIS                 TRISAbits.TRISA5
#define POT1_INC_LAT                  LATAbits.LATA5
#define POT1_INC_PORT                 PORTAbits.RA5
#define POT1_INC_WPU                  WPUAbits.WPUA5
#define POT1_INC_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define POT1_INC_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define POT1_INC_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define POT1_INC_GetValue()           PORTAbits.RA5
#define POT1_INC_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define POT1_INC_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define POT1_INC_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define POT1_INC_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set PULSADOR aliases
#define PULSADOR_TRIS                 TRISCbits.TRISC0
#define PULSADOR_LAT                  LATCbits.LATC0
#define PULSADOR_PORT                 PORTCbits.RC0
#define PULSADOR_WPU                  WPUCbits.WPUC0
#define PULSADOR_ANS                  ANSELCbits.ANSC0
#define PULSADOR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define PULSADOR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define PULSADOR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define PULSADOR_GetValue()           PORTCbits.RC0
#define PULSADOR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define PULSADOR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define PULSADOR_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define PULSADOR_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define PULSADOR_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define PULSADOR_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IR_OUT aliases
#define IR_OUT_TRIS                 TRISCbits.TRISC1
#define IR_OUT_LAT                  LATCbits.LATC1
#define IR_OUT_PORT                 PORTCbits.RC1
#define IR_OUT_WPU                  WPUCbits.WPUC1
#define IR_OUT_ANS                  ANSELCbits.ANSC1
#define IR_OUT_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IR_OUT_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IR_OUT_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IR_OUT_GetValue()           PORTCbits.RC1
#define IR_OUT_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IR_OUT_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IR_OUT_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IR_OUT_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IR_OUT_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IR_OUT_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set POT2_UD aliases
#define POT2_UD_TRIS                 TRISCbits.TRISC2
#define POT2_UD_LAT                  LATCbits.LATC2
#define POT2_UD_PORT                 PORTCbits.RC2
#define POT2_UD_WPU                  WPUCbits.WPUC2
#define POT2_UD_ANS                  ANSELCbits.ANSC2
#define POT2_UD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define POT2_UD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define POT2_UD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define POT2_UD_GetValue()           PORTCbits.RC2
#define POT2_UD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define POT2_UD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define POT2_UD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define POT2_UD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define POT2_UD_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define POT2_UD_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set POT1_UD aliases
#define POT1_UD_TRIS                 TRISCbits.TRISC3
#define POT1_UD_LAT                  LATCbits.LATC3
#define POT1_UD_PORT                 PORTCbits.RC3
#define POT1_UD_WPU                  WPUCbits.WPUC3
#define POT1_UD_ANS                  ANSELCbits.ANSC3
#define POT1_UD_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define POT1_UD_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define POT1_UD_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define POT1_UD_GetValue()           PORTCbits.RC3
#define POT1_UD_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define POT1_UD_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define POT1_UD_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define POT1_UD_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define POT1_UD_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define POT1_UD_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set POT2_CS aliases
#define POT2_CS_TRIS                 TRISCbits.TRISC4
#define POT2_CS_LAT                  LATCbits.LATC4
#define POT2_CS_PORT                 PORTCbits.RC4
#define POT2_CS_WPU                  WPUCbits.WPUC4
#define POT2_CS_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define POT2_CS_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define POT2_CS_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define POT2_CS_GetValue()           PORTCbits.RC4
#define POT2_CS_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define POT2_CS_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define POT2_CS_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define POT2_CS_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)

// get/set POT1_CS aliases
#define POT1_CS_TRIS                 TRISCbits.TRISC5
#define POT1_CS_LAT                  LATCbits.LATC5
#define POT1_CS_PORT                 PORTCbits.RC5
#define POT1_CS_WPU                  WPUCbits.WPUC5
#define POT1_CS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define POT1_CS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define POT1_CS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define POT1_CS_GetValue()           PORTCbits.RC5
#define POT1_CS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define POT1_CS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define POT1_CS_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define POT1_CS_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/