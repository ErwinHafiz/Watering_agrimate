
// Define for water pump purpose
#define OPEN_WATER_PUMP_GATE                  LOW
#define CLOSE_WATER_PUMP_GATE                 HIGH
bool IS_WATERING_GATE_OPEN                     = DISABLED;

unsigned long StartTime                    = 0; /// waktu mulai penyiraman

// For turning on watering pump
unsigned long timeInterval_watering          = 60000;      // the time we need to wait
unsigned long previousTime_watering          = 0;           // millis() returns an unsigned long.

const int relay_4_watering_pump                      = 23;

bool waterPinState = false;                                  // state variable for the PUMP

void initializeWaterPump(){
  pinMode(relay_4_watering_pump, OUTPUT);
  digitalWrite(relay_4_watering_pump,waterPinState);
}

// void turningOnWateringPump() {
//   unsigned long currentMillis = millis();

//   if (IS_WATERING_GATE_OPEN == ENABLED && currentTime - previousTime_watering >= timeInterval_watering) {
//     digitalWrite(relay_4_watering_pump, CLOSE_WATER_PUMP_GATE);

//     IS_WATERING_GATE_OPEN = DISABLED;
//   }
//     // Watering pump
//   if (IS_WATERING_GATE_OPEN == DISABLED) {
//     digitalWrite(relay_4_watering_pump, OPEN_WATER_PUMP_GATE);

//     IS_WATERING_GATE_OPEN = ENABLED;
//     previousTime_watering = currentTime;
//   }
// }
void turn_on_water_pump(){
      unsigned long currentMillis = millis();
      Serial.println("from turn on water pump");
      digitalWrite(relay_4_watering_pump, LOW); // Menghidupkan relay water pump
      StartTime = currentMillis; //  waktu mulai
      waterPinState = true;
}

void cek_interval_time(){
  unsigned long currentMillis = millis();
  if (waterPinState && (currentMillis - StartTime >= timeInterval_watering)) {
    digitalWrite(relay_4_watering_pump, HIGH); // Matikan relay
    waterPinState = false;
  }

}