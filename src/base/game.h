#ifndef GAME_H
#define GAME_H
#include "../player/player.h"
#include "../resource/resource_loader.h"
#include "../shader/shader.h"
enum GameState { GAME_MENU, GAME_PLAYING, GAME_WINNING, GAME_ENDING };

class Game {
public:
  float width, height;
  float &deltaTime;
  GameState gameState;
  Game(float width, float height, float &deltaTime);
  ~Game();

  /*Shader defaultShader = Shader{"../../shaders/vertex/default-vertex.vert",*/
  /*                              "../../shaders/fragment/diffuse.frag"};*/

  Player *player;

  void init();
  void update();
  void render();
};
#endif
