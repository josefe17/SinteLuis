/* 
 * File:   main.h
 * Author: josefe
 *
 * Created on 21 de abril de 2016, 21:31
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

// PIC18F2550 Configuration Bit Settings

// 'C' source line config statements

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1L
#pragma config PLLDIV = 2       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2 // System Clock Postscaler Selection bits ([Primary Oscillator Src: /2][96 MHz PLL Src: /3])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = INTOSC_EC       // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT disabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

 // CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

#define _XTAL_FREQ 8000000

#define OUTPUT_OFF_FREQ_INDEX 9
#define OUTPUT_OFF_VALUE 128
#define OFF_VALUE        8

#define T2_TRESHOLD 244 //DEFAULT 122

#define MIDI_OFFSET 60
#define MAX_KEYS    16
#define MAX_NOTES 17
#define WAVEFORM_ROM_SIZE 16

#define MIDI_MODE    1
#define KEY_MODE     2
#define SONG_MODE    3

#define START   0
#define PLAY    1
#define SILENCE 2
#define END     3

#define DAC LATD
#define SONG PORTCbits.RC0
#define SOURCE PORTCbits.RC1
#define WAVE PORTCbits.RC2
#define PORTD_MODE_MASK 0b00001100
#define PORTD_SONG_MASK 0b00001000
#define PORTD_SONG_SELECTION_MASK 0b00000100
#define PORTD_LOWER_MASK 0x0F
#define PORTD_DATA_MASK 0xF0

#define KEY1 PORTBbits.RB0
#define KEY2 PORTBbits.RB1
#define KEY3 PORTBbits.RB2
#define KEY4 PORTBbits.RB3
#define KEY5 PORTBbits.RB4
#define KEY6 PORTBbits.RB5
#define KEY7 PORTBbits.RB6
#define KEY8 PORTBbits.RB7
#define KEY9 PORTAbits.RA0
#define KEY10 PORTAbits.RA1
#define KEY11 PORTAbits.RA2
#define KEY12 PORTAbits.RA3
#define KEY13 PORTAbits.RA4
#define KEY14 PORTAbits.RA5
#define KEY15 PORTEbits.RE0
#define KEY16 PORTEbits.RE1

#define DO 0
#define DO_UP 1
#define RE 2
#define RE_UP 3
#define MI 4
#define FA 5
#define FA_UP 6
#define SOL 7
#define SOL_UP 8
#define LA 9
#define LA_UP 10
#define SI 11
#define DO2 12
#define DO2_UP 13
#define RE2 14
#define RE2_UP 15
#define MI2 16


/*Constants*/
//Musical sequence
//Cumpleanos feliz
const int cumpleanos_feliz[] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 60, 60, 60, 60, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 60, 60, 60, 60, 128, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 60, 60, 60, 60, 128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 128, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 128, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 255 };

//Feliz en tu dia
const int feliz_en_tu_dia[] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 
128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 
128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 
128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 
128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 
128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 
128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 
128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 
128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 
128, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 
128, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 
128, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 
128, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 
128, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 
128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 
128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 255 };
//Navidad
//const unsigned char notes_values[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 60, 60, 60, 60, 60, 60, 60, 60, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 60, 60, 60, 60, 60, 60, 60, 60, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 128, 62, 62, 62, 62, 62, 62, 62, 62, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 128, 64, 64, 64, 64, 64, 64, 64, 64, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 128, 60, 60, 60, 60, 60, 60, 60, 60, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 128, 60, 60, 60, 60, 60, 60, 60, 60, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 128, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 128, 62, 62, 62, 62, 62, 62, 62, 62, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 69, 69, 69, 69, 69, 69, 69, 69, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 74, 74, 74, 74, 74, 74, 74, 74, 128, 72, 72, 72, 72, 72, 72, 72, 72, 128, 70, 70, 70, 70, 70, 70, 70, 70, 128, 67, 67, 67, 67, 67, 67, 67, 67, 128, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 128, 255 };

//freq to period ROM
//Man tuned
const unsigned char notes_periodsH[]={ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
const unsigned char notes_periodsL[]={ 163, 136, 110, 86, 64, 42, 22, 63, 45, 224, 12, 253, 239, 225, 213, 201, 190 };

//const unsigned char notes_periodsH[]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//const unsigned char notes_periodsL[]={239,225,213,201,189,179,169,159,150,142,134,126,119,112,106};

//Old
//const unsigned char notes_periodsH[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
//const unsigned char notes_periodsL[] = {222, 195, 170, 146, 123, 102, 82, 63, 45, 28, 12, 253, 239, 225, 213, 201, 190};

//ROM DAC
/*
const unsigned char sin[]={128,176,208,240,240,240,208,176,128,64,32,0,0,0,32,64};
const unsigned char square[]={240,240,240,240,240,240,240,240,0,0,0,0,0,0,0,0};
const unsigned char output_off[]={128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128};
*/
const unsigned char sin[]={8,11,13,15,15,15,13,11,8,4,2,0,0,0,2,4};
const unsigned char square[]={15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0};
const unsigned char output_off[]={8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

