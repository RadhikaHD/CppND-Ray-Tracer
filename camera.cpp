#include "camera.h"
#include "ray.h"

Camera::Camera()
    : origin(0.0f, 0.0f, 0.0f), screen_bottom_left(0.0f, 0.0f, 0.0f),
      screen_width(0.0f, 0.0f, 0.0f), screen_height(0.0f, 0.0f, 0.0f) {}

Camera::Camera(float vfov,
               float aspect) {

  auto theta = (M_PI*vfov)/180;
  auto h = tan(theta / 2);
  auto viewport_height = 2.0 * h;
  auto viewport_width = aspect * viewport_height;

  auto focal_length = 1.0;

  origin = position (0, 0, 0);
  screen_width = position (viewport_width, 0.0, 0.0);
  screen_height = position (0.0, viewport_height, 0.0);
  screen_bottom_left =
      origin - (screen_width/2.0f)- (screen_height/2.0f) - position (0, 0, focal_length);
}

Ray Camera::get_ray(float u, float v) const {
  return Ray(origin, (screen_bottom_left +
                      (u * screen_width + v * screen_height) - origin));
}