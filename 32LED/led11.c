#include <18F6722.h>
#fuses HS,MCLR
#use delay(clock=40MHz)

#define EXP_OUT_ENABLE        PIN_B3   // MBI_LE0
#define EXP_OUT_CLOCK         PIN_D6   // MBI_SCK
#define EXP_OUT_DO            PIN_D4   // MBI_SDI

#define G_ALL                 PIN_C5   // MBI_OE

#define NUMBER_OF_74595       4
#include <74595.c>

unsigned int8 varCode[4];

void main() 
{
    int i;
    int8 x0=0x00, x1=0x00, x2=0x00, x3=0x00;
    output_low(G_ALL);   

    while(TRUE)
    {
      x0=0x00, x1=0x00, x2=0x00, x3=0x00;
      x1=0x80;
      varCode[1] = x1;
      write_expanded_outputs(varCode);
      delay_ms(200);
      x1=0x40;
      varCode[1] = x1;
      write_expanded_outputs(varCode);
      delay_ms(200);
      x1=0xC0;
      varCode[1] = x1;
      write_expanded_outputs(varCode);
      delay_ms(200);
        }
}
