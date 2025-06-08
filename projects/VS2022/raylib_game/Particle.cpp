#include "Particle.h"

void Particle::Update(Vector2 force)
{
    Velocity.x += force.x * 0.1f;
    Velocity.y += force.y * 0.1f;

    Position.x += Velocity.x;
    Position.y += Velocity.y;

    Velocity.x *= 0.97f;
    Velocity.y *= 0.97f;
}