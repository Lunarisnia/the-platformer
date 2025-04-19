#version 330
layout(location = 0) in vec3 aVertexPosition;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main() {
    gl_Position = projection * view * model * vec4(aVertexPosition, 1.0f);
}
