// Arduino DS3232RTC Library
// https://github.com/JChristensen/DS3232RTC
//
// Example sketch illustrating Time library with Real Time Clock.
// This example is identical to the example provided with the Time Library,
// only the #include statement has been changed to include the DS3232RTC library.

#include <DS3232RTC.h>      // https://github.com/JChristensen/DS3232RTC
int rly=4;

void setup()
{
  Serial.begin(9600);

  setTime(13, 13, 00, 29, 07, 2018);   //set the system time to 23h31m30s on 13Feb2009
  RTC.set(now());
  
  if (timeStatus() != timeSet)
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");

   pinMode(rly,OUTPUT);
}

void loop()
{
  digitalClockDisplay();
  delay(1000);

  if(second()>10&&second()<20){
    digitalWrite(rly,HIGH);
  }
  else{digitalWrite(rly,LOW);}
  }


void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  Serial.print(':');
  Serial.print(minute());
  Serial.print(':');
  Serial.print(second());
  Serial.print(' ');
  Serial.print(day());
  Serial.print(' ');
  Serial.print(month());
  Serial.print(' ');
  Serial.print(year());
  Serial.println();
}

/*void printDigits(int digits)
{
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(':');
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}*/
