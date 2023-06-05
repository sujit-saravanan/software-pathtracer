#pragma once
#include <thread>
#include <vector>
#include "bs_thread_pool.h"
#include "raytracer_shapes.h"

template<class... Ts>
struct overload : Ts ... {
        using Ts::operator()...;
};

using namespace Raytracer::Math;
using namespace Raytracer::Shapes;
namespace Raytracer {
        struct Scene;
        struct Camera;
}

struct Raytracer::Camera {
        Camera(const Vec3 &origin, const Vec3 &target, const Vec3 &up_direction, float vertical_fov, float aspect_ratio);
        
        [[nodiscard]] Ray getPrimaryRay(const Vec2 &normalized_coordinates) const;
        
        Vec3 m_origin;
        Vec3 m_lower_left_corner;
        Vec3 m_horizontal;
        Vec3 m_vertical;
};

struct Raytracer::Scene {
        std::vector<Raytracer::Shapes::Shape> shapes;
        
        Shape traceRay(Ray ray);
};