#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include "../base/game_object.h"
#include "../player/player.h"
#include "GLFW/glfw3.h"
#include "glm/ext/vector_float3.hpp"
#include <iostream>
class InputManager {
private:
  GLFWwindow *window;
  float &deltaTime;
  Player &player;

public:
  InputManager(GLFWwindow *window, Player &player, float &deltaTime);
  void processInput();
};
#endif
