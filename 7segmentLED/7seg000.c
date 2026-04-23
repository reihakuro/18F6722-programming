#include <18F6722.h>
#fuses HS,MCLR
#use delay(clock=40MHz)
//pin def
#define EXP_OUT_ENABLE_B         PIN_F4   
#define EXP_OUT_CLOCK            PIN_D6   //MBI_SCK
#define EXP_OUT_DO               PIN_D4   //MBI_SDI
#define G_ALL                    PIN_C5   //MBI_OE
#define EXP_OUT_ENABLE_32LED     PIN_B3 
#define EXP_OUT_ENABLE_7         PIN_F6 
//74595def
#define NUMBER_OF_74595_B 2
#define NUMBER_OF_74595_LED32 4
#define NUMBER_OF_74595_7 8
//lib
#include <74595_B.c>
#include <74595_32LED.c>
#include <74595_7.c>
//variable
int8 array[3]={0x01,0x40,0x08};
unsigned int8 varCode[8];
unsigned int8 varCode0[2];

void main() 
{   
   output_low(G_ALL);
   output_low(EXP_OUT_ENABLE_32LED);
   output_low(EXP_OUT_ENABLE_B);
   int i0=0,i1=1,i2=2;
   int a=50;
      varCode[7]=array[i0];
      varCode[6]=array[i1];
      varCode[5]=array[i2];
      varCode[4]=array[i1];
      varCode[3]=array[i0];
      varCode[2]=array[i1];
      varCode[1]=array[i2];
      varCode[0]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
   while(TRUE)
   {  
      int i0=0,i1=1,i2=2;
      varCode[7]=array[i0];
      varCode[6]=array[i1];
      varCode[5]=array[i2];
      varCode[4]=array[i1];
      varCode[3]=array[i0];
      varCode[2]=array[i1];
      varCode[1]=array[i2];
      varCode[0]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[0]=array[i0];
      varCode[7]=array[i1];
      varCode[6]=array[i2];
      varCode[5]=array[i1];
      varCode[4]=array[i0];
      varCode[3]=array[i1];
      varCode[2]=array[i2];
      varCode[1]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[1]=array[i0];
      varCode[0]=array[i1];
      varCode[7]=array[i2];
      varCode[6]=array[i1];
      varCode[5]=array[i0];
      varCode[4]=array[i1];
      varCode[3]=array[i2];
      varCode[2]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[1]=array[i0];
      varCode[0]=array[i1];
      varCode[7]=array[i2];
      varCode[6]=array[i1];
      varCode[5]=array[i0];
      varCode[4]=array[i1];
      varCode[3]=array[i2];
      varCode[2]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[2]=array[i0];
      varCode[1]=array[i1];
      varCode[0]=array[i2];
      varCode[7]=array[i1];
      varCode[6]=array[i0];
      varCode[5]=array[i1];
      varCode[4]=array[i2];
      varCode[3]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[3]=array[i0];
      varCode[2]=array[i1];
      varCode[1]=array[i2];
      varCode[0]=array[i1];
      varCode[7]=array[i0];
      varCode[6]=array[i1];
      varCode[5]=array[i2];
      varCode[4]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[4]=array[i0];
      varCode[3]=array[i1];
      varCode[2]=array[i2];
      varCode[1]=array[i1];
      varCode[0]=array[i0];
      varCode[7]=array[i1];
      varCode[6]=array[i2];
      varCode[5]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[5]=array[i0];
      varCode[4]=array[i1];
      varCode[3]=array[i2];
      varCode[2]=array[i1];
      varCode[1]=array[i0];
      varCode[0]=array[i1];
      varCode[7]=array[i2];
      varCode[6]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
      varCode[6]=array[i0];
      varCode[5]=array[i1];
      varCode[4]=array[i2];
      varCode[3]=array[i1];
      varCode[2]=array[i0];
      varCode[1]=array[i1];
      varCode[0]=array[i2];
      varCode[7]=array[i1];
      write_expanded_outputs_7(varCode);
      delay_ms(a);
   }
}


   
