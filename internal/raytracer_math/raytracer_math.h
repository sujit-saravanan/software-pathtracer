#pragma once
#include <cmath>
#include <ostream>
#include <concepts>

template<class T>
concept arithmetic = std::is_arithmetic_v<T>;

namespace Raytracer::Math {
        template<arithmetic T>
        struct BasicVec2;
        
        template<arithmetic T>
        struct BasicVec3;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator-(const Raytracer::Math::BasicVec2<T> &lhs, const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
        return {lhs.x - static_cast<T>(rhs.x), lhs.y - static_cast<T>(rhs.y)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator+(const Raytracer::Math::BasicVec2<T> &lhs, const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
        return {lhs.x + static_cast<T>(rhs.x), lhs.y + static_cast<T>(rhs.y)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator*(const Raytracer::Math::BasicVec2<T> &lhs, const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
        return {lhs.x * static_cast<T>(rhs.x), lhs.y * static_cast<T>(rhs.y)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator/(const Raytracer::Math::BasicVec2<T> &lhs, const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
        return {lhs.x / static_cast<T>(rhs.x), lhs.y / static_cast<T>(rhs.y)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator-(const Raytracer::Math::BasicVec2<T> &lhs, T2 rhs) noexcept {
        return {lhs.x - static_cast<T>(rhs), lhs.y - static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator+(const Raytracer::Math::BasicVec2<T> &lhs, T2 rhs) noexcept {
        return {lhs.x + static_cast<T>(rhs), lhs.y + static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator*(const Raytracer::Math::BasicVec2<T> &lhs, T2 rhs) noexcept {
        return {lhs.x * static_cast<T>(rhs), lhs.y * static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator/(const Raytracer::Math::BasicVec2<T> &lhs, T2 rhs) noexcept {
        return {lhs.x / static_cast<T>(rhs), lhs.y / static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator-(T2 lhs, const Raytracer::Math::BasicVec2<T> &rhs) noexcept {
        return rhs - lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator+(T2 lhs, const Raytracer::Math::BasicVec2<T> &rhs) noexcept {
        return rhs + lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator*(T2 lhs, const Raytracer::Math::BasicVec2<T> &rhs) noexcept {
        return rhs * lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec2<T> operator/(T2 lhs, const Raytracer::Math::BasicVec2<T> &rhs) noexcept {
        return rhs / lhs;
}

template<arithmetic T>
std::ostream &operator<<(std::ostream &os, const Raytracer::Math::BasicVec2<T> &rhs) noexcept {
        os << '{' << rhs.x << ", " << rhs.y << "}";
        return os;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator-(const Raytracer::Math::BasicVec3<T> &lhs, const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
        return {lhs.x - static_cast<T>(rhs.x), lhs.y - static_cast<T>(rhs.y), lhs.z - static_cast<T>(rhs.z)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator+(const Raytracer::Math::BasicVec3<T> &lhs, const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
        return {lhs.x + static_cast<T>(rhs.x), lhs.y + static_cast<T>(rhs.y), lhs.z + static_cast<T>(rhs.z)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator*(const Raytracer::Math::BasicVec3<T> &lhs, const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
        return {lhs.x * static_cast<T>(rhs.x), lhs.y * static_cast<T>(rhs.y), lhs.z * static_cast<T>(rhs.z)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator/(const Raytracer::Math::BasicVec3<T> &lhs, const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
        return {lhs.x / static_cast<T>(rhs.x), lhs.y / static_cast<T>(rhs.y), lhs.z / static_cast<T>(rhs.z)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator-(const Raytracer::Math::BasicVec3<T> &lhs, T2 rhs) noexcept {
        return {lhs.x - static_cast<T>(rhs), lhs.y - static_cast<T>(rhs), lhs.z - static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator+(const Raytracer::Math::BasicVec3<T> &lhs, T2 rhs) noexcept {
        return {lhs.x + static_cast<T>(rhs), lhs.y + static_cast<T>(rhs), lhs.z + static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator*(const Raytracer::Math::BasicVec3<T> &lhs, T2 rhs) noexcept {
        return {lhs.x * static_cast<T>(rhs), lhs.y * static_cast<T>(rhs), lhs.z * static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator/(const Raytracer::Math::BasicVec3<T> &lhs, T2 rhs) noexcept {
        return {lhs.x / static_cast<T>(rhs), lhs.y / static_cast<T>(rhs), lhs.z / static_cast<T>(rhs)};
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator-(T2 lhs, const Raytracer::Math::BasicVec3<T> &rhs) noexcept {
        return rhs - lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator+(T2 lhs, const Raytracer::Math::BasicVec3<T> &rhs) noexcept {
        return rhs + lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator*(T2 lhs, const Raytracer::Math::BasicVec3<T> &rhs) noexcept {
        return rhs * lhs;
}

template<arithmetic T, arithmetic T2>
Raytracer::Math::BasicVec3<T> operator/(T2 lhs, const Raytracer::Math::BasicVec3<T> &rhs) noexcept {
        return rhs / lhs;
}

template<arithmetic T>
std::ostream &operator<<(std::ostream &os, const Raytracer::Math::BasicVec3<T> &rhs) noexcept {
        os << '{' << rhs.x << ", " << rhs.y << ", " << rhs.z << "}";
        return os;
}


template<arithmetic T>
struct Raytracer::Math::BasicVec2 {
        BasicVec2() {
                this->x = 0;
                this->y = 0;
        };
        
        template<arithmetic T2, arithmetic T3>
        BasicVec2(T2 x, T3 y) {
                this->x = static_cast<T>(x);
                this->y = static_cast<T>(y);
        };
        
        template<arithmetic T2>
        BasicVec2(T2 value) {
                this->x = static_cast<T>(value);
                this->y = static_cast<T>(value);
        };
        
        template<arithmetic T2>
        BasicVec2(const Raytracer::Math::BasicVec2<T2> &rhs) {
                this->x = static_cast<T>(rhs.x);
                this->y = static_cast<T>(rhs.y);
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator-=(const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
                *this = *this - rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator+=(const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
                *this = *this + rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator*=(const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
                *this = *this * rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator/=(const Raytracer::Math::BasicVec2<T2> &rhs) noexcept {
                *this = *this / rhs;
                return *this;
        }
        
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator-=(T2 rhs) noexcept {
                *this = *this - rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator+=(T2 rhs) noexcept {
                *this = *this + rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator*=(T2 rhs) noexcept {
                *this = *this * rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec2<T> &operator/=(T2 rhs) noexcept {
                *this = *this / rhs;
                return *this;
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type, arithmetic T2>
        [[nodiscard]] RET dot(const Raytracer::Math::BasicVec2<T2> &rhs) const noexcept {
                return (static_cast<RET>(x) * static_cast<RET>(rhs.x)) + (static_cast<RET>(y) * static_cast<RET>(rhs.y));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] RET length() const noexcept {
                return static_cast<RET>(std::sqrt(static_cast<RET>(x) * static_cast<RET>(x) + static_cast<RET>(y) * static_cast<RET>(y)));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] RET squaredLength() const noexcept {
                return (static_cast<RET>(x) * static_cast<RET>(x) + static_cast<RET>(y) * static_cast<RET>(y));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] Raytracer::Math::BasicVec2<RET> normalize() const noexcept {
                auto len = length<RET>();
                return {static_cast<RET>(x) / len, static_cast<RET>(y) / len};
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] Raytracer::Math::BasicVec2<RET> inverse() const noexcept {
                return {static_cast<RET>(1) / static_cast<RET>(x), static_cast<RET>(1) / static_cast<RET>(y)};
        }
        
        union {
                T x{0};
                T r;
        };
        union {
                T y{0};
                T g;
        };
};


template<arithmetic T>
struct Raytracer::Math::BasicVec3 {
        BasicVec3() {
                this->x = 0;
                this->y = 0;
                this->z = 0;
        };
        
        template<arithmetic T2, arithmetic T3, arithmetic T4>
        BasicVec3(T2 x, T3 y, T4 z) {
                this->x = static_cast<T>(x);
                this->y = static_cast<T>(y);
                this->z = static_cast<T>(z);
        };
        
        template<arithmetic T2>
        BasicVec3(T2 value) {
                this->x = static_cast<T>(value);
                this->y = static_cast<T>(value);
                this->z = static_cast<T>(value);
        };
        
        template<arithmetic T2>
        BasicVec3(const Raytracer::Math::BasicVec3<T2> &rhs) {
                this->x = static_cast<T>(rhs.x);
                this->y = static_cast<T>(rhs.y);
                this->z = static_cast<T>(rhs.z);
        }
        
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator-=(const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
                *this = *this - rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator+=(const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
                *this = *this + rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator*=(const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
                *this = *this * rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator/=(const Raytracer::Math::BasicVec3<T2> &rhs) noexcept {
                *this = *this / rhs;
                return *this;
        }
        
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator-=(T2 rhs) noexcept {
                *this = *this - rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator+=(T2 rhs) noexcept {
                *this = *this + rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator*=(T2 rhs) noexcept {
                *this = *this * rhs;
                return *this;
        }
        
        template<arithmetic T2>
        Raytracer::Math::BasicVec3<T> &operator/=(T2 rhs) noexcept {
                *this = *this / rhs;
                return *this;
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type, arithmetic T2>
        [[nodiscard]] RET dot(const Raytracer::Math::BasicVec3<T2> &rhs) const noexcept {
                return (static_cast<RET>(x) * static_cast<RET>(rhs.x)) + (static_cast<RET>(y) * static_cast<RET>(rhs.y)) + (static_cast<RET>(z) * static_cast<RET>(rhs.z));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] RET length() const noexcept {
                return static_cast<RET>(std::sqrt(static_cast<RET>(x) * static_cast<RET>(x) + static_cast<RET>(y) * static_cast<RET>(y) + static_cast<RET>(z) * static_cast<RET>(z)));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] RET squaredLength() const noexcept {
                return (static_cast<RET>(x) * static_cast<RET>(x) + static_cast<RET>(y) * static_cast<RET>(y) + static_cast<RET>(z) * static_cast<RET>(z));
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] Raytracer::Math::BasicVec3<RET> normalize() const noexcept {
                auto len = length<RET>();
                return {static_cast<RET>(x) / len, static_cast<RET>(y) / len, static_cast<RET>(z) / len};
        }
        
        template<std::floating_point RET = std::conditional<std::is_same_v<T, double>, double, float>::type>
        [[nodiscard]] Raytracer::Math::BasicVec3<RET> inverse() const noexcept {
                return {static_cast<RET>(1) / static_cast<RET>(x), static_cast<RET>(1) / static_cast<RET>(y), static_cast<RET>(1) / static_cast<RET>(z)};
        }
        
        template<arithmetic RET = T, arithmetic T2>
        [[nodiscard]] Raytracer::Math::BasicVec3<RET> cross(const Raytracer::Math::BasicVec3<T2> &rhs) const noexcept {
                return {static_cast<RET>(y) * static_cast<RET>(rhs.z) - static_cast<RET>(z) * static_cast<RET>(rhs.y), static_cast<RET>(z) * static_cast<RET>(rhs.x) - static_cast<RET>(x) * static_cast<RET>(rhs.z), static_cast<RET>(x) * static_cast<RET>(rhs.y) - y * static_cast<RET>(rhs.x)};
        }
        
        
        union {
                T x{0};
                T r;
        };
        union {
                T y{0};
                T g;
        };
        union {
                T z{0};
                T b;
        };
};


namespace Raytracer::Math {
        using Vec3 = BasicVec3<float>;
        using Vec3d = BasicVec3<double>;
        using Vec3dd = BasicVec3<long double>;
        using Vec3i = BasicVec3<int32_t>;
        using Vec3i8 = BasicVec3<int8_t>;
        using Vec3i16 = BasicVec3<int16_t>;
        using Vec3i32 = BasicVec3<int32_t>;
        using Vec3i64 = BasicVec3<int64_t>;
        using Vec3u = BasicVec3<uint32_t>;
        using Vec3u8 = BasicVec3<uint8_t>;
        using Vec3u16 = BasicVec3<uint16_t>;
        using Vec3u32 = BasicVec3<uint32_t>;
        using Vec3u64 = BasicVec3<uint64_t>;
        using Vec3b = BasicVec3<bool>;
        
        using Vec2 = BasicVec2<float>;
        using Vec2d = BasicVec2<double>;
        using Vec2dd = BasicVec2<long double>;
        using Vec2i = BasicVec2<int32_t>;
        using Vec2i8 = BasicVec2<int8_t>;
        using Vec2i16 = BasicVec2<int16_t>;
        using Vec2i32 = BasicVec2<int32_t>;
        using Vec2i64 = BasicVec2<int64_t>;
        using Vec2u = BasicVec2<uint32_t>;
        using Vec2u8 = BasicVec2<uint8_t>;
        using Vec2u16 = BasicVec2<uint16_t>;
        using Vec2u32 = BasicVec2<uint32_t>;
        using Vec2u64 = BasicVec2<uint64_t>;
        using Vec2b = BasicVec2<bool>;
        
}