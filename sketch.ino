// NTC Thermistor on A0
// Fan (simulated with LED) on D13

const int sensorPin = A0;
const int fanPin = 9;  // Use PWM pin instead of D13 (D13 can’t do PWM)
                       // If you still want LED on D13, we’ll mirror states.

const int ledPin = 13; 

// Thermistor constants (for 10k NTC)
const float BETA = 3950;  // beta value
const float T0 = 298.15;  // 25°C in Kelvin
const float R0 = 10000;   // 10k at 25°C
const float SERIES_RESISTOR = 10000.0; 

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

float readTemperature() {
  int adcValue = analogRead(sensorPin);
  float resistance = SERIES_RESISTOR / ((1023.0 / adcValue) - 1);
  float tempK = 1 / (1 / T0 + (1.0 / BETA) * log(resistance / R0));
  return tempK - 273.15; // Convert K to °C
}

void loop() {
  float temperature = readTemperature();
  int fanSpeed = 0;

  if (temperature < 25) {
    fanSpeed = 0; // OFF
  } else if (temperature < 30) {
    fanSpeed = 128; // ~50% speed (0-255 scale)
  } else {
    fanSpeed = 255; // 100%
  }

  // Write PWM to fan
  analogWrite(fanPin, fanSpeed);

  // Mirror state on LED (ON if fan running, OFF if not)
  digitalWrite(ledPin, fanSpeed > 0 ? HIGH : LOW);

  // Print status
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Fan Speed: ");
  if (fanSpeed == 0) Serial.println("OFF");
  else if (fanSpeed == 128) Serial.println("50%");
  else Serial.println("100%");

  delay(1000); // 1s update
}
