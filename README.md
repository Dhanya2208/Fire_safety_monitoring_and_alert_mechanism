🌲 Forest Fire Detection System using ESP32, IoT & Blynk
📌 Project Overview

Forest fires cause severe environmental damage and loss of wildlife. Early detection is crucial to prevent large-scale destruction.
This project presents an IoT-based Forest Fire Detection System using ESP32, temperature and gas sensors, GPS location tracking, and Blynk IoT platform for real-time monitoring and alerts.

The system continuously monitors environmental conditions and sends alerts with exact fire location when abnormal temperature and gas levels are detected.

🎯 Objectives

Detect forest fire conditions in real-time

Monitor temperature and gas levels remotely

Provide GPS location of the detected fire

Send alerts using Blynk IoT platform

Visualize sensor data on a mobile dashboard

🧰 Hardware Components

ESP32 Dev Module

DHT22 Temperature & Humidity Sensor

MQ-2 Gas Sensor

LED (Fire Alert Indicator)

GPS Module (Simulated in Wokwi / Real GPS in hardware)

Jumper wires

Power supply (USB)

🧪 Software & Platforms Used

Arduino IDE

Blynk IoT Platform

Wokwi Simulator

ESP32 WiFi Library

DHT Sensor Library

Blynk Library

🔌 System Architecture

Sensors collect environmental data (temperature & gas)

ESP32 processes the data

Fire condition is detected based on threshold values

GPS coordinates are captured

Data is sent to Blynk cloud

User receives real-time alerts and location on the mobile app

📲 Blynk Dashboard Configuration
Virtual Pin Mapping
Parameter	Widget Type	Virtual Pin
Temperature	Value Display	V0
Humidity	Value Display	V1
Gas Level	Value Display	V2
Fire Alert	LED Widget	V3
GPS Location	Map Widget	V4
🔥 Fire Detection Logic

A fire is detected when:

Temperature > 45°C

Gas Value > 400

When these conditions are met:

LED turns ON

Fire alert is sent to Blynk

GPS location is displayed on the map

🧩 Circuit Connections (ESP32)
Component	ESP32 Pin
DHT22 Data	GPIO 15
MQ-2 AOUT	GPIO 34
LED	GPIO 13
GPS RX	GPIO 16
GPS TX	GPIO 17
VCC	3.3V
GND	GND
🧑‍💻 How to Run the Project
Step 1: Blynk Setup

Create a Template in Blynk Cloud

Select ESP32 + WiFi

Create required Datastreams

Add a device and copy Auth Token

Step 2: Arduino Setup

Install ESP32 Board Package

Install required libraries:

Blynk

DHT Sensor Library

Paste the project code

Add:

#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Forest Fire"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

Step 3: Wokwi Simulation

Upload diagram.json

Run the simulation

Change sensor values to test fire detection

📍 GPS Feature

GPS location of fire is sent to Blynk

Displayed live on Map Widget

Helps authorities locate the fire quickly

📈 Advantages

Real-time monitoring

Remote access via mobile

Low cost and scalable

Accurate fire location tracking
