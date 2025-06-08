#include "ParticleSystem.h"
#include "MathUtilities.h"
#include "raylib.h"

void ParticleSystem::Init(const int screenWidth, const int screenHeight, const int numParticles)
{
    Particles.clear();

    for (int i = 0; i < numParticles; i++)
    {
        Vector2 startPosition = {
            MathUtilities::GetRandomFloat(0, screenWidth),
            MathUtilities::GetRandomFloat(0, screenHeight)
        };
        Vector2 startVelocity = {0.0f, 0.0f};
        Particles.push_back({startPosition, startVelocity});
    }
}

void ParticleSystem::Update(const VectorField& vectorField)
{
    for (auto& p : Particles)
    {
        int gridX = static_cast<int>(p.Position.x / Spacing);
        int gridY = static_cast<int>(p.Position.y / Spacing);

        Vector2 force = vectorField.GetForce(gridX, gridY);
        p.Update(force);

        float offset = Spacing * 10.f;
        int width = GetScreenWidth();
        int height = GetScreenHeight();
        if (p.Position.x < -offset)
        {
            p.Position.x += width + offset;
        }
        else if (p.Position.x >= width + offset)
        {
            p.Position.x -= width + offset;
        }
        if (p.Position.y < -offset)
        {
            p.Position.y += height + offset;
        }
        else if (p.Position.y >= height + offset)
        {
            p.Position.y -= height + offset;
        }
    }
}

void ParticleSystem::Draw() const
{
    for (const auto& p : Particles)
    {
        DrawPixelV(p.Position, ColorAlpha(WHITE, Alpha));
    }
}