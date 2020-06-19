#include "sphere.h"
#include <glm/glm.hpp>

bool Sphere::hit(Ray const &r, float const tmin, float const tmax,
                 std::shared_ptr<hit_record> &rec) {
  float a, b, c;

  position const &C = center;
  position const &A = r.origin();
  position const &B = r.direction();
  float const &R = radius;

  a = glm::dot(B, B);
  b = 2 * glm::dot(B, (A - C));
  c = glm::dot((A - C), (A - C)) - R * R;

  float discriminant = b * b - (4 * a * c);
  if (discriminant > 0) {
    float t = (-b - sqrt(discriminant)) / (2 * a);
    if ((t > tmin) && (t < tmax)) {
      rec->t = t;
      rec->point_where_hit = r.pointAtParameter(t);
      rec->normal = glm::normalize(rec->point_where_hit - center);
      return true;
    }
    t = (-b + sqrt(discriminant)) / (2 * a);
    if ((t > tmin) && (t < tmax)) {
      rec->t = t;
      rec->point_where_hit = r.pointAtParameter(t);
      rec->normal = glm::normalize(rec->point_where_hit - center);
      return true;
    }
  }

  return false;
}