#include "ParticleSystem.h"
#include "raylib.h"

void ParticleSystem::Init(const int screenWidth, const int screenHeight, const int numParticles)
{
    Particles.clear();
    for (int i = 0; i < numParticles; i++)
    {
        Vector2 startPosition = {
            static_cast<float>(GetRandomValue(0, screenWidth)),
            static_cast<float>(GetRandomValue(0, screenHeight))
        };
        Vector2 startVelocity = {0.0f, 0.0f};
        Particles.push_back({startPosition, startVelocity});
    }
}

void ParticleSystem::Update(const VectorField& field, const int screenWidth, int screenHeight)
{
    int field_cols = field.GetCols();
    int field_rows = field.GetRows();

    for (auto& p : Particles)
    {
        // Convert particle world position to vector field grid indices
        int gridX = static_cast<int>(p.Position.x / Spacing);
        int gridY = static_cast<int>(p.Position.y / Spacing);

        if (gridX >= 0 && gridX < field_cols && gridY >= 0 && gridY < field_rows)
        {
            Vector2 force = field.GetForce(gridX, gridY);
            p.Update(force);
        }

        // Simple screen wrapping for particles
        if (p.Position.x < 0)
        {
            p.Position.x += screenWidth;
        }
        else if (p.Position.x >= screenWidth)
        {
            p.Position.x -= screenWidth;
        }
        if (p.Position.y < 0)
        {
            p.Position.y += screenHeight;
        }
        else if (p.Position.y >= screenHeight)
        {
            p.Position.y -= screenHeight;
        }
    }
}

void ParticleSystem::Draw() const
{
    for (const auto& p : Particles)
    {
        DrawPixelV(p.Position, ColorAlpha(WHITE, 0.25f));
    }
}