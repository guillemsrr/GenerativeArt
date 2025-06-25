#include "MathUtilities.h"
#include "raylib.h"

float MathUtilities::GetRandomFloat(float min, float max)
{
    return min + (static_cast<float>(GetRandomValue(0, 1000)) / 1000.0f) * (max - min);
}