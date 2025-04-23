#include "enemy.h"
Enemy::Enemy(std::string name, Transform trans) : GameObject(name, trans) {}

void Enemy::init() {}

void Enemy::update(float &deltaTime) {}

void Enemy::render() {}

void Enemy::setSpriteRenderer(SpriteRenderer sr) { spriteRenderer = sr; }
