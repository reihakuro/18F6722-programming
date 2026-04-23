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
   output_low(G_ALL);
   
   while(TRUE)
   {
     varCode0[1]=0b00000000;
     varCode0[0]=0b00000000;
     for(i=0;i<1000;i++)
      {  
         //led7doan
         if(i<100) varCode[2] = 0x00;
         else varCode[2] = array[(i/100)];
         if(i<10) varCode[1] = 0x00;
         else varCode[1] = array[(i/10)%10];
         varCode[0] = array[i%10];
         //buzzer
         varCode0[1] = 0x00;
         //
         varCode1[0] = i; //4 led don dau
         varCode1[1] = i >> 8; // 4 led don sau
         write_expanded_outputs_7(varCode); //led7doan
         write_expanded_outputs_B(varCode0); //ngat buzzer
         write_expanded_outputs_32(varCode1); //8 led don
         delay_ms(200);
     }
      
   }
}
