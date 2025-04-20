#include "game.h"
#include <cstddef>
Game::Game(float width, float height, float &deltaTime)
    : width(width), height(height), gameState(GAME_PLAYING),
      deltaTime(deltaTime) {}

Game::~Game() {}

void Game::init() {
  // Load textures and stuff
  Shader defaultShader =
      ResourceLoader::LoadShader("./shaders/vertex/default-vertex.vert",
                                 "./shaders/fragment/diffuse.frag");
  SpriteRenderer sr(defaultShader);
  player = Player{"Hello"};
  player.setSpriteRenderer(sr);
}

void Game::update() {
  // Core game logic
  player.update();
  player.finish();
}

void Game::render() {
  // Core rendering logic
  player.render();
}
