#include "simulation.h"

simulation_t simulation_init(rocket_t* rocket, pid_t* pid, float setpoint, int time_limit) {
    simulation_t simulation;
    simulation.rocket = rocket;
    simulation.pid = pid;
    simulation.setpoint = setpoint;
    simulation.time_limit = time_limit;

    return simulation;
}

void simulate(simulation_t* simulation, float* output) {
    for(int i = 0; i < simulation->time_limit; i++) {
        output[i] = rocket_get_position(simulation->rocket);

        float thrust = pid_cycle(simulation->pid, simulation->setpoint, rocket_get_position(simulation->rocket));
        rocket_set_thrust(simulation->rocket, thrust);
        rocket_update(simulation->rocket);
    }
}