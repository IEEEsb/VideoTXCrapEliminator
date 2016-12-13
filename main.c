
// PIC10F200 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = OFF      // Master Clear Enable (GP3/MCLR pin fuction is digital I/O, MCLR internally tied to VDD)
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void main(void) {
    OPTION = 0;
    TRISGPIO = 0b00011011;
    GPIObits.GP2 = 0;
    __delay_ms(3000);
    GPIObits.GP2 = 1;
    while (1) {
        __delay_ms(200);
        GPIObits.GP2 = GPIObits.GP3 ? 1 : 0;
    }
    return;
}
