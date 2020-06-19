#pragma once
#include "types.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

class Ray {
public:
  Ray() : A(0.0f, 0.0f, 0.0f), B(0.0f, 0.0f, 0.0f){};
  Ray(position const &ORIGIN, position const &DIRECTION)
      : A(ORIGIN), B(DIRECTION){};

  void setOrigin(position const &ORIGIN) { A = ORIGIN; }

  void setDirection(position const &DIRECTION) { B = DIRECTION; }

  const position &origin() const { return A; }

  const position &direction() const { return B; }

  position pointAtParameter(float t) const { return A + t * B; }

private:
  position A;
  position B;
};