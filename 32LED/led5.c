#include <18F6722.h>
#fuses HS,MCLR
#use delay(clock=40MHz)
void main (){
int16 mbi_data = 0xFFFF;  
int i;

setup_spi(SPI_MASTER | SPI_L_TO_H | SPI_CLK_DIV_4);
output_low(MBI_LE);   
output_low(MBI_OE);   

mbi_data &= ~(1 << 5);

    // Ch?n microstep = Quarter step (MS1=0, MS2=1, MS3=0)
    mbi_data &= ~(1 << 0); // MS1=0
    mbi_data |=  (1 << 1); // MS2=1
    mbi_data &= ~(1 << 2); // MS3=0

    // DIR = 0 => quay thu?n
    mbi_data &= ~(1 << 4);

    // STEP m?c ð?nh = 0
    mbi_data &= ~(1 << 3);

    // ----------- G?I D? LI?U L?N Ð?U -----------
    spi_write(mbi_data >> 8);      // Byte cao
    spi_write(mbi_data & 0xFF);    // Byte th?p
    output_high(MBI_LE);
    delay_us(1);
    output_low(MBI_LE);

    // ----------- V?NG L?P CHÍNH -----------
    while(TRUE) {
        // ==== QUAY THU?N 200 BÝ?C ====
        mbi_data &= ~(1 << 4);  // DIR=0
        for(i = 0; i < 200; i++) {
            // STEP = HIGH
            mbi_data |= (1 << 3);
            spi_write(mbi_data >> 8);
            spi_write(mbi_data & 0xFF);
            output_high(MBI_LE);
            delay_us(1);
            output_low(MBI_LE);
            delay_us(2);

            // STEP = LOW
            mbi_data &= ~(1 << 3);
            spi_write(mbi_data >> 8);
            spi_write(mbi_data & 0xFF);
            output_high(MBI_LE);
            delay_us(1);
            output_low(MBI_LE);
            delay_us(2);
        }
        delay_ms(500);

