#include "VectorField.h"
#include <vector>
#include "MathUtilities.h"

VectorField::VectorField(int screenWidth, int screenHeight, float spacing)
    : FieldSpacing(spacing)
{
    Columns = static_cast<int>(screenWidth / spacing);
    Rows = static_cast<int>(screenHeight / spacing);
}

void VectorField::Init()
{
    Magnitude = 1.f;
    Field.resize(Columns);
    for (int x = 0; x < Columns; x++)
    {
        Field[x].resize(Rows);
        for (int y = 0; y < Rows; y++)
        {
            Field[x][y] = GetTypedForce(x, y);
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

void VectorField::SetFieldType(VectorFieldType type)
{
    this->Type = type;
}

Vector2 VectorField::GetTypedForce(int x, int y)
{
    Vector2 force = {0, 0};
    if (Type == VectorFieldType::Algae)
    {
        Magnitude = 0.75f;
        float randomX = MathUtilities::GetRandomFloat(0.1f, 1.f);
        float randomY = MathUtilities::GetRandomFloat(0.1f, 1.f);
        float angleNoise = MathUtilities::GetRandomFloat(0.1f, 1.f);
        float angle = sinf(x * randomX * FieldSpacing + y * randomY * FieldSpacing) + angleNoise;

        force = {cosf(angle), sinf(angle)};
    }
    else if (Type == VectorFieldType::Octopus)
    {
        Magnitude = 3.f;
        float RandomSeed = MathUtilities::GetRandomFloat(0.1f, 10.f);
        float noise = sinf(x * 0.1f + RandomSeed) * cosf(y * 0.1f + RandomSeed) * PI;
        float angle = sinf(x * 0.1f * (FieldSpacing / 10.0f) + y * 0.1f * (FieldSpacing / 10.0f)) + noise;
        force = {cosf(angle), sinf(angle)};
    }
    else if (Type == VectorFieldType::Waves)
    {
        float angle = sinf(x * 0.1f * (FieldSpacing / 10.0f) + y * 0.1f * (FieldSpacing / 10.0f));
        force = {cosf(angle), sinf(angle)};
    }
    else if (Type == VectorFieldType::Arround)
    {
        Magnitude = 2.f;

        float margin = 0.005f;
        float RandomSeedX = MathUtilities::GetRandomFloat(0.f, margin);
        float RandomSeedY = MathUtilities::GetRandomFloat(0.f, margin);

        float angle = sinf(x * RandomSeedX + y * RandomSeedY);
        force = {cosf(angle), sinf(angle)};
    }
    else if (Type == VectorFieldType::Horizontal)
    {
        float margin = 0.005f;
        float RandomSeedX = MathUtilities::GetRandomFloat(-margin, margin);
        float RandomSeedY = MathUtilities::GetRandomFloat(-margin, margin);

        float angle = sinf(x * RandomSeedX + y * RandomSeedY);
        force = {cosf(angle), sinf(angle)};
    }

    force.x *= Magnitude;
    force.y *= Magnitude;

    return force;
}