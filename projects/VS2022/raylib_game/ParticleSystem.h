// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include <vector>
#include "Particle.h"
#include "VectorField.h"

class ParticleSystem
{
public:
    std::vector<Particle> Particles;
    float Spacing;
    Vector2 ScreenCenter;

    explicit ParticleSystem(const float spacing) : Spacing(spacing), ScreenCenter()
    {
    }

    void Init(int screenWidth, int screenHeight, int numParticles = 1000);
    void Update(const VectorField& field, int screenWidth, int screenHeight);
    void Draw() const;
};