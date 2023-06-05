#pragma once
#include <thread>
#include <vector>
#include "bs_thread_pool.h"
#include "raytracer_shapes.h"

namespace Raytracer {
        struct Scene;
        struct Camera;
}

class Raytracer::Camera {
public: // Constructors/Destructors/Overloads
        Camera(const Math::Vec3 &look_from, const Math::Vec3 &look_at, const Math::Vec3 &v_up, float v_fov, float aspect_ratio, float aperture, float focus_distance);

public: // Public Member Functions
public: // Public Member Variables
        Shapes::Ray getRay(Math::Vec2 screenspace_coordinates) const;
        void fire_primary_rays(const Raytracer::Scene& scene, const Math::Vec2u &image_resolution);

private: // Private Member Functions
private: // Private Member Variables
        Math::Vec3 m_origin;
        Math::Vec3 m_lower_left_corner;
        Math::Vec3 m_horizontal;
        Math::Vec3 m_vertical;
        Math::Vec3 m_u, m_v, m_w;
        float m_lens_radius;

        BS::thread_pool m_thread_pool;
};


struct Raytracer::Scene {
        std::vector<Raytracer::Shapes::Shape> shapes;
};