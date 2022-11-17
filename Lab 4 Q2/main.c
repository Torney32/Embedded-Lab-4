#include <msp430.h> 


/**
 * pwm w/ 10% dc
 * 500 ms period
 * polling process
 * measure results
 *
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;

        P6DIR |= BIT0;          // P1.0  output
        P6SEL0 |= BIT0;
        P6SEL1 &= ~BIT0;

        //PWM Generator
        TB3CCR0 = 16384;
        TB3CCTL1 = OUTMOD_7;
        TB3CCR1 = 1638;
        TB3CTL = TBSSEL_1 + MC_1 + TBCLR;

        while(1){
            P6OUT ^= BIT0;
        }
    }
