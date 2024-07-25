#include  <Wire.h>
#include "automation.h"
#include "ds3231.h"

void setup() {
  Serial.begin(115200);
  initializeWaterPump();
  setup_rtc();
  digitalWrite(relay_4_watering_pump,HIGH); // matikan relay 
}

void loop() {
  unsigned long currentMillis = millis();

  DateTime now = rtc.now();
  int jam = now.hour();


// Debug
  Serial.println("Jamnya : ");
  Serial.print (jam);
  Serial.println("");
  Serial.print("ESP32 RTC Date Time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
// debug -- end

  // automatic water
    if (now.hour() == 07 && now.minute() == 00 && !waterPinState){
        turn_on_water_pump();
    }

    if (now.hour() == 17 && now.minute() == 00 && !waterPinState){
        turn_on_water_pump();
    }    

    // test --
    if (now.hour() == 13 && now.minute() == 3 && !waterPinState){
        turn_on_water_pump();
    }   
    // test -- end 

  // cek time interval dari water pump 
  cek_interval_time();

  delay(1000);
}
