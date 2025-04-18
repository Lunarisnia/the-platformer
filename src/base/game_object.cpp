#include "game_object.h"

GameObject::GameObject(std::string name, Transform t)
    : name(name), transform(t) {
  transformMatrix = glm::mat4(1.0f);
}

void GameObject::setActive(bool b) { isActive = b; }
void GameObject::setName(std::string newName) { name = newName; }

void GameObject::translate(glm::vec3 newPosition) {
  transform.position = newPosition;
  updateMatrix();
}

void GameObject::rotate(glm::vec3 newRotation) {
  // TODO: Implement rotation
  std::cout << "Unimplemented!" << std::endl;
}

void GameObject::scale(glm::vec3 newScale) { transform.scale = newScale; }

void GameObject::updateMatrix() {
  transformMatrix = glm::translate(transformMatrix, transform.position);
  // TODO: Deal with rotation
  transformMatrix = glm::scale(transformMatrix, transform.scale);
};
