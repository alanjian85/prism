// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: MIT

#ifndef PRISM_SCENE_SCENE_HPP
#define PRISM_SCENE_SCENE_HPP

#include <cstddef>

#include "bvh.hpp"

struct Scene {
public:
    PRISM_CPU Scene(std::vector<Triangle> &primitives) : bvh(primitives) {}

    PRISM_CPU static void *operator new(std::size_t count) {
        Scene *ptr;
        cudaMallocManaged(&ptr, count);
        return ptr;
    }

    PRISM_CPU static void operator delete(void *ptr) {
        cudaFree(ptr);
    }

    PRISM_GPU bool intersect(const Ray &ray, Interaction &interaction) const {
        return bvh.intersect(ray, interaction);
    }

private:
    BVH bvh;
};

#endif // PRISM_SCENE_SCENE_HPP