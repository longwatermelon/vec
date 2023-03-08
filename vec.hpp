#pragma once
#include <cstddef>
#include <array>
#include <cmath>
#include <string>

template <typename T, size_t N>
struct Vec
{
    template <typename ...Args>
    Vec(Args ...args)
        : data{ args... } {}

    Vec(const std::array<T, N> &data)
        : data(data) {}

    std::array<T, N> data;

    T operator[](int i) const
    {
        return data[i];
    }

    Vec<T, N> operator+(const Vec<T, N> &other) const
    {
        std::array<T, N> arr;
        for (size_t i = 0; i < N; ++i)
            arr[i] = data[i] + other[i];
        return Vec(arr);
    }

    Vec<T, N> operator-(const Vec<T, N> &other) const
    {
        return *this + -other;
    }

    Vec<T, N> operator-() const
    {
        std::array<T, N> arr;
        for (size_t i = 0; i < N; ++i)
            arr[i] = -data[i];
        return Vec(arr);
    }

    Vec<T, N> operator*(T s) const
    {
        std::array<T, N> arr;
        for (size_t i = 0; i < N; ++i)
            arr[i] = data[i] * s;
        return Vec(arr);
    }

    Vec<T, N> operator/(T s) const
    {
        std::array<T, N> arr;
        for (size_t i = 0; i < N; ++i)
            arr[i] = data[i] / s;
        return Vec(arr);
    }

    T dot(const Vec<T, N> &other) const
    {
        T sum = 0;
        for (size_t i = 0; i < N; ++i)
            sum += data[i] * other[i];
        return sum;
    }

    T length() const
    {
        T len = 0;
        for (size_t i = 0; i < N; ++i)
            len += data[i] * data[i];
        return std::sqrt(len);
    }

    Vec<T, N> normalize() const
    {
        return *this / length();
    }

    std::string str() const
    {
        std::string s = "[";
        for (size_t i = 0; i < N; ++i)
            s += std::to_string(data[i]) + (i == N - 1 ? "]" : ", ");
        return s;
    }
};

using vec4 = Vec<float, 4>;
using vec3 = Vec<float, 3>;
using vec2 = Vec<float, 2>;

using ivec4 = Vec<int, 4>;
using ivec3 = Vec<int, 3>;
using ivec2 = Vec<int, 2>;
