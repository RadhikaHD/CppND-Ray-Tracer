#pragma once
#include "ray.h"
#include "types.h"
#include <glm/glm.hpp>

class Camera {
public:
  Camera()
      : origin(0.0f, 0.0f, 0.0f), screen_bottom_left(0.0f, 0.0f, 0.0f),
        screen_width(0.0f, 0.0f, 0.0f), screen_height(0.0f, 0.0f, 0.0f){};
  Camera(position const &origin, position const &screen_bottom_left,
         float screen_width, float screen_height)
      : origin(origin), screen_bottom_left(screen_bottom_left),
        screen_width(screen_width, 0.0f, 0.0f),
        screen_height(0.0f, screen_height, 0.0f){};
  Ray get_ray(float u, float v) const{
    return Ray(origin, (screen_bottom_left +
                        (u * screen_width + v * screen_height) - origin));
  }

private:
  position origin;
  position screen_bottom_left;
  position screen_width;
  position screen_height;
};