#version 450

//! [0]

in Fragment
{
    vec4 color;
} fragment;

out vec4 color;

void main(void)
{
    color = fragment.color;
}
//! [0]
