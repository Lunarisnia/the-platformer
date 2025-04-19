#include "input_manager.h"
InputManager::InputManager(GLFWwindow *window, GameObject &player,
                           float &deltaTime)
    : window(window), deltaTime(deltaTime), player(player) {}

void InputManager::processInput() {
  float movementSpeed = 0.9f;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    player.translate(glm::vec3(0.0f, 1.0f, 0.0f) * movementSpeed * deltaTime);
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    player.translate(glm::vec3(0.0f, -1.0f, 0.0f) * movementSpeed * deltaTime);
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    player.translate(glm::vec3(-1.0f, 0.0f, 0.0f) * movementSpeed * deltaTime);
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    player.translate(glm::vec3(1.0f, 0.0f, 0.0f) * movementSpeed * deltaTime);
  }
}
