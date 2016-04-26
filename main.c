
/*
 * File:   main.c
 * Author: Josefe
 *
 * Created on 21 de abril de 2016, 21:32
 */

#include <xc.h>
#include "main.h"

#define LED PORTCbits.RC6
#define LED_TRIS TRISCbits.TRISC6

/*Variables*/
unsigned char  rom_index;       //Waveform rom counter
unsigned char* rom_pointer;     //Waveform rom pointer
unsigned char rom_value;        //Latch for rom value
unsigned char  freq_index;  //Frequency variables for CCP


unsigned char* aux_rom_pointer; //Waveform rom pointer for selection
unsigned char mode;             //Working mode

int* note_index;                //Song rom pointer
unsigned char player_status;
unsigned char next_player_status;
unsigned char song_freq_buffer;

unsigned char last_pressed;

void osc_init(void);
void port_init(void);
void timer1_init(void);
void timer1_reset(void);
void ccp2_init(void);
void timer2_init(void);
void timer2_interrupts_start(void);
void timer2_stop(void);
void interrupts_init(void);
unsigned char* set_waveform(void);
int* set_song(void);
void update_freq(unsigned char);
unsigned char leeTecla(unsigned char);
unsigned char leeTeclado(void);


void main(void){

    osc_init();
    port_init();

    LED_TRIS=0;
    LED=0;

    /*Variables initialization*/
    rom_pointer = (unsigned char*) output_off;
    aux_rom_pointer = (unsigned char*) output_off;
    rom_value=OFF_VALUE;
    rom_index = 0;
    freq_index = OUTPUT_OFF_FREQ_INDEX;

    timer1_init();
    ccp2_init();
    interrupts_init();
    timer1_reset();

    while(1) {
        /*
        if (rom_index >= WAVEFORM_ROM_SIZE) {
            rom_index = 0; //Reset counter
            rom_pointer = aux_rom_pointer; //Load rom
            CCPR2H = notes_periodsH[freq_index]; //Load frequency
            CCPR2L = notes_periodsL[freq_index];
        }
         */

       if (!SOURCE) {//READ KEYBOARD
           if (mode!=KEY_MODE) {
               timer2_stop();
               aux_rom_pointer = (unsigned char *) output_off;
               last_pressed = OUTPUT_OFF_VALUE;
               freq_index = OUTPUT_OFF_FREQ_INDEX;
               mode=KEY_MODE;
               LED=0;////////////////////////////////////////////////////////////////////
                          
           //aux_rom_pointer=set_waveform();
           //freq_index=9; //NO AFINADA AUN 5         //Ejecuta teclado

              }
            if (last_pressed >= MAX_NOTES){
                last_pressed = leeTeclado(); //If pressed stored key is none, read keyboard
            }
            else {
                if (leeTecla(last_pressed)==0){
                    last_pressed = leeTeclado(); //Else if pressed stored key is already released, read keyboard again
                }
            }

            if (last_pressed >= MAX_NOTES) { //If no pressed key, shut off output (when zero crossing)
                //LED=0;////////////////////////////////////////////////////////////////////////
                aux_rom_pointer = (unsigned char*) output_off;
                freq_index= OUTPUT_OFF_FREQ_INDEX;

            } else { //Else play read key
                //LED=1;///////////////////////////////////////////////////////////////////
                aux_rom_pointer=set_waveform();
                freq_index = last_pressed;
             }
        
        }

        /*
       if(!SOURCE && SONG){//UART
           if (mode!=MIDI_MODE){
               mode=MIDI_MODE;
               timer2_stop();
           }
           aux_rom_pointer=set_waveform();
           freq_index=7;     //No afinada ni compilado   //Ejecuta teclado           
       }
         */
       if(SOURCE){
           if (mode!=SONG_MODE){
               timer2_init();
               mode=SONG_MODE;
               next_player_status = SILENCE;
               aux_rom_pointer = (unsigned char*) output_off;
               note_index = set_song();
               song_freq_buffer = OUTPUT_OFF_FREQ_INDEX;
               timer2_interrupts_start();
           }
           player_status=next_player_status;
           switch (player_status){
               case START:{
                    timer2_init();
                    aux_rom_pointer = (unsigned char*) output_off;
                    note_index = set_song();
                    song_freq_buffer=OUTPUT_OFF_FREQ_INDEX;
                    timer2_interrupts_start();
                   if ((*note_index)<OUTPUT_OFF_VALUE){
                       next_player_status=PLAY;
                       break;
                   }
                   if ((*note_index)==OUTPUT_OFF_VALUE) {
                       next_player_status = SILENCE;
                       break;
                    }
                   if ((*note_index)> OUTPUT_OFF_VALUE) {
                       next_player_status = START;
                       break;
                    }
                    break;
               }
               case PLAY:{
                   aux_rom_pointer=set_waveform();
                   song_freq_buffer =(*note_index)-MIDI_OFFSET;
                    if ((*note_index) < OUTPUT_OFF_VALUE) {
                        next_player_status = PLAY;
                        break;
                    }
                    if ((*note_index) == OUTPUT_OFF_VALUE) {
                        next_player_status = SILENCE;
                        break;
                    }
                    if ((*note_index) > OUTPUT_OFF_VALUE) {
                        next_player_status = START;
                        break;
                    }
                   break;
               }
               case SILENCE:{
                   aux_rom_pointer = (unsigned char*) output_off;
                   song_freq_buffer = OUTPUT_OFF_FREQ_INDEX;
                    if ((*note_index) < OUTPUT_OFF_VALUE) {
                        next_player_status = PLAY;
                        break;
                    }
                    if ((*note_index) == OUTPUT_OFF_VALUE) {
                        next_player_status = SILENCE;
                        break;
                    }
                    if ((*note_index) > OUTPUT_OFF_VALUE) {
                        next_player_status = START;
                        break;
                    }
                   break;
               }
               case END:{
                    aux_rom_pointer = (unsigned char*) output_off;
                    note_index = set_song();
                    song_freq_buffer = OUTPUT_OFF_FREQ_INDEX;
                    if ((*note_index) < OUTPUT_OFF_VALUE) {
                        next_player_status = PLAY;
                        break;
                    }
                    if ((*note_index) == OUTPUT_OFF_VALUE) {
                        next_player_status = SILENCE;
                        break;
                    }
                    if ((*note_index) > OUTPUT_OFF_VALUE) {
                        next_player_status = START;
                        break;
                    }
                    break;
               }
               

           }
           
       }

        
    }

}

