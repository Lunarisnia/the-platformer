#ifndef SAT_H
#define SAT_H
#include "../base/game_object.h"
#include "glm/ext/vector_float2.hpp"
#include <vector>
class SAT {
public:
  static bool CheckCollision(GameObject &a, GameObject &b);
};
#endif
