#include <16F1827.h>
#device ADC=16
#use delay(clock=4MHz,crystal=4MHz)
#include <lcd.c>

#define LED PIN_A1
#define DELAY 1000
void main()
{
   lcd_init();

   set_tris_a(0b11111111);
   set_tris_b(0b00000000);
   while(TRUE)
   {
      if(input_state(PIN_A0))
      {
         output_high(LED); 
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor encendido");
      }
      else 
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"\fMotor apagado");
         output_low(LED);
         DELAY_MS(100);
      }
   }
}


