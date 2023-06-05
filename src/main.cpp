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

Vec3u8 color(const Raytracer::Shapes::Shape &shape) {
        return std::visit(overload{
                [](std::monostate) {
                        return Vec3u8{0, 0, 0};
                },
                [](auto & shape) {
                        return shape.color;
                }
        }, shape);
}


int main(int argc, char *argv[]) {
        const float aspect_ratio = 16.0f / 9.0f;
        const int image_width = 1600;
        const int image_height = static_cast<int>(image_width / aspect_ratio);
        uint8_t samples_per_pixel = 100;
        
        Camera camera({0, 0, 0}, {0, 0, -1}, {0, 1, 0}, 90, aspect_ratio);
        
        auto *image = static_cast<Color*>(aligned_alloc(64, image_width * image_height * 4));
        Scene scene;
        scene.shapes.emplace_back(Sphere({0, 0, -1}, 0.5, {255, 0, 0}));
        scene.shapes.emplace_back(Sphere({0.5, 0, -1}, 0.5, {255, 0, 255}));
        
        for (int j = image_height-1; j >= 0; --j) {
                for (int i = 0; i < image_width; ++i) {
                        Vec3u rgb = {0, 0, 0};
                        for (int s = 0; s < samples_per_pixel; s++){
                                Vec2 local = {float(i) / float(image_width-1), float(j) / float(image_height-1)};
                                Ray ray = camera.getPrimaryRay(local);
                                
                                Shape closest_shape = scene.traceRay(ray);
                                rgb += color(closest_shape);
                        }
                        image[j * image_width + i] = {static_cast<uint8_t>(rgb.r / samples_per_pixel), static_cast<uint8_t>(rgb.g / samples_per_pixel), static_cast<uint8_t>(rgb.b / samples_per_pixel), 255};
                }
        }
        stbi_write_png("assets/output.png", image_width, image_height, 4, image, 4 * image_width);
        
        return 0;
}