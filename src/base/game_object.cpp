#include "game_object.h"

GameObject::GameObject(std::string name, Transform t)
    : name(name), transform(t) {
  // TODO: Replace this with something more proper
  float aspect = 800.0f / 600.0f;
  projectionMatrix = glm::ortho(-aspect, aspect, -1.0f, 1.0f, -1.0f, 1.0f);
  viewMatrix = glm::mat4(1.0f);
  viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f));
}

void GameObject::setActive(bool b) { isActive = b; }
void GameObject::setName(std::string newName) { name = newName; }

void GameObject::translate(glm::vec3 newPosition) {
  transform.position += newPosition;
}

void GameObject::setPosition(glm::vec3 newPosition) {
  transform.position = newPosition;
  glm::mat4 newPosMat = glm::mat4(1.0f);
  newPosMat = glm::translate(newPosMat, newPosition);
}

void GameObject::rotate(glm::vec3 newRotation) {
  // TODO: Implement rotation
  std::cout << "Unimplemented!" << std::endl;
}

void GameObject::scale(glm::vec3 newScale) { transform.scale = newScale; }

void GameObject::debugTransform() {
  std::cout << "DEBUG: " << name << std::endl;
  std::cout << "================= POSITION ==================" << std::endl;
  std::cout << "X: " << transform.position.x << std::endl;
  std::cout << "Y: " << transform.position.y << std::endl;
  std::cout << "Z: " << transform.position.z << std::endl;
  std::cout << "==============================================" << std::endl;
  std::cout << "================= SCALE ==================" << std::endl;
  std::cout << "X: " << transform.scale.x << std::endl;
  std::cout << "Y: " << transform.scale.y << std::endl;
  std::cout << "Z: " << transform.scale.z << std::endl;
  std::cout << "==============================================" << std::endl;
  std::cout << "================= ROTATION ==================" << std::endl;
  std::cout << "X: " << transform.rotation.x << std::endl;
  std::cout << "Y: " << transform.rotation.y << std::endl;
  std::cout << "Z: " << transform.rotation.z << std::endl;
  std::cout << "==============================================" << std::endl;
}

void GameObject::init() {}

void GameObject::render() {}

void GameObject::update() {}

void GameObject::finish() { setPosition(transform.position); }

void GameObject::input(GLFWwindow *window, float &deltaTime) {}
