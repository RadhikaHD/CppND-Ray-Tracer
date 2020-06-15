#pragma once

#include "types.h"
#include "ray.h"
#include <memory>

struct hit_record
{
    float t;
    position point_where_hit;
    position normal;
};


class Hittable
{
    public:
    virtual bool hit(Ray const &r, float const tmin, float const tmax, std::shared_ptr<hit_record> rec)=0;
};