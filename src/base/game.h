#ifndef GAME_H
#define GAME_H
#include "../player/player.h"
#include "../resource/resource_loader.h"
#include "../shader/shader.h"
#include "../sprite_renderer/sprite_renderer.h"
enum GameState { GAME_MENU, GAME_PLAYING, GAME_WINNING, GAME_ENDING };

class Game {
public:
  float width, height;
  float &deltaTime;
  GameState gameState;
  Game(float width, float height, float &deltaTime);
  ~Game();

  Player player;

  void init();
  void update();
  void render();
};
#endif
