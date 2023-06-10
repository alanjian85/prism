#ifndef PRISM_CORE_COLOR_HPP
#define PRISM_CORE_COLOR_HPP

#include <cassert>
#include <cmath>

#include <config/types.h>

namespace prism {
    struct color {
        __device__ __host__ color(real_t r, real_t g, real_t b)
                                : r(r), g(g), b(b) {
            assert(!has_nans());
        }

        __device__ __host__ bool has_nans() {
            return isnan(r) || isnan(g) || isnan(b);
        }

        real_t r, g, b;
    };
}

#endif // PRISM_CORE_COLOR_HPP
