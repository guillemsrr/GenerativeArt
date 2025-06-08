#include "VectorTrailsApp.h"

VectorTrailsApp::VectorTrailsApp(int width, int height)
    : ScreenWidth(width), ScreenHeight(height), ParticleSystem(vectors_spacing),
      VectorField(width, height, vectors_spacing)
{
    Init();
}

VectorTrailsApp::~VectorTrailsApp()
{
    UnloadRenderTexture(TrailLayer);
}

void VectorTrailsApp::Init()
{
    InitWindow(ScreenWidth, ScreenHeight, "Vector Trails");
    SetTargetFPS(60);

    ParticleSystem.Init(ScreenWidth, ScreenHeight, 1000);
    VectorField.Init();

    TrailLayer = LoadRenderTexture(ScreenWidth, ScreenHeight);

    BeginTextureMode(TrailLayer);
    ClearBackground(BLACK);
    EndTextureMode();
}

void VectorTrailsApp::Reset()
{
    ParticleSystem.Init(ScreenWidth, ScreenHeight, 1000);
    VectorField.Init();

    BeginTextureMode(TrailLayer);
    ClearBackground(BLACK);
    EndTextureMode();
}

void VectorTrailsApp::Update()
{
    if (IsKeyPressed(KEY_ONE))
    {
        Reset();
    }

    ParticleSystem.Update(VectorField, ScreenWidth, ScreenHeight);
}

void VectorTrailsApp::Draw()
{
    BeginTextureMode(TrailLayer);
    BeginBlendMode(BLEND_ADDITIVE);
    DrawRectangle(0, 0, ScreenWidth, ScreenHeight, ColorAlpha(BLACK, alpha));
    ParticleSystem.Draw();
    EndBlendMode();
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextureRec(TrailLayer.texture,
                   {0, 0, static_cast<float>(ScreenWidth), -static_cast<float>(ScreenHeight)},
                   {0, 0},
                   WHITE);
    EndDrawing();
}

void VectorTrailsApp::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();
}