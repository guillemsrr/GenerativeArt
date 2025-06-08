// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include "ParticleSystem.h"
#include "VectorField.h"
#include "raylib.h"

constexpr float vectors_spacing = 10.0f;
constexpr float alpha = 0.015f;

class VectorTrailsApp
{
public:
    VectorTrailsApp(int width, int height);
    ~VectorTrailsApp();

    void Run();

private:
    void Init();
    void Reset();
    void Update();
    void Draw();

    int ScreenWidth;
    int ScreenHeight;

    ParticleSystem ParticleSystem;
    VectorField VectorField;
    RenderTexture2D TrailLayer;
};