# Acoustic Intent Detector

A real-time sound intent detection system built on the ESP32 using ESP-IDF in VSC.

This project focuses on detecting intentional acoustic events from noisy microphone input using lightweight signal processing techniques instead of heavy DSP or machine learning frameworks.

-FreeRTOS
-ESP32
-ESP IDF

## Current Features

- Real-time microphone sampling using ESP32 ADC
- Baseline (DC offset) tracking
- Noise deviation extraction
- Smoothed signal energy estimation
- Threshold-based intent detection
- Rising-edge event triggering
- Modular embedded architecture

## Signal Processing Pipeline

Microphone Input  
→ ADC Sampling  
→ Baseline Tracking  
→ Deviation Extraction  
→ Energy Smoothing  
→ Threshold Detection  
→ Rising Edge Trigger  

## Structure

```text
main/
├── main.c
├── mic.c
├── mic.h
├── intent.c
└── intent.h
