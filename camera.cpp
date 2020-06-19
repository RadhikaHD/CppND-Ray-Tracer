#include "camera.h"
#include "ray.h"

Camera::Camera()
    : origin(0.0f, 0.0f, 0.0f), screen_bottom_left(0.0f, 0.0f, 0.0f),
      screen_width(0.0f, 0.0f, 0.0f), screen_height(0.0f, 0.0f, 0.0f) {}

Camera::Camera(position lookfrom, position lookat, position vup, float vfov,
               float aspect) {

  float theta = (M_PI * vfov) / 180.0f;
  float h = tan(theta / 2.0f);
  float viewport_height = 2.0f * h;
  float viewport_width = aspect * viewport_height;

  position w = glm::normalize(lookfrom - lookat);
  position u = glm::normalize(glm::cross(vup, w));
  position v = glm::cross(w, u);

  origin = lookfrom;
  screen_width = viewport_width * u;
  screen_height = viewport_height * v;
  screen_bottom_left =
      origin - (screen_width / 2.0f) - (screen_height / 2.0f) - w;
}

Ray Camera::get_ray(float u, float v) const {
  return Ray(origin, (screen_bottom_left +
                      (u * screen_width + v * screen_height) - origin));
}