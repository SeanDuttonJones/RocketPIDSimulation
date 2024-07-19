#ifndef PID_H
#define PID_H

typedef struct {
    float A0;
    float A1;
    float A2;
    float error[3];
    float prev_output;
} pid_t;

pid_t pid_init(float Kp, float Ki, float Kd, float dt);

float pid_cycle(pid_t* pid, float setpoint, float measurement);

#endif