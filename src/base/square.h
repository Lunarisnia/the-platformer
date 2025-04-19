#ifndef SQUARE_H
#define SQUARE_H
#include "../shader/shader.h"
#include "game_object.h"
#include <glad/glad.h>
#include <vector>
class Square : public GameObject {
private:
  // TODO: Add texture coordinate
  std::vector<float> mesh = {
      0.5f, 0.5f, 0.0f,  // Top right
      -0.5f, 0.5f, 0.0f, // Top left
      0.5f, -0.5f, 0.0f, // Bottom right
      // 2nd triangle
      -0.5f, 0.5f, 0.0f,  // Top left
      -0.5f, -0.5f, 0.0f, // Bottom left
      0.5f, -0.5f, 0.0f   // Bottom right
  };

public:
  Shader shader;
  Square(std::string name = "NewSquare", Transform trans = Transform{});
  void render();
};
#endif
