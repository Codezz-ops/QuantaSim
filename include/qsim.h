#ifndef QSIM_H
#define QSIM_H

/* Define constants */
#define GRAVITY -9.81f  /* m/s^2 */
#define DELTA_T 0.01f   /* seconds */
#define BOUNCE_DAMPING 0.8f /* Damping factor for bounce collisions */
#define WALL_ELASTICITY 0.5f /* Elasticity of walls */
#define WALL_HEIGHT 10
#define WALL_WIDTH 10


/* Define the particle struct */
typedef struct particle {
    float x;
    float y;
    float vx;
    float vy;
} particle_t;

/* Define the force struct */
typedef struct force {
    float fx;
    float fy;
} force_t;

/* Define the wall struct */
typedef struct wall {
    float x1;
    float y1;
    float x2;
    float y2;
} wall_t;

/* Function to create a new particle */
particle_t* particle_create(float x, float y, float vx, float vy);

/* Function to apply a force to a particle */
void particle_apply_force(particle_t* p, force_t* f);

/* Function to update a particle's position and velocity */
void particle_update(particle_t* p, float dt);

/* Function to destroy a particle */
void particle_destroy(particle_t* p);

/* Function to create a new gravitational force */
force_t* force_create_gravity(float g);

/* Function to create a new friction force */
force_t* force_create_friction(float friction_coefficient);

/* Function to destroy a force */
void force_destroy(force_t* f);

/* Function to create a new wall */
wall_t* wall_create(float x1, float y1, float x2, float y2);

/* Function to destroy a wall */
void wall_destroy(wall_t* w);

/* Function to check for a collision between a particle and a wall */
int particle_wall_collision(particle_t* p, wall_t* w);

/* Function to resolve a collision between a particle and a wall */
void particle_wall_collision_resolve(particle_t* p, wall_t* w);

#endif /* QSIM_H */
