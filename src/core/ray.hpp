// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: MIT

#pragma once

#include "utils.h"
#include "vector.hpp"

struct Ray {
    Ray() = default;

    PRISM_CPU_GPU Ray(Point3f o, Vector3f d) : o(o), d(d) {}

    PRISM_CPU_GPU Vector3f operator()(Real t) const {
        return o + t * d;
    }

    Point3f o;
    Vector3f d;
    Real tMin = ray_default_tmin;
    mutable Real tMax = inf;
};
