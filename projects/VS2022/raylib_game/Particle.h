// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include "VectorField.h"

struct Particle
{
    Vector2 Position;
    Vector2 Velocity;
    void Update(Vector2 force);
};