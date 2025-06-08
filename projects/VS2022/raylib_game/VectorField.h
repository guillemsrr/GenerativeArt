// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include <vector>
#include "raylib.h"

enum class VectorFieldType
{
    Algae,
    Octopus,
    Waves,
    Arround,
    Horizontal,
};

class VectorField
{
public:
    VectorField(int screenWidth, int screenHeight, float spacing);

    void Init();
    Vector2 GetForce(int gridX, int gridY) const;
    void SetFieldType(VectorFieldType type);

private:
    int Columns;
    int Rows;
    float FieldSpacing;
    std::vector<std::vector<Vector2>> Field;
    float Magnitude = 1.f;
    VectorFieldType Type = VectorFieldType::Waves;

    Vector2 GetTypedForce(int x, int y);
};