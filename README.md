# RTOS-Based Air Quality Monitoring System

## Overview
This project is a FreeRTOS-based embedded system that simulates an air quality monitoring device. It demonstrates multi-tasking, inter-task communication, and modular embedded software design.

---

## Features
- Multi-task architecture using FreeRTOS
- Sensor data simulation
- Real-time data processing
- Alert generation system
- Logging mechanism
- Queue-based inter-task communication

---

## System Architecture

Sensor Task → Processing Task → Alert Task  
                              ↓  
                           Logger Task  

---

## Task Description

### 1. Sensor Task
- Simulates air quality data
- Sends data using queue

### 2. Processing Task
- Receives sensor data
- Classifies air quality:
  - GOOD
  - MODERATE
  - BAD

### 3. Alert Task
- Displays system status
- Simulates LED/Buzzer behavior

### 4. Logger Task
- Logs system status for monitoring

---

## Technologies Used
- C Programming
- FreeRTOS
- ESP-IDF Framework

---

## Key Concepts
- Task Scheduling
- Queue Communication
- Modular Design
- Real-Time Data Handling

---

## Future Improvements
- Integration with real sensors (MQ135)
- MQTT/Cloud integration
- Web dashboard for visualization

---

## Author
Sumit Bounthiyal
