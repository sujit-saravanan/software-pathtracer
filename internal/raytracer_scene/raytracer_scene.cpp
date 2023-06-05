#include <cmath>
#include <random>
#include "raytracer_scene.h"

template<class... Ts>
struct overload : Ts ... {
        using Ts::operator()...;
};

float intersect(const Raytracer::Shapes::Ray &ray, const Raytracer::Shapes::Shape &shape) {
        return std::visit(overload{
                [ray](const Raytracer::Shapes::Sphere &sphere) {
                        Raytracer::Math::Vec2 t;
                        Raytracer::Math::Vec3 L = ray.origin - sphere.center;
                        float a = ray.direction.dot(ray.direction);
                        float b = 2 * ray.direction.dot(L);
                        float c = L.dot(L) - (sphere.radius * sphere.radius);
                        float discriminant = b * b - 4 * a * c;

                        if (discriminant < 0) return std::numeric_limits<float>::max();
                        else if (discriminant == 0) t = -0.5f * b / a;
                        else {
                                float q = (b > 0) ? -0.5f * (b + std::sqrt(discriminant)) : -0.5f * (b - std::sqrt(discriminant));
                                t = {q / a, c / q};
                        }

                        if (t.x > t.y) std::swap(t.x, t.y);

                        if (t.x < 0) {
                                t.x = t.y;
                                if (t.y < 0) return std::numeric_limits<float>::max();
                        }

                        return t.x;
                },
                [ray](const Raytracer::Shapes::Cube &cube) {
                        return 0.0f;
                },
                [ray](const Raytracer::Shapes::Prism &prism) {
                        return 0.0f;
                }
        }, shape);
}

float degrees_to_radians(float degrees) {
        return degrees * std::numbers::pi_v<float> / 180.0f;
}

Raytracer::Camera::Camera(const Raytracer::Math::Vec3 &look_from,
                          const Raytracer::Math::Vec3 &look_at,
                          const Raytracer::Math::Vec3 &v_up,
                          float v_fov, float aspect_ratio, float aperture, float focus_distance) {
        float theta = degrees_to_radians(v_fov);
        float h = std::tan(theta/2.0f);
        float viewport_height = 2.0f * h;
        float viewport_width = aspect_ratio * viewport_height;

        m_w = (look_from - look_at).normalize();
        m_u = v_up.cross(m_w);
        m_v = m_w.cross(m_u);

        m_origin = look_from;
        m_horizontal = focus_distance * viewport_width * m_u;
        m_vertical = focus_distance * viewport_height * m_v;
        m_lower_left_corner = m_origin - m_horizontal/2.0f - m_vertical/2.0f - focus_distance*m_w;

        m_lens_radius = aperture / 2.0f;
}

inline float random_float() {
        static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
        static std::mt19937 generator;
        return distribution(generator);
}

inline float random_float(float min, float max) {
        return min + (max-min)*random_float();
}

Raytracer::Math::Vec3 randomInUnitDisk() {
        while (true) {
                auto p = Raytracer::Math::Vec3(random_float(-1,1), random_float(-1,1), 0);
                if (p.squaredLength() >= 1) continue;
                return p;
        }
}

Raytracer::Shapes::Ray Raytracer::Camera::getRay(Raytracer::Math::Vec2 screenspace_coordinates) const {
        Raytracer::Math::Vec3 rd = m_lens_radius * randomInUnitDisk();
        Raytracer::Math::Vec3 offset = m_u * rd.x + m_v * rd.y;
        return {
                m_origin + offset,
                m_lower_left_corner + screenspace_coordinates.x * m_horizontal + screenspace_coordinates.y * m_vertical - m_origin - offset
        };
}

void Raytracer::Camera::fire_primary_rays(const Raytracer::Scene &scene, const Math::Vec2u &image_resolution) {
        for (uint32_t x = 0; x < image_resolution.x; x++) {
                for (uint32_t y = 0; y < image_resolution.y; x++) {
                        std::cout << "(" << x << ", " << y << "): "  << getRay({x, y}).direction << "\n";
                }
        }
}