void osc_init(void){
    /*Oscillator configurations*/
    OSCCONbits.IDLEN=0; // Sleeps on SLEEP
    OSCCONbits.IRCF=0b111; //8 MHz internal oscillator
    OSCCONbits.SCS=2;   //Primary oscillator source
    while(!OSCCONbits.IOFS){};
}

 void port_init(void){
    /*Port configuration*/
    TRISA=0b00111111; //port A a keyboard input
    TRISB=255; //Port B as Keyboard input
    ADCON1bits.PCFG=0b1111; //No analog inputs
    TRISE=0b00000011;
    TRISD=0;   //Half D port as DAC output
    TRISCbits.TRISC0=1;  //Port C0 as loop mode input ----
    TRISCbits.TRISC1=1;  //Port C1 as song selection input
    TRISCbits.TRISC2=1;

}

void timer1_init (void){    //Freq gen
    //T1GCON=0;           //No gate trigger
    T1CONbits.TMR1CS=0; //System clock/4
    T1CONbits.T1CKPS=0; //No prescale (1/8)
    T1CONbits.RD16=1;   //Read/write in one instruction
    T1CONbits.T1OSCEN=0; //Dedicated oscillator disabled
    T3CONbits.T3CCP2=0; //Timer1 as source of both CCP modules
    T3CONbits.T3CCP1=0;

}


void timer1_reset(void) {
    T1CONbits.TMR1ON = 0; //Stop t1
    TMR1H = 0;
    TMR1L = 0; //Reset timer
    T1CONbits.TMR1ON = 1; //Start t1
}

void ccp2_init(void) {
    /*CCP2 configuration*/
    //Attached to timer1
    CCP2CONbits.CCP2M = 0b1010; //Compare without output
    CCPR2H = notes_periodsH[OUTPUT_OFF_FREQ_INDEX];
    CCPR2L = notes_periodsL[OUTPUT_OFF_FREQ_INDEX];
}


