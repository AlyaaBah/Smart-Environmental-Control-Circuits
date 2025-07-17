# Smart-Environmental-Control-Circuits
Arduino-based smart circuits for environmental control using analog and digital sensors.

# Smart Light-Responsive Power Saver Circuit

## Overview
This project presents a light-responsive power-saving system designed using Arduino and basic electronic components. 
- Arduino Uno
- LDR (Light Dependent Resistor)
- 10kΩ resistor (for voltage divider with LDR)
- Two 220Ω resistors (for LED current limiting)
- Push button (initially used for manual control, later removed)
- Two LEDs (system status and sensor activity)
- Breadboard and jumper wires

## Circuit Connections

### LDR Sensor:
- One terminal connected to 5V
- Second terminal connected to a 10kΩ resistor and to analog pin A0
- The other end of the 10kΩ resistor connected to GND

### System Status LED:
- Anode connected to digital pin 9 via 220Ω resistor
- Cathode connected to GND

### Sensor Activity LED:
- Anode connected to digital pin 10 via 220Ω resistor
- Cathode connected to GND

## System Behavior
- The system starts in an active state (system LED ON).
- When ambient light is low, the sensor LED turns ON, indicating sensor activity.
- When ambient light increases beyond a defined threshold, the sensor LED turns OFF and a 5-second countdown begins.
- If light remains high for 5 seconds, the system LED turns OFF to conserve battery.
- If light drops again, the system reactivates immediately.

## Challenges Faced

### 1. Arduino Overload ("Explosion" in TinkerCAD)
**Issue:** The Arduino simulated a short circuit when the button was miswired between 5V and GND.  
**Solution:** Rewired the button correctly between a digital pin and GND using `INPUT_PULLUP`.

### 2. LED Not Responding to LDR
**Issue:** The LED did not react to changes in light.  
**Solution:** Adjusted the threshold value and verified the voltage divider configuration for the LDR.

### 3. Conflicting LED Behavior
**Issue:** Both LEDs were responding to the button, which was not intended.  
**Solution:** Separated logic for system control and sensor response, assigning each LED a distinct role.

## Future Improvements
- Add buzzer for audible alerts when the system shuts down.
- Integrate an LCD to display system status and sensor readings.
- Replace LDR with a calibrated digital light sensor for higher accuracy.

# Smart Room Ventilation System

## Overview
This project implements a smart room ventilation system using Arduino, combining both analog and digital sensors to respond to environmental conditions.
The system activates a fan (represented by an LED) only when motion is detected in the room and the ambient temperature exceeds a defined threshold.
This approach ensures energy-efficient operation by responding only when necessary.

## Components Used
- Arduino Uno
- TMP36 temperature sensor (analog)
- PIR motion sensor (digital)
- LED (as fan indicator)
- 220Ω resistor (for LED current limiting)
- Breadboard and jumper wires

## Circuit Connections

### Temperature Sensor (TMP36):
- VCC → 5V  
- GND → GND  
- OUT → A0

### PIR Motion Sensor:
- VCC → 5V  
- GND → GND  
- OUT → Digital pin 2

### Fan Indicator (LED):
- Anode → Digital pin 9 via 220Ω resistor  
- Cathode → GND

## System Behavior
The system activates a fan (represented by an LED) only when motion is detected in the room and the ambient temperature exceeds a defined threshold.

- The system continuously reads ambient temperature and motion status.
- If motion is detected and the temperature exceeds a predefined threshold (e.g., 30°C), the fan indicator turns ON.
- If either condition is not met, the fan remains OFF.
- Sensor readings are printed to the Serial Monitor for real-time observation.

## Challenges Faced

### 1. Temperature Calibration
**Issue:** Initial readings were lower than expected.  
**Solution:** Verified TMP36 formula and adjusted threshold to match realistic room conditions.

### 2. Motion Detection Stability
**Issue:** PIR sensor occasionally fluctuated between states.  
**Solution:** Added short delay and monitored consistent readings to confirm detection accuracy.

### 3. Serial Display Encoding
**Issue:** Special characters (°C) appeared incorrectly in Serial Monitor.  
**Solution:** Replaced with plain text ("C") to ensure compatibility.

## Future Improvements
- Replace LED with actual fan using transistor or relay.
- Add LCD display to show temperature and motion status.
- Integrate humidity sensor for more comprehensive environmental control.


This repository showcases two Arduino-based environmental control circuits: one for light-responsive power saving, and another for motion and temperature-triggered ventilation.

⭐ Created by Alyaa


