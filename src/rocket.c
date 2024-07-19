#include <stdio.h>
#include "rocket.h"

rocket_t rocket_init(float thrust, float max_thrust, float mass, float gravity) {
    rocket_t rocket;
    rocket.thrust = thrust;
    rocket.max_thrust = max_thrust;
    rocket.mass = mass;
    rocket.gravity = gravity;
    rocket.s = 0;
    rocket.v = 0;
    rocket.a = 0;

    return rocket;
}

void rocket_update(rocket_t* rocket) {
    rocket->a = (rocket->thrust / rocket->mass) - rocket->gravity;
    rocket->v = rocket->v + rocket->a;
    rocket->s = rocket->s + rocket->v;
}

void rocket_set_thrust(rocket_t* rocket, float thrust) {
    if(thrust > rocket->max_thrust) {
        rocket->thrust = rocket->max_thrust;
    } else {
        rocket->thrust = thrust;
    }
}

void rocket_set_mass(rocket_t* rocket, float mass) {
    rocket->mass = mass;
}

void rocket_set_gravity(rocket_t* rocket, float gravity) {
    rocket->gravity = gravity;
}

float rocket_get_position(rocket_t* rocket) {
    return rocket->s;
}

float rocket_get_velocity(rocket_t* rocket) {
    return rocket->v;
}

float rocket_get_acceleration(rocket_t* rocket) {
    return rocket->a;
}