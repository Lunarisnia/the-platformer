#ifndef PLAYER_H
#define PLAYER_H
#include "../base/game_object.h"
#include "../shader/shader.h"
#include "../sprite_renderer/sprite_renderer.h"
#include "glm/ext/vector_float2.hpp"
#include <GLFW/glfw3.h>
#include <string>
class Player : public GameObject {
public:
  glm::vec3 velocity;
  SpriteRenderer spriteRenderer;
  Player();
  Player(std::string name, Transform trans = Transform{});

  void setSpriteRenderer(SpriteRenderer sr);

  void update();
  void render();
  void input(bool keys[], float &deltaTime);
};
#endif
