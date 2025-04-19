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

// NOTE: maybe separate the memory mapping for texture coordinate later?
void GameObject::mapMemory(std::vector<float> vertices, unsigned int location,
                           unsigned int dataSize, unsigned int stride,
                           void *offset) {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * dataSize * sizeof(float),
               &vertices[0], GL_STATIC_DRAW);

  glVertexAttribPointer(location, dataSize, GL_FLOAT, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(location);
}

void GameObject::render() {}
