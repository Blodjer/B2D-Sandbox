#version 450 core

layout(location = 0) out vec4 color;

layout(location = 0) in vec3 Pos;
layout(location = 1) in vec2 TexCoord;

layout(binding = 0) uniform sampler2D texture0;
layout(binding = 1) uniform sampler2D texture1;

uniform float rotation;

void main()
{
    vec4 d = texture(texture0, TexCoord);
    vec3 n = texture(texture1, TexCoord).xyz;
    n.xy = n.xy * 2 - 1;
    n.z = n.z - 0.5;

    vec2 lightPos = vec2((sin(rotation) + 1) * 0.4, (cos(rotation) + 1) * 0.3);
    float g = 1 - distance(lightPos, TexCoord);

    vec3 light = vec3(lightPos - TexCoord, 0.1);//vec3(sin(rotation), cos(rotation), 1);
    float f = dot(normalize(light), normalize(n.xyz));

    color = vec4(d.xyz * max(f * g * vec3(1, 0.5, 4), 0.2), d.w); //texture(texture0, TexCoord);// * vec4(0.0, 1.0, 1.0, 1.0);
}

//  X: -1 to +1 :  Red: 0 to 255
//  Y: -1 to +1 :  Green: 0 to 255
//  Z: 0 to -1 :  Blue: 128 to 255