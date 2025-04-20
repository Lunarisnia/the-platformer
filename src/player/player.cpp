#include "player.h"
Player::Player() {};
Player::Player(std::string name, Transform trans) : GameObject(name, trans) {}

float timeStep = 1.0f / 60.0f;
glm::vec3 gravity = glm::vec3(0.0f, -10.0f, 0.0f);
bool onAir = false;
void Player::update() {
  velocity.y += gravity.y * timeStep;
  transform.position.y += velocity.y * timeStep;

  // TODO: Implement a better collision detection against another object
  if (transform.position.y < -0.25f) {
    transform.position.y = -0.25f;
    onAir = false;
  }
  if (transform.position.y > -0.25f) {
    onAir = true;
  }
}

bool wKey = false;
void Player::input(GLFWwindow *window, float &deltaTime) {
  float movementSpeed = 0.9f;
  if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) && !wKey) {
    velocity.y = 2.0f;
    wKey = true;
  }
  if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE) && wKey) {
    wKey = false;
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    translate(glm::vec3(-1.0f, 0.0f, 0.0f) * movementSpeed * deltaTime);
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    translate(glm::vec3(1.0f, 0.0f, 0.0f) * movementSpeed * deltaTime);
  }
}

void Player::render() {
  spriteRenderer.render(transformMatrix, viewMatrix, projectionMatrix);
}

void Player::setSpriteRenderer(SpriteRenderer sr) { spriteRenderer = sr; }
