#include "player.h"
#include "glm/ext/vector_float3.hpp"
Player::Player() {};
Player::Player(std::string name, Transform trans) : GameObject(name, trans) {}

float timeStep = 1.0f / 60.0f;
glm::vec3 gravity = glm::vec3(0.0f, -10.0f, 0.0f);
bool onAir = false;
int jumpCount = 1;

void Player::init() {
  Shader defaultShader =
      ResourceLoader::LoadShader("./shaders/vertex/default-vertex.vert",
                                 "./shaders/fragment/diffuse.frag");
  SpriteRenderer sr(defaultShader, viewMatrix, projectionMatrix);
  setSpriteRenderer(sr);
}

void Player::update(float &deltaTime) {
  velocity.y += gravity.y * timeStep;
  transform.position.y += velocity.y * timeStep;

  // TODO: Implement a better collision detection against another object
  if (transform.position.y < -0.25f) {
    transform.position.y = -0.25f;
    onAir = false;
    jumpCount = 1;
  }
  if (transform.position.y > -0.25f) {
    onAir = true;
  }

  setPosition(transform.position);
}

void Player::input(bool keys[], float &deltaTime) {
  float movementSpeed = 0.9f;
  if (keys[GLFW_KEY_W] && jumpCount > 0) {
    velocity.y = 2.0f;
    jumpCount--;
  }
  if (keys[GLFW_KEY_D]) {
    translate(glm::vec3(0.5f, 0.0f, 0.0f) * deltaTime);
  }
  if (keys[GLFW_KEY_A]) {
    translate(glm::vec3(-0.5f, 0.0f, 0.0f) * deltaTime);
  }
}

void Player::render() {
  spriteRenderer.drawSprite(transform.position, transform.scale);
}

void Player::setSpriteRenderer(SpriteRenderer sr) { spriteRenderer = sr; }
