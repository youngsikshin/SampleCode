#version 450

in vec4 offset;

//! [0]
void main(void)
{
    const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0),
                                     vec4(-0.25, -0.25, 0.5, 1.0),
                                     vec4(0.25, 0.25, 0.5, 1.0));

    gl_Position = vertices[gl_VertexID] + offset;
}
//! [0]
