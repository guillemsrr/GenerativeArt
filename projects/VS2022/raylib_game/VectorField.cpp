#include "VectorField.h"
#include <vector>

VectorField::VectorField(int screenWidth, int screenHeight, float spacing)
    : FieldSpacing(spacing), RandomSeed(0)
{
    if (spacing <= 0)
    {
        Columns = 1;
        Rows = 1;
    }
    else
    {
        Columns = static_cast<int>(screenWidth / spacing);
        Rows = static_cast<int>(screenHeight / spacing);
    }

    if (Columns <= 0)
    {
        Columns = 1;
    }
    if (Rows <= 0)
    {
        Rows = 1;
    }
}

void VectorField::Init()
{
    RandomSeed = GetRandomValue(0, 1000) / 100.f;

    Field.resize(Columns);
    for (int x = 0; x < Columns; x++)
    {
        Field[x].resize(Rows);
        for (int y = 0; y < Rows; y++)
        {
            Field[x][y] = CalculateFieldVector(x, y);
        }
    }
}

Vector2 VectorField::GetForce(int gridX, int gridY) const
{
    if (gridX >= 0 && gridX < Columns && gridY >= 0 && gridY < Rows)
    {
        return Field[gridX][gridY];
    }
    return {0, 0};
}

Vector2 VectorField::CalculateFieldVector(int x, int y) const
{
    float noise = sinf(x * 0.1f + RandomSeed) * cosf(y * 0.1f + RandomSeed) * PI;
    float angle = sinf(x * 0.1f * (FieldSpacing / 10.0f) + y * 0.1f * (FieldSpacing / 10.0f)) + noise;
    Vector2 force = {cosf(angle), sinf(angle)};
    float magnitude = 1.f;
    force.x *= magnitude;
    force.y *= magnitude;

    return force;
}