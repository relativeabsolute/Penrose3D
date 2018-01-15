#ifndef PENROSE_VECTOR_HPP
#define PENROSE_VECTOR_HPP

#include <array>

namespace Penrose::Math {
    template<class T, std::size_t N>
    class Vector {
        public:
            Vector();
            Vector(std::array<T, N> new_members);

            constexpr T& operator[](size_t index);
            constexpr const T& operator[](size_t index) const;
            
            Vector<T, N> operator+(const Vector<T, N>& other) const;
            void operator+=(const Vector<T, N>& other);
            
            Vector<T, N> operator-(const Vector<T, N>& other) const;
            void operator-=(const Vector<T, N>& other);

            Vector<T, N> operator*(T scalar) const;
            void operator*=(T scalar);

            T dot(const Vector<T, N>& other) const;

        private:
            std::array<T, N> data_members;
    };

    template<class T>
    Vector<T, 3> cross(const Vector<T, 3>& first, const Vector<T, 3>& second);

}

#endif
