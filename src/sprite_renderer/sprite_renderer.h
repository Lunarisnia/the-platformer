#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H
#include "../shader/shader.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/trigonometric.hpp"
#include <glad/glad.h>
#include <vector>
class SpriteRenderer {

private:
  unsigned int VAO, VBO;
  std::vector<float> vertices = {
      0.5f, 0.5f, 0.0f,  // Top right
      0.5f, -0.5f, 0.0f, // Bottom right
      -0.5f, 0.5f, 0.0f, // Top left
      //
      -0.5f, 0.5f, 0.0f,  // Top left
      -0.5f, -0.5f, 0.0f, // Bottom left
      0.5f, -0.5f, 0.0f   // Bottom right
  };

  void mapMemory(std::vector<float> vertices, unsigned int location,
                 unsigned int dataSize, unsigned int stride, void *offset);

  glm::mat4 projection;
  glm::mat4 view;

public:
  Shader material;
  SpriteRenderer();
  SpriteRenderer(Shader mat, glm::mat4 view, glm::mat4 projection);
  void drawSprite(glm::vec2 position, glm::vec2 size);
};
#endif
