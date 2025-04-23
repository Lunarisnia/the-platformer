#ifndef AABB_H
#define AABB_H
#include "../base/game_object.h"
class AABB {
public:
  static bool CheckCollision(GameObject &a, GameObject &b);
};
#endif
