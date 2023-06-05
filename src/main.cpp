#include <iostream>

#include "raytracer_math.h"
#include "raytracer_shapes.h"

//template<class... Ts>
//struct overload : Ts ... {
//        using Ts::operator()...;
//};

//float intersect(const Raytracer::Shapes::Ray &ray, const Raytracer::Shapes::Shape &shape) {
//        return std::visit(overload{
//                [ray](const Raytracer::Shapes::Sphere &sphere) {
//                        Raytracer::Math::Vec2 t;
//                        Raytracer::Math::Vec3 L = ray.origin - sphere.center;
//                        float a = ray.direction.dot(ray.direction);
//                        float b = 2 * ray.direction.dot(L);
//                        float c = L.dot(L) - (sphere.radius * sphere.radius);
//                        float discriminant = b * b - 4 * a * c;
//
//                        if (discriminant < 0) return std::numeric_limits<float>::max();
//                        else if (discriminant == 0) t = -0.5f * b / a;
//                        else {
//                                float q = (b > 0) ? -0.5f * (b + std::sqrt(discriminant)) : -0.5f * (b - std::sqrt(discriminant));
//                                t = {q / a, c / q};
//                        }
//
//                        if (t.x > t.y) std::swap(t.x, t.y);
//
//                        if (t.x < 0) {
//                                t.x = t.y;
//                                if (t.y < 0) return std::numeric_limits<float>::max();
//                        }
//
//                        return t.x;
//                },
//                [ray](const Raytracer::Shapes::Cube &cube) {
//                        return 0.0f;
//                },
//                [ray](const Raytracer::Shapes::Prism &prism) {
//                        return 0.0f;
//                }
//        }, shape);
//}

using namespace Raytracer::Math;

int main(int argc, char *argv[]) {
        Vec3i first{1, 2, 3};
        
        Vec3i second{1, 5, 7};
        Vec3 fourth = second;
        
        Vec3 third = {1.2, 2, 3};
        third = 2;
        
        std::cout << first << "\n";
        std::cout << third << "\n";
        std::cout << third.normalize() << "\n";
        std::cout << fourth << "\n";


//        std::vector<Raytracer::Shapes::Shape> shapes;
//        shapes.emplace_back(Raytracer::Shapes::Sphere{{0, 4, 0}, 1.2});
//        shapes.emplace_back(Raytracer::Shapes::Sphere{{0, 5, 0}, 1.2});
//        shapes.emplace_back(Raytracer::Shapes::Sphere{{0, 6, 0}, 1.2});
//
//        Raytracer::Shapes::Ray ray = {{0.1, 0, 0},{0, 1, 0}};
//        for (const auto& shape: shapes) {
//                auto intersection_point = ray.at(intersect(ray, shape));
//                std::cout << intersection_point << "\n";
//        }
//
        
        
        
        
        return 0;
}