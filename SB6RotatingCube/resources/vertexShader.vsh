#version 450

//! [0]
in vec4 position;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out VS_OUT
{
    vec4 color;
} vs_out;

void main(void)
{
    gl_Position = proj_matrix*mv_matrix * position;
    vs_out.color = position + vec4(0.5, 0.5, 0.5, 0.0);
}
//! [0]
