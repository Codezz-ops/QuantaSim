#include <stdio.h>
#include <stdlib.h>
#include "qsim.h"

/* Function to create a new particle */
particle_t* particle_create(float x, float y, float vx, float vy) {
    particle_t* p = malloc(sizeof(particle_t));
    if (p == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for particle.\n");
        exit(EXIT_FAILURE);
    }
    p->x = x;
    p->y = y;
    p->vx = vx;
    p->vy = vy;
    return p;
}

/* Function to apply a force to a particle */
void particle_apply_force(particle_t* p, force_t* f) {
    p->vx += f->fx * DELTA_T;
    p->vy += f->fy * DELTA_T;
}

/* Function to update a particle's position and velocity */
void particle_update(particle_t* p, float dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

/* Function to destroy a particle */
void particle_destroy(particle_t* p) {
    free(p);
}

/* Function to create a new gravitational force */
force_t* force_create_gravity(float g) {
    force_t* f = malloc(sizeof(force_t));
    if (f == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for force.\n");
        exit(EXIT_FAILURE);
    }
    f->fx = 0;
    f->fy = g * GRAVITY;
    return f;
}

/* Function to destroy a force */
void force_destroy(force_t* f) {
    free(f);
}
