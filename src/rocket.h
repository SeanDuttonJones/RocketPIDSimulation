#ifndef ROCKET_H
#define ROCKET_H

typedef struct {
    float thrust;
    float max_thrust;
    float mass;
    float gravity;
    float s;
    float v;
    float a;
} rocket_t;

rocket_t rocket_init(float thrust, float max_thrust, float mass, float gravity);

void rocket_update(rocket_t* rocket);

void rocket_set_thrust(rocket_t* rocket, float thrust);

void rocket_set_mass(rocket_t* rocket, float mass);

void rocket_set_gravity(rocket_t* rocket, float gravity);

float rocket_get_position(rocket_t* rocket);

float rocket_get_velocity(rocket_t* rocket);

float rocket_get_acceleration(rocket_t* rocket);

#endif