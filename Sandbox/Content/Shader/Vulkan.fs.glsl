#version 450 core

#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) out vec4 out_color;

layout(location = 0) in vec3 in_color;

void main()
{
    out_color = vec4(in_color, 1) * vec4(1, 1, 1, 1);
}