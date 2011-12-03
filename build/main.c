
#include <pic18f4550.h>
#include "fuses.h"
#include <stdint.h>
#include <timer/timer2.h>

void delay_ms(uint16_t x);

void main() {
    uint8_t count = 0;
    TRISAbits.TRISA0 = 0;
    TRISCbits.TRISC2 = 0;
    LATAbits.LATA0 = 1;
    /*
    timer2_setup(TIMER2_DIVIDED_BY_16, 0xff, 0x0f);
    timer2_enable();    
    PIE1bits.TMR2IE = 1;
    INTCONbits.GIE = 1;
    
    * */
    // Timer 2
   PR2=0xff;   // 4 MHz clock -> 5kHz PWM frequency
   //T2CONbits.TMR2ON = 1;
//   T2CON = (1<<TMR2ON);
    T2CON = 0xff;

   // Initialize Control PWM
   //CCPR1L  = 0x19;    // Initial Duty
   CCP1CON = 0x2c;  // PWM mode set and 5,4 duty = 0

    while(1) {
        //for(count = 10; count < 250; count += 5) {
         //   CCPR1L = count;
         //   delay_ms(5000);
        //}
        LATAbits.LATA0 = 1;
        delay_ms(3);
        LATAbits.LATA0 = 0;
        delay_ms(36);
    }
}

/* 
 * Delay loop.
 * This is not calibrated to milliseconds,
 * Since we have interruptions, we need to calibrate
 */
void delay_ms(uint16_t x) {
    uint8_t y, z;
    for(; x > 0 ; x--){
        for( y = 0 ; y < 40 ; y++){
            for( z = 0 ; z < 7 ; z++){
                __asm nop __endasm;
            }
        }
    }
}
