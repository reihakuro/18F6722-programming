#include <18F6722.h>
#fuses HS,MCLR
#use delay(clock=40MHz)
#define EXP_OUT_ENABLE_B         PIN_F4   //MBI_LE0
#define EXP_OUT_CLOCK            PIN_D6   //MBI_SCK
#define EXP_OUT_DO               PIN_D4   //MBI_SDI
#define G_ALL                    PIN_C5   //MBI_OE
#define EXP_OUT_ENABLE_32LED     PIN_B3 
#define EXP_OUT_ENABLE_7         PIN_F6 
#define NUMBER_OF_74595_B 2
#define NUMBER_OF_74595_LED32 4
#define NUMBER_OF_74595_7 8
#include <74595_B.c>
#include <74595_32LED.c>
#include <74595_7.c>
int8 array[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int8 varCode[8];
unsigned int8 varCode0[2];
unsigned int8 varCode1[4];
void main() 
{   
   int8 i;
   int1 j[8];
   int k;
   output_low(G_ALL);
   
   while(TRUE)
   {
     varCode0[1]=0x00;
     varCode0[0]=0x00;
     for(i=0;i<1000;i++)
      {  k=0;
      for(k=0;k<8;k++)
      {
         j[k] = i >> k;
         varCode[k] = array[j[k]];
      }
      
        /*
         j[0] = i >> 0;
         varCode[0] = array[j[0]];
         j[1] = i >> 1;
         varCode[1] = array[j[1]];
         j[2] = i >> 2;
         varCode[2] = array[j[2]];
         j[3] = i >> 3;
         varCode[3] = array[j[3]];
         j[4] = i >> 4;
         varCode[4] = array[j[4]];
         j[5] = i >> 5;
         varCode[5] = array[j[5]];
         j[6] = i >> 6;
         varCode[6] = array[j[6]];
         j[7] = i >> 7;
         varCode[7] = array[j[7]];
*/
         varCode1[0] = i;
         varCode1[1] = i >> 8;
         
         write_expanded_outputs_7(varCode);
         write_expanded_outputs_B(varCode0);
         write_expanded_outputs_32(varCode1);
         delay_ms(400);
     }
      
   }
}
