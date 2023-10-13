#ifndef MATHLIB_IMPL_TRANSFORM3_HPP
#define MATHLIB_IMPL_TRANSFORM3_HPP

#include "Matrix4.hpp"

namespace Math
{
    template <typename T>
    class Transform3T final
    {
    public:
        using ScalarType = T;
        using MatrixType = Matrix4T<T>;
        static constexpr SizeType Dimension = 3;

        constexpr explicit Transform3T() noexcept
            : rows({})
        {}

        constexpr explicit Transform3T(T diag) noexcept
            : rows({})
        {
            for (SizeType i = 0; i < 3; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Transform3T(const Vector3T<T>& row0,
                                       const Vector3T<T>& row1,
                                       const Vector3T<T>& row2)
        noexcept
            : rows({ Vector4T<T>(row0),
                     Vector4T<T>(row1),
                     Vector4T<T>(row2) })
        {}

        constexpr explicit Transform3T(const Vector4T<T>& row0,
                                       const Vector4T<T>& row1,
                                       const Vector4T<T>& row2)
        noexcept
            : rows({ row0,
                     row1,
                     row2 })
        {}

        constexpr explicit Transform3T(T m00, T m01, T m02, T m03,
                                       T m10, T m11, T m12, T m13,
                                       T m20, T m21, T m22, T m23)
        noexcept
            : rows({{ {m00, m01, m02, m03},
                      {m10, m11, m12, m13},
                      {m20, m21, m22, m23} }})
        {}

        constexpr       Vector4T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector4T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr const Matrix4T<T> ToMatrix() const noexcept
        {
            return Matrix4T<T>( rows[0], rows[1], rows[2], { 0, 0, 0, 1 } );
        }
    private:
        // Fourth row is implicit { 0, 0, 0, 1 }
        Array<Vector4T<T>, 3> rows;
    };
}

#endif //MATHLIB_IMPL_TRANSFORM3_HPP
