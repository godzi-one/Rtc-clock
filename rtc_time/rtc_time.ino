#include <LiquidCrystal.h>

#include <Wire.h>

#include "RTClib.h"



RTC_DS3231 rtc;



char daysOfTheWeek[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};



int Day;

int Month;

int Year;

int Secs;

int Minutes;

int Hours;

int Millisecs;



String dofweek; 

String NAME;

String myDate;

String myTime;



#define rs 9

#define en 8

#define d4 7

#define d5 6  

#define d6 5

#define d7 4



LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup()

{

    Serial.begin(9600);

    lcd.begin(16, 4);

    delay(3000); 



    if (!rtc.begin()) {

        Serial.println("Couldn't find RTC");

        while (1);

    }



    if (rtc.lostPower()) {

        Serial.println("RTC lost power");

          rtc.adjust(DateTime()); 

    }

}



void loop()

{

    DateTime now = rtc.now();

    lcd.clear();



    NAME = "     hello     ";

    Day = now.day();

    Month = now.month();

    Year = now.year();

    Secs = now.second();

    Hours = now.hour();

    Minutes = now.minute();

    Millisecs = millis() % 1000; 



    dofweek = daysOfTheWeek[now.dayOfTheWeek()];

    

    myDate = String(Day) + "/" + String(Month) + "/" + String(Year);



    char timeBuffer[20];

    sprintf(timeBuffer, "%02d:%02d:%02d:%03d", Hours, Minutes, Secs, Millisecs);

    myTime = String(timeBuffer);



    Serial.println(NAME);

    Serial.println(myDate);

    Serial.println(myTime);



    // Print on LCD

    lcd.setCursor(0, 0);

    lcd.print(NAME);

    

    lcd.setCursor(5, 1);

    lcd.print(dofweek);

    

    lcd.setCursor(9, 2);

    lcd.print(myDate);



    lcd.setCursor(7, 3); 

    lcd.print(myTime);



    delay(1000);

}
