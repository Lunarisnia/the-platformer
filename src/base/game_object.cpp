#include "game_object.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

GameObject::GameObject(std::string name, Transform t)
    : name(name), transform(t) {
  transformMatrix = glm::mat4(1.0f);
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
  transformMatrix = glm::translate(transformMatrix, transform.position);
}

void GameObject::setPosition(glm::vec3 newPosition) {
  transform.position = newPosition;
  glm::mat4 newPosMat = glm::mat4(1.0f);
  newPosMat = glm::translate(newPosMat, newPosition);

  transformMatrix[3][0] = newPosMat[3][0];
  transformMatrix[3][1] = newPosMat[3][1];
  transformMatrix[3][2] = newPosMat[3][2];
}

void GameObject::rotate(glm::vec3 newRotation) {
  // TODO: Implement rotation
  std::cout << "Unimplemented!" << std::endl;
}

void GameObject::scale(glm::vec3 newScale) {
  transform.scale = newScale;
  transformMatrix = glm::scale(transformMatrix, transform.scale);
}

void GameObject::render() {}

void GameObject::update() {}

void GameObject::finish() { setPosition(transform.position); }

void GameObject::input(GLFWwindow *window, float &deltaTime) {}
