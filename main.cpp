#include "camera.h"
#include "constants.h"
#include "math.h"
#include "ray.h"
#include "sphere.h"
#include "types.h"
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// get_random() function from here https://stackoverflow.com/a/36527160
float get_random() {
  static std::default_random_engine e;
  static std::uniform_real_distribution<> dis(0, 1); // range 0 - 1
  return dis(e);
}

position randomInUnitCube() {
  position p;
  do {
    p = 2.0f * (position(get_random(), get_random(), get_random())) -
        position(1.0, 1.0, 1.0);
  } while (std::pow(glm::length(p), 2) >= 1.0);
  return p;
}

bool hitObjects(std::vector<std::unique_ptr<Hittable>> const &hittable_objects,
                Ray const &r, float const tmin, float const tmax,
                std::shared_ptr<hit_record> &rec) {

  bool hit_anything = false;
  std::shared_ptr<hit_record> temp_rec = std::make_shared<hit_record>();
  float closest_so_far = tmax;

  for (auto &hittable_object : hittable_objects) {
    if (hittable_object->hit(r, tmin, closest_so_far, temp_rec)) {
      if (temp_rec->t > 0) {
        hit_anything = true;
        closest_so_far = temp_rec->t;
        rec = temp_rec;
      }
    }
  }

  return hit_anything;
}

rgb color(Ray &r, std::vector<std::unique_ptr<Hittable>> const &objects) {

  auto hit_rec = std::make_shared<hit_record>();
  // constructs a hit record with space allocated, returns a shared pointer to
  // it
  auto hitornot = hitObjects(objects, r, TMIN, TMAX, hit_rec);

  rgb current_color;

  if (hitornot) {
    position target =
        hit_rec->point_where_hit + hit_rec->normal + randomInUnitCube();
    Ray current_ray(hit_rec->point_where_hit,
                    (target - hit_rec->point_where_hit));
    current_color = 0.5f * color(current_ray, objects);
  } else {
    position unit_vector = glm::normalize(r.direction());
    float t = 0.5 * (unit_vector.y + 1);
    current_color = (1 - t) * (WHITE) + t * (LIGHT_BLUE);
  }

  return (current_color);
}

rgb256 rgbToRgb256(rgb const &rgbval) {
  int red, blue, green;
  red = (rgbval.x) * 255.99;
  blue = (rgbval.y) * 255.99;
  green = (rgbval.z) * 255.99;
  rgb256 rgb256val(red, blue, green);
  return rgb256val;
}

void writeToPPM(std::string filename,
                std::vector<std::unique_ptr<Hittable>> const &objects,
                Camera const &cam) {
  std::ofstream toppm;
  toppm.open(filename);
  toppm << "P3\n";
  toppm << NCOLS << " " << NROWS << "\n"; // columns and rows
  toppm << 255 << "\n";
  float u, v;
  int num_samples = 100;

  for (int r = (NROWS - 1); r >= 0; r--) {
    for (int c = 0; c < NCOLS; c++) {
      rgb pixel_color{0, 0, 0};
      for (int n = 0; n < num_samples; n++) {
        u = (1.0f / (NCOLS - 1)) * (c + get_random());
        v = (1.0f / (NROWS - 1)) * (r + get_random());

        Ray ray = cam.get_ray(u, v);
        pixel_color += color(ray, objects);
      }
      pixel_color /= num_samples;
      rgb256 pixel_color_256 = rgbToRgb256(pixel_color);
      toppm << pixel_color_256.x << " " << pixel_color_256.y << " "
            << pixel_color_256.z << " ";
    }
    toppm << "\n";
  }
  toppm.close();
}

int main() {
  Camera main_cam(position(-2, 2, 1), position(0, 0, -1), position(0, 1, 0), 90,
                  ASPECT_RATIO);

  std::vector<std::unique_ptr<Hittable>> objects;

  objects.emplace_back(
      std::make_unique<Sphere>(500, position(0.0f, -500.5f, -1.0f)));

  objects.emplace_back(
      std::make_unique<Sphere>(1.5, position(3.0f, 1.0f, -3.0f)));
  objects.emplace_back(
      std::make_unique<Sphere>(0.8, position(0.0f, 0.3f, -2.5f)));
  objects.emplace_back(
      std::make_unique<Sphere>(0.5, position(-1, 0.0f, -1.0f)));
  objects.emplace_back(
      std::make_unique<Sphere>(0.5, position(2.0f, 0.0f, 0.0f)));

  writeToPPM("output.ppm", objects, main_cam);
  return 0;
}