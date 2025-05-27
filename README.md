# Proyecto de Control PID Discreto y Péndulo Invertido

Este repositorio contiene el desarrollo de las prácticas de Teoría de Control, incluyendo el diseño y simulación de un controlador PID discreto, el diseño del sistema del péndulo invertido, el circuito de control, y su implementación embebida.

---

## 📂 Estructura del repositorio

- `Practica 4/` → Implementación en C++ de tres versiones del controlador PID discreto.
- `Diseño_plataforma_pendulo_invertido/` → Archivos FreeCAD, STL y G-code de la base para el péndulo.
- `PCB_pendulo_invertido/` → Diseño esquemático, footprint y vista 3D de la placa.
- `Librerias_MPU6050_I2Cdev/` → Librerías necesarias para el uso del sensor MPU6050 en el ESP32.

---

## 📚 Bibliografía

- [Microcontrolador ESP32-devKitC V4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html)
- [Giroscopio MPU6050](https://naylampmechatronics.com/blog/45_tutorial-mpu6050-acelerometro-y-giroscopio.html)
- [Driver TB6612FNG](https://www.luisllamas.es/arduino-motor-dc-tb6612fng)
- [Regulador AMS117 5V](https://datasheet.octopart.com/AMS1117-5.0-ams-datasheet-34441097.pdf)
- [Condensador para el regulador (220uF 16V)](https://c1555f5ec9.clvaw-cdnwnd.com/34662fcf1f1e607c561442431023ac8e/200000360-636e0646b8/Cap%20Electrolitic%2010-100V%20-%200.1%20to%2022000uF%20Datasheet.pdf)

---

## 🖼 Diseño PCB

### 📌 PCB schematics
![imagen_2024-03-20_131127213](https://github.com/IkerFil/Teoria_De_Control/assets/82641121/1e610847-991d-4ee5-8fc6-26bed47ecda8)

### 📌 PCB footprint
![pcb_provisional](https://github.com/IkerFil/Teoria_De_Control/assets/82641121/261078ec-f9dc-4b4b-9d7b-f3200a636677)

### 📌 PCB 3D
![pcb_provisional_3D](https://github.com/IkerFil/Teoria_De_Control/assets/82641121/05128f6e-859e-41d9-b537-355987deeea8)
