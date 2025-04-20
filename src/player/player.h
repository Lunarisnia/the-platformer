#ifndef PLAYER_H
#define PLAYER_H
#include "../base/game_object.h"
#include "../shader/shader.h"
#include "glm/ext/vector_float2.hpp"
#include <GLFW/glfw3.h>
#include <string>
class Player : public GameObject {
public:
  glm::vec3 velocity;
  Shader *material;
  Player(std::string name = "NewPlayer", Transform trans = Transform{});

  void setMaterial(Shader *mat);

  void update();
  void render();
  void input(GLFWwindow *window, float &deltaTime);
};
#endif
