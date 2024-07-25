#include "RTClib.h"


RTC_DS3231 rtc;             // define Rtc

char daysOfWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};                          // define days

void setup_rtc(){
    if(!rtc.begin()){
    Serial.println("Connecting to RTC");
    while (1);
  } Serial.println("RTC connected!");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}