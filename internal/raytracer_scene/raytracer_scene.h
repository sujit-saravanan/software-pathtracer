#pragma once
#include <thread>
#include <vector>
#include "bs_thread_pool.h"
#include "raytracer_shapes.h"

namespace Raytracer {
        struct Scene;
        struct Camera;
}

struct Raytracer::Scene {
        std::vector<Raytracer::Shapes::Shape> shapes;
};