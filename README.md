# Nordic Multi-sensor Network

## Overview

Nordic Multi-sensor Network is an embedded IoT project based on Nordic Semiconductor development boards and the nRF Connect SDK.

The goal of this project is to build a multi-sensor monitoring system capable of collecting environmental data from multiple sensors and processing them in real time.

Currently, the first version of the project supports:

- MQ5 gas sensor reading
- Light sensor (photoresistor/LDR) reading
- ADC data acquisition using Nordic nRF boards
- Serial output for real-time monitoring

This project is developed using:

- nRF Connect SDK (Zephyr RTOS)
- C programming language
- Visual Studio Code
- Nordic Semiconductor development tools

Future versions may include:

- Wireless communication
- MQTT integration
- BLE connectivity
- Cloud monitoring
- Multi-node sensor networking

---

## Requirements

### Hardware

- Nordic nRF development board
- MQ5 gas sensor
- LDR / photoresistor light sensor
- Jumper wires
- USB cable

### Software

- Ubuntu Linux
- Visual Studio Code
- nRF Connect SDK
- West tool
- CMake
- Ninja build system

---

## Building and Running

### 1. Clone the repository

```bash
git clone https://github.com/Kullllll/Nordic-Multi-sensor-Network.git
cd Nordic-Multi-sensor-Network
```

### 2. Build the project

```bash
west build -b <your_board>
```

Example:

```bash
west build -b nrf52840dk/nrf52840
```

### 3. Flash the firmware

```bash
west flash
```

### 4. Monitor serial output

You can monitor sensor data using a serial terminal such as:

- minicom
- screen
- PuTTY
- Serial Monitor in VS Code

Example:

```bash
screen /dev/ttyACM0 115200
```

---

## Current Features

- MQ5 gas sensor ADC reading
- Light sensor ADC reading
- Real-time serial monitoring

---

## Project Status

This project is currently in the early development stage.

More sensors and wireless communication features will be added in future updates.