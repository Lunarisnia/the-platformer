#include "input_manager.h"
InputManager::InputManager(GLFWwindow *window, Player &player, float &deltaTime)
    : window(window), deltaTime(deltaTime), player(player) {}

void InputManager::processInput() { player.input(window, deltaTime); }
