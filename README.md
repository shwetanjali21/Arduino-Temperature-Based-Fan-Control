
🌡 Arduino Temperature-Based Fan Control

This project demonstrates how to control a fan (simulated with an LED) using an Arduino Uno and a temperature sensor.

Below 25°C → Fan OFF

25°C to 30°C → Fan runs at 50% speed (PWM)

Above 30°C → Fan runs at 100% speed


The live temperature and fan state are printed to the Serial Monitor.


🛠 Components (Virtual in Wokwi)

Arduino Uno

Temperature input: LM35 (or Potentiometer to simulate NTC)

LED + 220Ω resistor (Fan simulation on pin D9)

Serial Monitor (built-in)


📂 How to Use

1. Open this code in Wokwi Arduino Simulator.


2. Connect components as described:

LM35 OUT → A0, VCC → 5V, GND → GND

LED + resistor → Pin D9 → GND



3. Paste the code into sketch.ino.


4. Run the simulation → open Serial Monitor to see live updates.


5. Change the temperature sensor value to test different fan states.


📷 Demo

<25°C: LED OFF (Fan OFF)

25–30°C: LED dim (Fan 50%)

>30°C: LED bright (Fan 100%)

🔗 Wokwi Link

https://wokwi.com/projects/441702050315008001
