#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <glad/glad.h>
// FORCE
#include "GLFW/glfw3.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <vector>

struct Transform {
  glm::vec3 position = glm::vec3(0.0f);
  // NOTE: at the moment rotation doesn't work
  glm::vec3 rotation = glm::vec3(0.0f);
  glm::vec3 scale = glm::vec3(1.0f);
};

class GameObject {
public:
  // NOTE: Maybe put it somewhere else? since this is only for rendering
  glm::mat4 projectionMatrix;
  glm::mat4 viewMatrix;

public:
  std::string name;
  Transform transform;
  bool isActive;

  GameObject(std::string name = "NewGameObject", Transform trans = Transform{});
  void setActive(bool b);
  void setName(std::string newName);
  void translate(glm::vec3 newPosition);
  void setPosition(glm::vec3 newPosition);
  void rotate(glm::vec3 newRotation);
  void scale(glm::vec3 newScale);
  void render();

  void debugTransform();

  void init();
  void update();
  void finish();
  void input(GLFWwindow *window, float &deltaTime);
};
#endif
