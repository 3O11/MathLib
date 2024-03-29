#ifndef MATHLIB_IMPLEMENTATION_MATRIX_OPERATORS_HPP
#define MATHLIB_IMPLEMENTATION_MATRIX_OPERATORS_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Matrix-Matrix operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                for (SizeType k = 0; k < Mat::Dimension; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }



    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator+= (Mat& a, const Mat& b) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                a[i][j] += b[i][j];
            }
        }
        return a;
    }

    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator-= (Mat& a, const Mat& b) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                a[i][j] -= b[i][j];
            }
        }
        return a;
    }

    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator*= (Mat& a, const Mat& b) noexcept
    {
        a = a * b;
        return a;
    }

    //////////////////////////////////////////////////////////////////////////
    // Matrix-Scalar operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] += s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] += s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] -= s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] = s - m[i][j];
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator/ (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] /= s;
            }
        }
        return scaled;
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator/ (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] = s / m[i][j];
            }
        }
        return scaled;
    }



    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator+= (Mat& m, typename Mat::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; i++)
        {
            for (SizeType j = 0; j < Mat::Dimension; j++)
            {
                m[i][j] += s;
            }
        }
        return m;
    }

    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator-= (Mat& m, typename Mat::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; i++)
        {
            for (SizeType j = 0; j < Mat::Dimension; j++)
            {
                m[i][j] -= s;
            }
        }
        return m;
    }

    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator*= (Mat& m, typename Mat::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; i++)
        {
            for (SizeType j = 0; j < Mat::Dimension; j++)
            {
                m[i][j] *= s;
            }
        }
        return m;
    }

    template <Concept::BasicMatrix Mat>
    [[maybe_unused]] constexpr
    Mat& operator/= (Mat& m, typename Mat::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Mat::Dimension; i++)
        {
            for (SizeType j = 0; j < Mat::Dimension; j++)
            {
                m[i][j] /= s;
            }
        }
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    // Matrix-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicMatrix Mat, Concept::BasicVector Vec>
        requires (Mat::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Mat& m, const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                result[i] += m[i][j] * u[j];
            }
        }
        return result;
    }

    template <Concept::BasicMatrix Mat, Concept::BasicVector Vec>
        requires (Mat::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Vec& u, const Mat& m) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                result[i] += u[j] * m[j][i];
            }
        }
        return result;
    }

    //////////////////////////////////////////////////////////////////////////
    // Matrix-Point operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicMatrix Mat, Concept::BasicPoint Pnt>
        requires (Mat::Dimension == Pnt::Dimension)
    [[nodiscard]] constexpr
    Pnt operator* (const Mat& m, const Pnt& p) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
        }
        return result;
    }

    template <Concept::BasicMatrix Mat, Concept::BasicPoint Pnt>
        requires (Mat::Dimension == Pnt::Dimension)
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const Mat& m) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
        }
        return result;
    }

    template <Concept::BasicMatrix Mat, Concept::BasicPoint Pnt>
        requires (Mat::Dimension == Pnt::Dimension + 1)
    [[nodiscard]] constexpr
    Pnt operator* (const Mat& m, const Pnt& p) noexcept
    {
        Pnt result;
        typename Pnt::ScalarType w = 0;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            for (SizeType j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
            result[i] += m[i][Pnt::Dimension];

            w += p[i] * m[Pnt::Dimension][i];
        }
        w += m[Pnt::Dimension][Pnt::Dimension];
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] /= w;
        }

        return result;
    }

    template <Concept::BasicMatrix Mat, Concept::BasicPoint Pnt>
        requires (Mat::Dimension == Pnt::Dimension + 1)
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const Mat& m) noexcept
    {
        Pnt result;
        typename Pnt::ScalarType w = 0;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            for (SizeType j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
            result[i] += m[Pnt::Dimension][i];

            w += p[i] * m[i][Pnt::Dimension];
        }
        w += m[Pnt::Dimension][Pnt::Dimension];
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] /= w;
        }

        return result;
    }
}

#endif //MATHLIB_IMPLEMENTATION_MATRIX_OPERATORS_HPP
