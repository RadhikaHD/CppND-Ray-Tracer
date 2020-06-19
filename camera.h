#pragma once
#include "ray.h"
#include "types.h"
#include <glm/glm.hpp>

class Camera {
public:
  Camera();

  Camera(position lookfrom, position lookat, position vup, float vfov,
         float aspect);

  Ray get_ray(float u, float v) const;

private:
  position origin;
  position screen_bottom_left;
  position screen_width;
  position screen_height;
};