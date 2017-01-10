#version 450

//! [0]
uniform mat4 mvpMatrix;

in vec4 position;
in vec4 instance_color;
in vec4 instance_position;

out Fragment
{
    vec4 color;
} fragment;

void main(void)
{
    gl_Position = mvpMatrix * (position + instance_position * vec4(0.25, 0.25, 1.0, 1.0));
    fragment.color = instance_color;
}
//! [0]
