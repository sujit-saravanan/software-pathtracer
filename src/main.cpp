#include <iostream>
#include <random>

#include "raytracer_shapes.h"
#include "stb_image_write.h"
#include "raytracer_scene.h"

using namespace Raytracer::Math;
using namespace Raytracer::Shapes;
using namespace Raytracer;

struct Color {
        uint8_t r, g, b, a;
};

inline float random_float() {
        static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
        static std::mt19937 generator;
        return distribution(generator);
}

inline float random_float(float min, float max) {
        return min + (max - min) * random_float();
}

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
Vec3u8 color(const Raytracer::Shapes::Shape &shape) {
        return std::visit(overload{
                [](const Raytracer::Shapes::Sphere &sphere) {
                        return sphere.color;
                },
                [](const Raytracer::Shapes::Cube &cube) {
                        return cube.color;
                },
                [](const Raytracer::Shapes::Prism &prism) {
                        return prism.color;
                }
        }, shape);
}

Raytracer::Math::Vec3 randomInUnitDisk() {
        while (true) {
                auto p = Raytracer::Math::Vec3(random_float(-1, 1), random_float(-1, 1), 0);
                if (p.squaredLength() >= 1) continue;
                return p;
        }
}

int main(int argc, char *argv[]) {
        const auto aspect_ratio = 16.0 / 9.0;
        const int image_width = 160;
        const int image_height = static_cast<int>(image_width / aspect_ratio);
        uint8_t samples_per_pixel = 100;
        
        auto viewport_height = 2.0;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;
        
        auto origin = Vec3(0, 0, 0);
        auto horizontal = Vec3(viewport_width, 0, 0);
        auto vertical = Vec3(0, viewport_height, 0);
        auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);
        
        
        auto *image = static_cast<Color*>(aligned_alloc(64, image_width * image_height * 4));
        Scene scene;
        scene.shapes.emplace_back(Sphere({0, 0, -1}, 0.5, {255, 0, 0}));
        scene.shapes.emplace_back(Sphere({0.5, 0, -1}, 0.5, {255, 0, 255}));
        
        for (int j = image_height-1; j >= 0; --j) {
                for (int i = 0; i < image_width; ++i) {
                        Vec3u rgb = {0, 0, 0};
                        for (int s = 0; s < samples_per_pixel; s++){
                                Vec2 local = {float(float(i) + random_float()) / float(image_width-1), float(float(j) + random_float()) / float(image_height-1)};
                                Ray r(origin, lower_left_corner + local.x*horizontal + local.y*vertical - origin);
                                
                                float closest_hit = std::numeric_limits<float>::max();
                                Shape closest_shape = scene.shapes[0];
                                for ( const auto& shape : scene.shapes) {
                                        float hit_distance = intersect(r, shape);
                                        if (hit_distance < closest_hit){
                                                closest_hit = hit_distance;
                                                closest_shape = shape;
                                        }
                                }
                                
                                if (closest_hit < std::numeric_limits<float>::max())
                                        rgb += color(closest_shape);
                                else
                                        rgb += Vec3u{0, 0, 0};
                        }
                        image[j * image_width + i] = {static_cast<uint8_t>(rgb.r / samples_per_pixel), static_cast<uint8_t>(rgb.g / samples_per_pixel), static_cast<uint8_t>(rgb.b / samples_per_pixel), 255};
                }
        }
        stbi_write_png("assets/output.png", image_width, image_height, 4, image, 4 * image_width);
        
        return 0;
}