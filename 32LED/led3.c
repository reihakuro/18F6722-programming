#include <18F6722.h>
#fuses HS,MCLR
#use delay(clock=40MHz)

#define EXP_OUT_ENABLE_32LED        PIN_B3   // MBI_LE0
#define EXP_OUT_CLOCK         PIN_D6   // MBI_SCK
#define EXP_OUT_DO            PIN_D4   // MBI_SDI

#define G_ALL                 PIN_C5   // MBI_OE

#define NUMBER_OF_74595_LED32       4
#include <74595_32LED.c>

unsigned int8 varCode[4];

void main() 
{
    int i;
    int8 x0=0,x1=0;
    output_low(G_ALL);   

    while(TRUE)
    {
      int8 x0 = 0, x1 = 0, x2 = 0, x3 = 0;
        for(i=0; i<8; i++)
        {
            x0 = (x0 << 1) + 0x01 ; x1 = (x1 >> 1) + 0x80 ;
            x3 = (x3 >> 1) + 0x80 ; x2 = (x2 << 1) + 0x01;
            varCode[0] = x0;
            varCode[3] = x3;
            varCode[2] = x2;
            varCode[1] = x1;
            write_expanded_outputs_32(varCode);
            delay_ms(50);
        }
        x0 = 0, x1 = 0, x2 = 0, x3 = 0;
        for(i=0; i<8; i++)
        {
            x0 = (x0 >> 1) + 0x80 ; x1 = (x1 << 1) + 0x01 ;
            x3 = (x3 << 1) + 0x01 ; x2 = (x2 >> 1) + 0x80;
            varCode[0] = x0;
            varCode[3] = x3;
            varCode[2] = x2;
            varCode[1] = x1;
            write_expanded_outputs_32(varCode);
            delay_ms(50);
        }
        
    }
}

