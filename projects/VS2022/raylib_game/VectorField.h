// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once
#include <vector>
#include "raylib.h"

class VectorField
{
public:
    VectorField(int screenWidth, int screenHeight, float spacing);

    void Init();
    Vector2 GetForce(int gridX, int gridY) const;

    int GetCols() const { return Columns; }
    int GetRows() const { return Rows; }

private:
    int Columns;
    int Rows;
    float FieldSpacing;
    std::vector<std::vector<Vector2>> Field;
    float RandomSeed;

    Vector2 CalculateFieldVector(int x, int y) const;
};