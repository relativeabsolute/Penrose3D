#include <Penrose_Vector.hpp>

namespace Penrose::Math {

    template<class T, std::size_t N>
    Vector<T, N>::Vector() {
    }

    template<class T, std::size_t N>
    Vector<T, N>::Vector(std::array<T, N> new_members)
        : data_members(new_members) {

    }

    template<class T, std::size_t N>
    constexpr T& Vector<T, N>::operator[](size_t index) {
        return data_members[index];
    }

    template<class T, std::size_t N>
    constexpr const T& Vector<T, N>::operator[](size_t index) const {
        return data_members[index];
    }

    template<class T, std::size_t N>
    Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& other) const {
        Vector<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = data_members[i] + other[i];
        }
        return result;
    }

    template<class T, std::size_t N>
    void Vector<T, N>::operator+=(const Vector<T, N>& other) {
        for (size_t i = 0; i < N; i++) {
            data_members[i] += other[i];
        }
    }

    template<class T, std::size_t N>
    Vector<T, N> Vector<T, N>::operator*(T scalar) const {
        Vector<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = data_members[i] * scalar;
        }
        return result;
    }

    template<class T, std::size_t N>
    void Vector<T, N>::operator*=(T scalar) {
        for (size_t i = 0; i < N; i++) {
            data_members[i] *= scalar;
        }
    }
    template<class T, std::size_t N>
    void Vector<T, N>::operator-=(const Vector<T, N>& other) {
        for (size_t i = 0; i < N; i++) {
            data_members[i] -= other[i];
        }
    }


    template<class T, std::size_t N>
    Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& other) const {
        Vector<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = data_members[i] - other[i];
        }
        return result;
    }

    template<class T, std::size_t N>
    T Vector<T, N>::dot(const Vector<T, N>& other) const {
        T result = (T)0;
        for (size_t i = 0; i < N; i++) {
            result += data_members[i] * other[i];
        }
        return result;
    }

    template<class T>
    Vector<T, 3> cross(const Vector<T, 3>& first, const Vector<T, 3>& second) {
        Vector<T, 3> result {{
            first[1] * second[2] - first[2] * second[1],
            first[2] * second[0] - first[0] * second[2],
            first[0] * second[1] - first[1] * second[0]
        }};

        return result;
    }
}
