#pragma once

#include "hittable.h"

class Sphere : public Hittable {
public:
  Sphere() : radius(0.0), center(0.0f, 0.0f, 0.0f){};

  Sphere(float radius, position center) : radius(radius), center(center){};

  inline float getRadius() { return this->radius; }

  inline position getCenter() { return this->center; }

  virtual bool hit(Ray const &r, float const tmin, float const tmax,
                   std::shared_ptr<hit_record> &rec);

private:
  position center;
  float radius;
};