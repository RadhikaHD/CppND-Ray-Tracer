#include "constants.h"
#include "ray.h"
#include "types.h"
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "math.h"
#include "sphere.h"

float hitSphere(Ray &r) {

  float a, b, c;

  position const &C = SPHERE_CENTRE;
  position const &A = r.origin();
  position const &B = r.direction();
  float const &R = SPHERE_RADIUS;

  a = glm::dot(B, B);
  b = 2 * glm::dot(B, (A - C));
  c = glm::dot((A - C), (A - C)) - R * R;

  float discriminant = b * b - (4 * a * c);

  if (discriminant >= 0)
    return (-b + sqrt(discriminant))/(2*a);
  else
    return -1.0;
}

bool hitObjects(std::vector<std::unique_ptr<Hittable>> const &hittable_objects, Ray const &r, float const tmin, float const tmax, std::shared_ptr<hit_record> rec)
{

 bool hit_anything = false;
 std::shared_ptr<hit_record> temp_rec = std::make_shared<hit_record>();
 float closest_so_far = tmax;

 for (auto &hittable_object: hittable_objects)
 {
     if (hittable_object->hit(r, tmin, closest_so_far, temp_rec))
     {
        hit_anything = true;
        closest_so_far = temp_rec->t;
        rec = temp_rec;
     }
 }

 return hit_anything;
}

rgb color(Ray &r, std::vector<std::unique_ptr<Hittable>> const &objects) {

    auto hit_rec = std::make_shared <hit_record>(); 
    //constructs a hit record with space allocated, returns a shared pointer to it 
    auto hitornot = hitObjects(objects, r, TMIN, TMAX, hit_rec);
    
  if (hitornot)
    return (0.5f*rgb(hit_rec->normal.x+1, hit_rec->normal.y+1, hit_rec->normal.z+1));
  else {
    position unit_vector = glm::normalize(r.direction());
    float t = 0.5 * (unit_vector.y + 1);
    rgb gradient = (1 - t) * (LIGHT_BLUE) + t * (WHITE);
    return gradient;
  }
}
/*
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
        glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f
/ 3.0f, 0.1f, 100.f); glm::mat4 View = glm::translate(glm::mat4(1.0f),
glm::vec3(0.0f, 0.0f, -Translate)); View = glm::rotate(View, Rotate.y,
glm::vec3(-1.0f, 0.0f, 0.0f)); View = glm::rotate(View, Rotate.x,
glm::vec3(0.0f, 1.0f, 0.0f)); glm::mat4 Model = glm::scale(glm::mat4(1.0f),
glm::vec3(0.5f)); return Projection * View * Model;
}
*/

rgb256 rgbToRgb256(rgb const &rgbval) {
  int red, blue, green;
  red = (rgbval.x) * 255.99;
  blue = (rgbval.y) * 255.99;
  green = (rgbval.z) * 255.99;
  rgb256 rgb256val(red, blue, green);
  return rgb256val;
}

void writeToPPM(std::string filename, std::vector<std::unique_ptr<Hittable>> const &objects) {
  std::ofstream toppm;
  toppm.open(filename);
  toppm << "P3\n";
  toppm << NCOLS << " " << NROWS << "\n"; // columns and rows
  toppm << 255 << "\n";
  float x, y;

  for (int r = 0; r < NROWS; r++) {
    for (int c = 0; c < NCOLS; c++) {
      x = (SCREEN_WIDTH / NCOLS) * c;
      y = (SCREEN_HEIGHT / NROWS) * r;
      position rdirection((SCREEN_BOTTOM_LEFT.x + x),
                          (SCREEN_BOTTOM_LEFT.y + y), SCREEN_Z_POS);
      Ray ray(CAMERA, rdirection);
      rgb pixel_color = color(ray,objects);
      rgb256 pixel_color_256 = rgbToRgb256(pixel_color);
      toppm << pixel_color_256.x << " " << pixel_color_256.y << " "
            << pixel_color_256.z << " ";
    }
    toppm << "\n";
  }
  toppm.close();
}

int main() {
std::vector<std::unique_ptr<Hittable>> objects;
objects.emplace_back(std::make_unique<Sphere>(SPHERE_RADIUS, SPHERE_CENTRE));
objects.emplace_back(std::make_unique<Sphere>(100, position (0,-100.5,-1)));


  writeToPPM("output.ppm", objects);
  return 0;
}