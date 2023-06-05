#include <cmath>
#include <random>
#include "stb_image_write.h"
#include "raytracer_scene.h"

float intersect(const Raytracer::Shapes::Ray &ray, const Raytracer::Shapes::Shape &shape) {
        return std::visit(overload{
                [ray](std::monostate) {
                        return 0.0f;
                },
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

inline float degreesToRadians(float degrees) {
        return degrees * std::numbers::pi_v<float> / 180.0f;
}

Raytracer::Camera::Camera(const Vec3 &origin, const Vec3 &target, const Vec3 &up_direction, float vertical_fov, float aspect_ratio) {
        float theta = degreesToRadians(vertical_fov);
        float h = tanf(theta/2);
        Vec2 viewport_dimensions = {aspect_ratio * 2.0 * h, 2.0 * h};
        
        auto w = (origin - target).normalize();
        auto u = up_direction.cross(w).normalize();
        auto v = w.cross(u);
        
        m_origin = origin;
        m_horizontal = viewport_dimensions.x * u;
        m_vertical = viewport_dimensions.y * v;
        m_lower_left_corner = m_origin - m_horizontal/2 - m_vertical/2 - w;
}

Ray Raytracer::Camera::getPrimaryRay(const Vec2 &normalized_coordinates) const {
        return Ray(m_origin, m_lower_left_corner + normalized_coordinates.x * m_horizontal + normalized_coordinates.y * m_vertical - m_origin);
}

Shape Raytracer::Scene::traceRay(Ray ray) {
        float closest_hit = std::numeric_limits<float>::max();
        Shape closest_shape;
        for ( const auto& shape : shapes) {
                float hit_distance = intersect(ray, shape);
                if (hit_distance < closest_hit){
                        closest_hit = hit_distance;
                        closest_shape = shape;
                }
        }
        return closest_shape;
}
