#include "aabb.h"
bool AABB::CheckCollision(GameObject &a, GameObject &b) {
  bool collisionX =
      a.transform.position.x + a.transform.scale.x >= b.transform.position.x &&
      b.transform.position.x + b.transform.scale.x >= a.transform.position.x;
  bool collisionY =
      a.transform.position.y + a.transform.scale.y >= b.transform.position.y &&
      b.transform.position.y + b.transform.scale.y >= a.transform.position.y;
  return collisionX && collisionY;
}
