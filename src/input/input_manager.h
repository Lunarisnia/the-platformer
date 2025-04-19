#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include "../base/game_object.h"
#include "GLFW/glfw3.h"
#include "glm/ext/vector_float3.hpp"
#include <iostream>
class InputManager {
private:
  GLFWwindow *window;
  float &deltaTime;
  GameObject &player;

public:
  InputManager(GLFWwindow *window, GameObject &player, float &deltaTime);
  void processInput();
};
#endif
