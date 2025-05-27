#ifndef PIDCONTROL_H
#define PIDCONTROL_H

// ------------------------------
// Declaración de clase PID directa
// ------------------------------
class PID {
public:
    PID(float Kp, float Ki, float Kd, float dt);
    float bucle_control(float setpoint, float measured_value);  // Ejecuta una iteración del PID

private:
    float Kp, Ki, Kd, dt;         // Ganancias y periodo de muestreo
    float previous_error;         // Error anterior (para derivada)
    float integral;               // Acumulador integral
};

// ------------------------------
// Declaración de clase PID como filtro IIR
// ------------------------------
class PID_IIR {
public:
    PID_IIR(float Kp, float Ki, float Kd, float dt);
    float bucle_control(float setpoint, float measured_value);  // Ejecuta control usando forma IIR

private:
    float A0, A1, A2;             // Coeficientes del filtro IIR
    float error[3];              // Historial de errores: e[k], e[k-1], e[k-2]
    float output;                // Salida actual
};

// ------------------------------
// Declaración de clase PID con derivada filtrada (Low Pass)
// ------------------------------
class PID_LowPass {
public:
    PID_LowPass(float Kp, float Ki, float Kd, float dt);
    float bucle_control(float setpoint, float measured_value);  // PID con derivada filtrada

private:
    const int N = 5;             // Factor de atenuación para filtro pasa baja (típico: 3-10)
    float A0, A1;                // Coeficientes del PI
    float A0d, A1d, A2d;         // Coeficientes de la parte derivativa discreta
    float tau;                   // Constante de tiempo del filtro derivativo
    float alpha, alpha_1, alpha_2; // Parámetros de filtro pasa baja

    float error[3];              // Historial de errores
    float d0, d1;                // Derivada sin filtrar
    float fd0, fd1;              // Derivada filtrada
    float output;                // Salida actual del controlador
};

#endif