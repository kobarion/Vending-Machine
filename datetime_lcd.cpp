#include <wiringPi.h>         
#include <lcd.h>               
#include <stdio.h>
#include <time.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  11               //Register select pin
#define LCD_E   10               //Enable Pin
#define LCD_D4  0               //Data pin 4
#define LCD_D5  5               //Data pin 5
#define LCD_D6  2               //Data pin 6
#define LCD_D7  3               //Data pin 7

int main()
{
    int lcd;
    wiringPiSetup();
    lcd = lcdInit (4, 20, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

    while(1){
        time_t timer;
        char buffer_date[26];
        char buffer_time[26];
        struct tm* tm_info;

        time(&timer);
        tm_info = localtime(&timer);

        strftime(buffer_date, 26, "Date: %m:%d:%Y", tm_info);
        strftime(buffer_time, 26, "Time: %H:%M:%S", tm_info);

        lcdPosition(lcd, 0, 0);
        lcdPuts(lcd, buffer_date);

        lcdPosition(lcd, 0, 1);
        lcdPuts(lcd, buffer_time);

	lcdPosition(lcd, 0, 2);
	lcdPuts(lcd, "--------Koba--------");

	lcdPosition(lcd, 0, 3);
	lcdPuts(lcd,"   VendingMachine   "); 

        }
}
