// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include "ParticleSystem.h"
#include "VectorField.h"
#include "raylib.h"

class VectorTrailsApp
{
public:
    VectorTrailsApp(int width, int height);
    ~VectorTrailsApp();

    void Run();

private:
    const float RectangleFadeAlpha = 0.015f;
    const float Spacing = 10.0f;

    int ScreenWidth;
    int ScreenHeight;
    const int NumberParticles = 5000;

    ParticleSystem ParticleSystem;
    VectorField VectorField;
    RenderTexture2D TrailLayer;

    void Init();
    void Reset();
    void HandleInputType();
    void Update();
    void Draw();
};