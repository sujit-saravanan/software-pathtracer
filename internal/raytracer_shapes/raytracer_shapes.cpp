#include "raytracer_shapes.h"

Raytracer::Math::Vec3 Raytracer::Shapes::Ray::at(float t) const noexcept {
        return origin + direction * t;
}
