#ifndef GAME_H
#define GAME_H
#include "../collision/sat.h"
#include "../player/player.h"
#include "../resource/resource_loader.h"
#include "../shader/shader.h"
#include "../sprite_renderer/sprite_renderer.h"
#include "game_object.h"
enum GameState { GAME_MENU, GAME_PLAYING, GAME_WINNING, GAME_ENDING };

class Game {
public:
  float width, height;
  float &deltaTime;
  bool keys[1024];
  GameState gameState;
  Game(float width, float height, float &deltaTime);
  ~Game();

  Player player;
  GameObject obj;

  void init();
  void update();
  void render();
  void processInput();
};
#endif
