#include <stdio.h>
#include "qsim.h"

int main() {
    // Create a new particle with initial position (0, 0) and velocity (1, 0)
    particle_t* p = particle_create(0, 0, 1, 0);

    // Apply a gravitational force to the particle
    force_t* gravity = force_create_gravity(9.8);

    // Simulate the particle for 10 seconds
    for (int i = 0; i < 10000; i++) {
        particle_apply_force(p, gravity);

        // Check for collision with left wall
        if (p->x <= 0) {
            p->x = 0;
            p->vx = -p->vx;
        }

        // Check for collision with right wall
        if (p->x >= WALL_WIDTH) {
            p->x = WALL_WIDTH;
            p->vx = -p->vx;
        }

        // Check for collision with top wall
        if (p->y <= 0) {
            p->y = 0;
            p->vy = -p->vy;
        }

        // Check for collision with bottom wall
        if (p->y >= WALL_HEIGHT) {
            p->y = WALL_HEIGHT;
            p->vy = -p->vy;
        }

        particle_update(p, 0.001);
    }

    // Print the final position of the particle
    printf("Final position: (%f, %f)\n", p->x, p->y);

    // Destroy the particle and force
    particle_destroy(p);
    force_destroy(gravity);

    return 0;
}
