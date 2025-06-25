#include "VectorTrailsApp.h"

VectorTrailsApp::VectorTrailsApp(int width, int height)
    : ScreenWidth(width), ScreenHeight(height), ParticleSystem(Spacing),
      VectorField(width, height, Spacing)
{
    Init();
}

VectorTrailsApp::~VectorTrailsApp()
{
    UnloadRenderTexture(TrailLayer);
}

void VectorTrailsApp::Init()
{
    InitWindow(ScreenWidth, ScreenHeight, "Generative Art");
    SetTargetFPS(60);

    TrailLayer = LoadRenderTexture(ScreenWidth, ScreenHeight);

    Reset();
}

void VectorTrailsApp::Reset()
{
    ParticleSystem.Init(GetScreenWidth(), GetScreenHeight(), NumberParticles);
    VectorField.Init();

    BeginTextureMode(TrailLayer);
    ClearBackground(BLACK);
    EndTextureMode();
}

void VectorTrailsApp::HandleInputType()
{
    if (IsKeyPressed(KEY_ONE))
    {
        VectorField.SetFieldType(VectorFieldType::Algae);
        Reset();
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        VectorField.SetFieldType(VectorFieldType::Octopus);
        Reset();
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        VectorField.SetFieldType(VectorFieldType::Waves);
        Reset();
    }
    else if (IsKeyPressed(KEY_FOUR))
    {
        VectorField.SetFieldType(VectorFieldType::Arround);
        Reset();
    }
    else if (IsKeyPressed(KEY_FIVE))
    {
        VectorField.SetFieldType(VectorFieldType::Horizontal);
        Reset();
    }
}

void VectorTrailsApp::Update()
{
    HandleInputType();

    ParticleSystem.Update(VectorField);
    Draw();
}

void VectorTrailsApp::Draw()
{
    BeginTextureMode(TrailLayer);
    BeginBlendMode(BLEND_ADDITIVE);
    DrawRectangle(0, 0, ScreenWidth, ScreenHeight, ColorAlpha(BLACK, RectangleFadeAlpha));
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