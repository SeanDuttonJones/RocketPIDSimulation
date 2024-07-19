#include <stdio.h>

#include "pid.h"
#include "rocket.h"
#include "simulation.h"

int main() {
    /* ##### GLOBALS ##### */
    int TIME_LIMIT = 500;
    float GRAVITY = 9.81;
    int SETPOINT = 20;

    /* ##### ROCKET PARAMS ##### */
    float init_thrust = 0.0f;
    float max_thrust = 20.0f;
    float mass = 1.0f;

    rocket_t rocket = rocket_init(init_thrust, max_thrust, mass, GRAVITY);

    /* ##### PID PARAMS ##### */
    float Kp = 0.39f;
    float Ki = 55.714285714285715f;
    float Kd = 0.0006825000000000001f;
    float dt = 0.001f;

    pid_t pid = pid_init(Kp, Ki, Kd, dt);

    /* ##### SIMULATION ##### */
    simulation_t sim = simulation_init(&rocket, &pid, SETPOINT, TIME_LIMIT);
    float output[TIME_LIMIT];

    simulate(&sim, output);
    
    /* ##### OUTPUT PRINT ##### */
    printf("[");
    for(int i = 0; i < TIME_LIMIT; i++) {
        printf("%f ", output[i]);
    }
    printf("]\n");
    
    return 0;
}