#version 330
layout(location = 0) in vec3 aVertexPosition;

void main() {
    gl_Position = vec4(aVertexPosition, 1.0f);
}
