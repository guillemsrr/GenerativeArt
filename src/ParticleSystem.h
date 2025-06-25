// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include <vector>
#include "Particle.h"
#include "VectorField.h"

class ParticleSystem
{
public:
    explicit ParticleSystem(const float spacing) : Spacing(spacing), ScreenCenter()
    {
    }

    void Init(int screenWidth, int screenHeight, int numParticles = 1000);
    void Update(const VectorField& vectorField);
    void Draw() const;

private:
    std::vector<Particle> Particles;
    float Spacing;
    Vector2 ScreenCenter;
    const float Alpha = 0.15f;
};