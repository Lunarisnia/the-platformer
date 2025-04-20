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
  player = Player{"Player"};
  player.setSpriteRenderer(sr);
}

void Game::update() {
  // Core game logic
  player.update();
}

void Game::render() {
  // Core rendering logic
  player.render();
}

void Game::processInput() { player.input(keys, deltaTime); }
