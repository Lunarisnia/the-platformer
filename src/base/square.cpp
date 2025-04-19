#include "square.h"
Square::Square(std::string name, Transform trans)
    : GameObject{name, trans},
      shader(Shader("./shaders/vertex/default-vertex.vert",
                    "./shaders/fragment/diffuse.frag")) {
  mapMemory(mesh, 0, 3, 3 * sizeof(float), (void *)0);
}

void Square::render() {
  shader.use();
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}
