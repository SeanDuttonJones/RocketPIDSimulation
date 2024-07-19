#ifndef SIMULATION_H
#define SIMULATION_H

#include "pid.h"
#include "rocket.h"

typedef struct {
    rocket_t* rocket;
    pid_t* pid;
    float setpoint;
    int time_limit;
} simulation_t;

simulation_t simulation_init(rocket_t* rocket, pid_t* pid, float setpoint, int time_limit);

void simulate(simulation_t* simulation, float* output);

#endif