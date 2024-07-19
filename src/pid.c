#include "pid.h"

pid_t pid_init(float Kp, float Ki, float Kd, float dt) {
    pid_t pid;
    pid.A0 = Kp + Ki * dt + Kd / dt;
    pid.A1 = -Kp - 2.0f * Kd / dt;
    pid.A2 = Kd / dt;
    pid.error[0] = 0.0f;
    pid.error[1] = 0.0f;
    pid.error[2] = 0.0f;
    pid.prev_output = 0.0f;

    return pid;
}

float pid_cycle(pid_t* pid, float setpoint, float measurement) {
    pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];
    pid->error[0] = setpoint - measurement;

    float output = pid->prev_output + pid->A0 * pid->error[0] + pid->A1 * pid->error[1] + pid->A2 * pid->error[2];
    pid->prev_output = output;

    return output;
}