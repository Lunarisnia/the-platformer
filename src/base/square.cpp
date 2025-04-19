#include "square.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
Square::Square(std::string name, Transform trans)
    : GameObject{name, trans},
      shader(Shader("./shaders/vertex/default-vertex.vert",
                    "./shaders/fragment/diffuse.frag")) {
  projectionMatrix =
      glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, -100.0f);
  viewMatrix = glm::mat4(1.0f);
  viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
  mapMemory(mesh, 0, 3, 3 * sizeof(float), (void *)0);
}

void Square::render() {
  shader.use();
  shader.setMat4("model", transformMatrix);
  shader.setMat4("projection", projectionMatrix);
  shader.setMat4("view", viewMatrix);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}
