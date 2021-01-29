/*
 * Challenge.c
 *
 * Created: 4/2/2014 7:42:04 PM
 *  Author: Mohamed T6arek
 */ 

#include "lcd.h"
#include "keypad.h"

int main(void)
{
	unsigned char key , first , last  , op  ,result ,flag = 1;
	LCD_init();

    while(1)
    {
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		if(key == 13 )
		{
			LCD_clearScreen();
			result = 0 ;
			first = 0 ;
			last = 0 ;
			flag = 1;
		}
		else if ((key>=0) && (key <=9))
		{
			if (flag)
			{
			first = key ;
			LCD_intgerToString(key);
			flag = 0;
			}
			else
			{
			last = key ;
			LCD_intgerToString(key);
			}
		}
		else if (key == '=')
		{
			LCD_displayCharacter(key);
			switch (op)
			{
			case '+' : result = first + last ; break;
			case '-' : result = first - last;break;
			case '*' : result = first * last ;break;
			case '%' : result = first / last;break;
			}
			LCD_intgerToString(result);
		}
		else
		{
			op = key ;
			LCD_displayCharacter(key); /* display the pressed keypad switch */
		}

		  _delay_ms(500);
    }
}

