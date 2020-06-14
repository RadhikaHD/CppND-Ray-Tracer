#include "constants.h"
#include "ray.h"
#include "types.h"
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "math.h"

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

rgb color(Ray &r) {
    auto ray_t = hitSphere(r);
  if (ray_t>0)
  {
    //calculate normal
    position normal = glm::normalize(r.pointAtParameter(ray_t)-SPHERE_CENTRE);
    return (0.5f*rgb(normal.x+1, normal.y+1, normal.z+1));

    //get color from normal
  }
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

void writeToPPM(std::string filename) {
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
      rgb pixel_color = color(ray);
      rgb256 pixel_color_256 = rgbToRgb256(pixel_color);
      toppm << pixel_color_256.x << " " << pixel_color_256.y << " "
            << pixel_color_256.z << " ";
    }
    toppm << "\n";
  }
  toppm.close();
}

int main() {
  writeToPPM("output.ppm");
  return 0;
}