#ifndef MATHLIB_IMPLEMENTATION_TRANSFORM_OPERATORS_HPP
#define MATHLIB_IMPLEMENTATION_TRANSFORM_OPERATORS_HPP

#include "Base/Concepts.hpp"
#include "Math/Implementation/Base/Types.hpp"
#include "MatrixOperators.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Transform-Transform operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicTransform Transform>
    [[nodiscard]] constexpr
    Transform operator* (const Transform& t1, const Transform& t2) noexcept
    {
        Transform result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension + 1; ++j)
            {
                for (SizeType k = 0; k < Transform::Dimension; ++k)
                {
                    result[i][j] += t1[i][k] * t2[k][j];
                }

                if (j == Transform::Dimension)
                {
                    result[i][j] += t1[i][j];
                }
            }
        }
        return result;
    }

    template <Concept::BasicTransform Transform>
    [[maybe_unused]] constexpr
    Transform& operator*= (Transform& t1, const Transform& t2) noexcept
    {
        t1 = t1 * t2;
        return t1;
    }

    //////////////////////////////////////////////////////////////////////////
    // Transform-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicTransform Transform, Concept::BasicVector Vec>
        requires (Transform::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Transform& t, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += t[i][j] * v[j];
            }
        }
        return result;
    }

    template <Concept::BasicTransform Transform, Concept::BasicVector Vec>
        requires (Transform::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Vec& v, const Transform& t) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += v[j] * t[j][i];
            }
        }
        return result;
    }

    template <Concept::BasicTransform Transform, Concept::BasicVector Vec>
        requires (Transform::Dimension + 1 == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Transform& t, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Vec::Dimension; ++j)
            {
                result[i] += t[i][j] * v[j];
            }
        }
        for (SizeType i = 0; i <= Transform::Dimension; ++i)
        {
            result[Transform::Dimension] += Transform::BottomRow[i] * v[i];
        }
        return result;
    }

    template <Concept::BasicTransform Transform, Concept::BasicVector Vec>
        requires (Transform::Dimension + 1 == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Vec& v, const Transform& t) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += v[j] * t[j][i];
            }
            result[i] += v[Transform::Dimension] * Transform::BottomRow[Transform::Dimension];
        }
        return result;
    }

    //////////////////////////////////////////////////////////////////////////
    // Transform-Point operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicTransform Transform, Concept::BasicPoint Pnt>
        requires (Transform::Dimension == Pnt::Dimension)
    [[nodiscard]] constexpr
    Pnt operator* (const Transform& t, const Pnt& p) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += t[i][j] * p[j];
            }
            result[i] += t[i][Transform::Dimension];
        }
        typename Pnt::ScalarType norm = Transform::BottomRow[Transform::Dimension];
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            norm += Transform::BottomRow[i] * p[i];
        }
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i] /= norm;
        }
        return result;
    }

    template <Concept::BasicTransform Transform, Concept::BasicPoint Pnt>
        requires (Transform::Dimension == Pnt::Dimension)
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const Transform& t) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += p[i] * t[j][i];
            }
            result[i] += Transform::BottomRow[i];
        }
        typename Pnt::ScalarType norm = Transform::BottomRow[Transform::Dimension];
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            norm += t[i][Transform::Dimension];
        }
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i] /= norm;
        }
        return result;
    }
}

#endif //MATHLIB_IMPLEMENTATION_TRANSFORM_OPERATORS_HPP
