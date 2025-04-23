#include "game.h"
#include "game_object.h"
#include "glm/ext/vector_float3.hpp"
#include <cstddef>
Game::Game(float width, float height, float &deltaTime)
    : width(width), height(height), gameState(GAME_PLAYING),
      deltaTime(deltaTime) {}

Game::~Game() {}

void Game::init() {
  // Load textures and stuff
  player = Player{"Player"};
  player.init();

  obj = GameObject();
  obj.scale(glm::vec3(0.5f, 0.5f, 0.0f));
  obj.setPosition(glm::vec3(0.7f, 0.2f, 0.0f));
  bool collided = SAT::CheckCollision(player, obj);
  if (collided) {
  }
}

void Game::update() {
  // Core game logic
  player.update(deltaTime);
}

void Game::render() {
  // Core rendering logic
  player.render();
  Shader sh("./shaders/vertex/default-vertex.vert",
            "./shaders/fragment/diffuse.frag");
  SpriteRenderer s{sh, obj.viewMatrix, obj.projectionMatrix};
  s.drawSprite(obj.transform.position, obj.transform.scale);
}

void Game::processInput() { player.input(keys, deltaTime); }