void timer2_init(void){
    T2CONbits.TOUTPS=15;
    T2CONbits.T2CKPS=2;  //Prescaler input 1:16 
    TMR2=0;
    PR2=T2_TRESHOLD;
}

void timer2_interrupts_start(void) {
    IPR1bits.TMR2IP = 0; //Low prior interrupt
    PIE1bits.TMR2IE = 1; //Timer 2 interrupt
    PIR1bits.TMR2IF = 0;
    T2CONbits.TMR2ON = 1;
}

void timer2_stop(void) {
    PIE1bits.TMR2IE = 0; //Timer 2 interrupt
    PIR1bits.TMR2IF = 0;
    T2CONbits.TMR2ON = 0;
}

void interrupts_init(void) {
    /*Interrupts configuration*/
    PIE2bits.CCP2IE = 1; //CCP interrupt
    PIR2bits.CCP2IF = 0;
    IPR2bits.CCP2IP = 1;
    RCONbits.IPEN = 1; //priority enabled
    INTCONbits.GIEL = 1; //Low priority interrupts enabled
    INTCONbits.GIEH = 1; //High priority interrupts enabled
}

unsigned char* set_waveform(void){
    if (WAVE) return (unsigned char*) square;
    else return (unsigned char*) sin;
}

int* set_song(void){
    if (SONG) return (int*) feliz_en_tu_dia;
    else return (int*) cumpleanos_feliz;
}


unsigned char leeTeclado(void) {
     if (KEY1) return 0;
     if (KEY2) return 1;
     if (KEY3) return 2;
     if (KEY4) return 3;
     if (KEY5) return 4;
     if (KEY6) return 5;
     if (KEY7) return 6;
     if (KEY8) return 7;
     if (KEY9) return 8;
     if (KEY10) return 9;
     if (KEY11) return 10;
     if (KEY12) return 11;
     if (KEY13) return 12;
     if (KEY14) return 13;
     if (KEY15) return 14;
     if (KEY16) return 15;
     return OUTPUT_OFF_VALUE;
}



unsigned char leeTecla(unsigned char tecla) {
    switch (tecla) {
        case 0: return KEY1;
        case 1: return KEY2;
        case 2: return KEY3;
        case 3: return KEY4;
        case 4: return KEY5;
        case 5: return KEY6;
        case 6: return KEY7;
        case 7: return KEY8;
        case 8: return KEY9;
        case 9: return KEY10;
        case 10: return KEY11;
        case 11: return KEY12;
        case 12: return KEY13;
        case 13: return KEY14;
        case 14: return KEY15;
        case 15: return KEY16;
        default: return 0;

    }
}

/*
unsigned char leeTecla(unsigned char tecla) {
    switch (tecla) {
        case DO:{
            if (KEY1) return 1;
            else return 0;            
        }
        case MI:{
            if (KEY5) return 1;
            else return 0;
        }
        case 9:{
           if (KEY10) return 1;
           else return 0;
        }
        default: return 0;

    }
}
*/
void interrupt ISR(void){
    if (PIR2bits.CCP2IF){
        PIR2bits.CCP2IF=0;  //Clear flag
        /*
        if(rom_index>=WAVEFORM_ROM_SIZE){
            rom_index=0; //Reset counter
            rom_pointer=aux_rom_pointer; //Load rom
            CCPR2H=freq_h; //Load frequency
            CCPR2L=freq_l;
        }
         */
        DAC=rom_value;
        rom_value = (*rom_pointer);
        T1CONbits.TMR1ON = 0; //Stop t1
        TMR1H = 0;
        TMR1L = 0; //Reset timer       
        
        rom_index++;
        rom_pointer++;
        if (rom_index >= WAVEFORM_ROM_SIZE) {
            rom_index = 0; //Reset counter
            rom_pointer = aux_rom_pointer; //Load rom            
            CCPR2H = notes_periodsH[freq_index]; //Load frequency
            CCPR2L = notes_periodsL[freq_index];
        }
        T1CONbits.TMR1ON = 1; //Start t1
 

    }
    if(PIR1bits.TMR2IF){
        PIR1bits.TMR2IF=0;
        note_index++;
        freq_index=song_freq_buffer;
        TMR2=0;
    }


}