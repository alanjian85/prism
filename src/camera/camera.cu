// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: MIT

#include "camera.hpp"

PRISM_CPU_GPU Ray Camera::generateRay(Point2f p) const {
    Ray r;
    Vector3f right = normalize(cross(d, up));
    Vector3f newUp = cross(right, d);
    if (type == CameraType::Persp) {
        right *= tanHalfFov;
        newUp *= tanHalfFov;
        r.o = o;
        r.d = normalize(d + (p.x * 2 - 1) * right + (p.y * 2 - 1) * newUp);
    }
    else {
        r.o = o + (p.x * 2 - 1) * right + (p.y * 2 - 1) * newUp;
        r.d = d;
    }
    return r;
}
