#ifndef ENEMIES_H
#define ENEMIES_H
#include "../base/game_object.h"
#include "../sprite_renderer/sprite_renderer.h"
class Enemy : public GameObject {
private:
  SpriteRenderer spriteRenderer;

public:
  Enemy(std::string name = "NewEnemy", Transform trans = Transform());

  void setSpriteRenderer(SpriteRenderer sr);

  void init();
  void update(float &deltaTime);
  void render();
};
#endif
