// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: MIT

#ifndef PRISM_SHAPES_TRIANGLE_HPP
#define PRISM_SHAPES_TRIANGLE_HPP

#include <config/types.h>
#include <core/vector.hpp>

#include "shape.hpp"

namespace prism {
    class triangle : public shape {
    public:
        PRISM_CPU_GPU triangle(point3f a, point3f b, point3f c)
                          : a(a), b(b), c(c)
        {
            n = normalize(cross(b - a, c - a));
        }

        PRISM_CPU_GPU bool intersect(const ray &r, interaction &i) const override {
            point3f ap = a - r.o;
            point3f bp = b - r.o;
            point3f cp = c - r.o;
            int z = r.d.max_dim();
            int x = (z + 1) % 3, y = (z + 2) % 3;
            ap = permute(ap, x, y, z);
            bp = permute(bp, x, y, z);
            cp = permute(cp, x, y, z);
            real_t iz = 1 / r.d.z;
            ap.z *= iz;
            ap.x -= r.d.x * ap.z;
            ap.y -= r.d.y * ap.z;
            bp.z *= iz;
            bp.x -= r.d.x * bp.z;
            bp.y -= r.d.y * bp.z;
            cp.z *= iz;
            cp.x -= r.d.x * cp.z;
            cp.y -= r.d.y * cp.z;
            real_t a0 = ap.x * bp.y - ap.y * bp.x;
            real_t a1 = bp.x * cp.y - bp.y * cp.x;
            real_t a2 = cp.x * ap.y - cp.y * ap.x;
            if (a0 > 0 && a1 > 0 && a2 > 0) {
                i.n = n;
                return true;
            }
            return false;
        }

    private:
        point3f a, b, c;
        vector3f n;
    };
}

#endif // PRISM_SHAPES_TRIANGLE_HPP
