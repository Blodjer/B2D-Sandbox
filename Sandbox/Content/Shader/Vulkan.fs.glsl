#version 450 core

#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 in_color;
layout(location = 1) in vec2 in_texcoord;

layout(location = 0) out vec4 out_color;

layout(set = 0, binding = 0) uniform RenderMatrices
{
	mat4 render_matrix;
} ubo;

layout(set = 1, binding = 0) uniform MaterialData
{
	float value;
} material;

layout(set = 2, binding = 0) uniform sampler2D tex0;

void main()
{
	vec3 color = texture(tex0, in_texcoord).rgb;
    out_color = vec4(color, 1.0);
}