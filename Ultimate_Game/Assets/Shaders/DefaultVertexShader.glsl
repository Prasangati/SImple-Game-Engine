#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
uniform ivec2 ScreenSize;

void main()
{
    // Map from screen coordinates to normalized device coordinates
    float x = (aPos.x * 2.0) / float(ScreenSize.x) - 1.0;
    float y = (aPos.y * 2.0) / float(ScreenSize.y) - 1.0;
    gl_Position = vec4(x, y, 0.0, 1.0);
    TexCoord = aTexCoord;
}
