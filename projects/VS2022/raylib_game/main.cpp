// Copyright (c) Guillem Serra. All Rights Reserved.

#include "raylib.h"
#include "VectorTrailsApp.h"

constexpr int screen_width = 1080;
constexpr int screen_height = 1080;

int main()
{
    VectorTrailsApp app(screen_width, screen_height);
    while (!WindowShouldClose())
    {
        app.Update();
    }

    CloseWindow();
    return 0;
}