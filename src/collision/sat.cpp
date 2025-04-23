#include "sat.h"

std::vector<glm::vec2> getVertices(GameObject &g) {
  Transform t = g.transform;
  std::vector<glm::vec2> vertices = {
      t.position,
      glm::vec2(t.position.x + t.scale.x, t.position.y),
      glm::vec2(t.position.x, t.position.y + t.scale.y),
      t.position + t.scale,
  };

  return vertices;
}

glm::vec2 getNormal(glm::vec2 pointA, glm::vec2 pointB) {
  glm::vec2 normal{
      -(pointB.y - pointA.y),
      pointB.x - pointA.x,
  };

  return glm::normalize(normal);
}

bool SAT::CheckCollision(GameObject &a, GameObject &b) {
  std::vector<glm::vec2> aVertices = getVertices(a);
  std::vector<glm::vec2> bVertices = getVertices(b);

  return false;
}
