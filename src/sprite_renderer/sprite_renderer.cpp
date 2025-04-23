#include "sprite_renderer.h"

SpriteRenderer::SpriteRenderer() {}

SpriteRenderer::SpriteRenderer(Shader mat, glm::mat4 view, glm::mat4 projection)
    : material(mat), view(view), projection(projection) {
  mapMemory(vertices, 0, 3, 3 * sizeof(float), (void *)0);
}

void SpriteRenderer::drawSprite(glm::vec2 position, glm::vec2 size) {
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(position, 0.0f));

  model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));

  model = glm::scale(model, glm::vec3(size, 1.0f));

  material.use();
  material.setMat4("model", model);
  material.setMat4("view", view);
  material.setMat4("projection", projection);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void SpriteRenderer::mapMemory(std::vector<float> vertices,
                               unsigned int location, unsigned int dataSize,
                               unsigned int stride, void *offset) {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * dataSize * sizeof(float),
               &vertices[0], GL_STATIC_DRAW);

  glVertexAttribPointer(location, dataSize, GL_FLOAT, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(location);
}
