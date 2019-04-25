#version 410 core

layout(location = 0) out vec4 color;

in vec3 Pos;
in vec2 TexCoord;

uniform sampler2D texture0;

void main()
{
    color = texture(texture0, TexCoord);
}