#include "game.h"
#include <cstddef>
Game::Game(float width, float height, float &deltaTime)
    : width(width), height(height), gameState(GAME_PLAYING),
      deltaTime(deltaTime) {}

Game::~Game() {}

void Game::init() {
  // Load textures and stuff
  /*Shader s =*/
  /*    ResourceLoader::LoadShader("../../shaders/vertex/default-vertex.vert",*/
  /*                               "../../shaders/fragment/diffuse.frag");*/
  Shader defaultShader = Shader("./shaders/vertex/default-vertex.vert",
                                "./shaders/fragment/diffuse.frag");
  player = new Player{};
  player->setMaterial(&defaultShader);
}

void Game::update() {
  // Core game logic
}

void Game::render() {
  // Core rendering logic
  player->render();
}
