#pragma once


#include <variant>
#include "raytracer_math.h"

namespace Raytracer::Shapes {
        struct Sphere;
        struct Cube;
        struct Prism;
        struct Ray;
}



struct Raytracer::Shapes::Sphere {
        Raytracer::Math::Vec3 center;
        float radius{0};
};

struct Raytracer::Shapes::Cube {
        Raytracer::Math::Vec3 center;
        float side{0};
};


struct Raytracer::Shapes::Prism {
        Raytracer::Math::Vec3 center;
        Raytracer::Math::Vec3 dimensions;
};


struct Raytracer::Shapes::Ray {
        [[nodiscard]] Raytracer::Math::Vec3 at(float t) const noexcept;

        Raytracer::Math::Vec3 origin;
        Raytracer::Math::Vec3 direction;
};


namespace Raytracer::Shapes {
        using Shape = std::variant<Sphere, Cube, Prism>;
}