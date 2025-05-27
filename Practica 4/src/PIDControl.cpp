#include "PIDControl.h"

// ------------------------------
// Implementación de PID básico (forma discreta clásica)
// ------------------------------
PID::PID(float Kp, float Ki, float Kd, float dt)
    : Kp(Kp), Ki(Ki), Kd(Kd), dt(dt), previous_error(0), integral(0) {}

float PID::bucle_control(float setpoint, float measured_value) {
    float error = setpoint - measured_value;
    integral += error * dt;  // Integral acumulada
    float derivative = (error - previous_error) / dt;  // Derivada discreta
    float output = Kp * error + Ki * integral + Kd * derivative;  // Ley de control
    previous_error = error;
    return output;
}

// ------------------------------
// Implementación de PID como filtro IIR
// ------------------------------
PID_IIR::PID_IIR(float Kp, float Ki, float Kd, float dt)
    : A0(Kp + Ki * dt + Kd / dt), A1(-Kp - 2 * Kd / dt), A2(Kd / dt),
      error{0, 0, 0}, output(0) {}

float PID_IIR::bucle_control(float setpoint, float measured_value) {
    // Desplazar errores anteriores
    error[2] = error[1];
    error[1] = error[0];
    error[0] = setpoint - measured_value;
    // Cálculo de salida por diferencia finita (forma IIR)
    output = A0 * error[0] + A1 * error[1] + A2 * error[2];
    return output;
}

// ------------------------------
// Implementación de PID con derivada filtrada (Low Pass Filter)
// ------------------------------
PID_LowPass::PID_LowPass(float Kp, float Ki, float Kd, float dt): 
    A0(Kp + Ki * dt), A1(-Kp), A0d(Kd / dt), A1d(-2.0 * Kd / dt), A2d(Kd / dt),
    tau(Kd / (Kp * N)), alpha(dt / (2 * tau)), 
    alpha_1(alpha / (alpha + 1)), alpha_2((alpha - 1) / (alpha + 1)),
    error{0, 0, 0}, d0(0), d1(0), fd0(0), fd1(0), output(0) {}

float PID_LowPass::bucle_control(float setpoint, float measured_value) {
    // Actualizar errores
    error[2] = error[1];
    error[1] = error[0];
    error[0] = setpoint - measured_value;

    // Parte proporcional e integral (estilo PI)
    output = output + A0 * error[0] + A1 * error[1];

    // Parte derivativa con filtro pasa baja
    d1 = d0;
    d0 = A0d * error[0] + A1d * error[1] + A2d * error[2];
    fd1 = fd0;
    fd0 = alpha_1 * (d0 + d1) - alpha_2 * fd1;
    output = output + fd0;

    return output;
}

