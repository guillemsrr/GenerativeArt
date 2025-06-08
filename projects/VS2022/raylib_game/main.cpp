#include "VectorTrailsApp.h"

constexpr int screen_width = 1080;
constexpr int screen_height = 1080;

int main()
{
    VectorTrailsApp app(screen_width, screen_height);
    app.Run();
    return 0;
}