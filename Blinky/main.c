#include <lpc17xx.h>   

#define LCD_DATA_DIR	   LPC_GPIO1->FIODIR
#define LCD_DATA_SET	   LPC_GPIO1->FIOSET
#define LCD_DATA_CLR	   LPC_GPIO1->FIOCLR
#define LCD_DATA_PIN		 LPC_GPIO1->FIOPIN

#define PIN_D0 24
#define PIN_D1 25
#define PIN_D2 26
#define PIN_D3 27
#define PIN_D4 28
#define PIN_D5 29
#define PIN_D6 30
#define PIN_D7 31

void delay_ms(unsigned int ms)
{
   unsigned int i,j;

   for(i=0;i<ms;i++)
     for(j=0;j<20000;j++);
}

int main() 
{
	int i;
	SystemInit();                    
	LCD_DATA_DIR = (0xFF << PIN_D0);
	i = PIN_D0;
	while(1)
    {
		LCD_DATA_SET = (0x01 << i);
			delay_ms(250);
		LCD_DATA_CLR = (0x01 << i);
		i++;
			if(i > PIN_D7)
				i = PIN_D0;
		}
}