#ifndef MATHLIB_IMPL_TRANSFORM2_HPP
#define MATHLIB_IMPL_TRANSFORM2_HPP

#include "Matrix3.hpp"

#include <array>

namespace Math
{
    template <typename T>
    class Transform2T final
    {
    public:
        using ScalarType = T;
        using MatrixType = Matrix3T<T>;
        static constexpr SizeType Dimension = 2;

        constexpr explicit Transform2T() noexcept
            : rows({})
        {}

        constexpr explicit Transform2T(T diag) noexcept
            : rows({})
        {
            for (SizeType i = 0; i < 2; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Transform2T(const Vector2T<T>& row0,
                                       const Vector2T<T>& row1)
        noexcept
            : rows({ Vector3T<T>(row0),
                     Vector3T<T>(row1) })
        {}

        constexpr explicit Transform2T(const Vector3T<T>& row0,
                                       const Vector3T<T>& row1)
        noexcept
            : rows({ row0,
                     row1 })
        {}

        constexpr explicit Transform2T(T m00, T m01, T m02,
                                       T m10, T m11, T m12)
        noexcept
            : rows({{ {m00, m01, m02},
                      {m10, m11, m12} }})
        {}

        constexpr       Vector3T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector3T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr const Matrix3T<T> ToMatrix() const noexcept
        {
            return Matrix3T<T>( rows[0], rows[1], { 0, 0, 1 } );
        }
    private:
        // Third row is implicit { 0, 0, 1 }
        std::array<Vector3T<T>, 2> rows;
    };
}

#endif //MATHLIB_IMPL_TRANSFORM2_HPP
