#ifndef MATHLIB_POINT_HPP
#define MATHLIB_POINT_HPP

#include "Implementation/Point.hpp"
#include "Implementation/PointOperators.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Point2i = Point2T<i32>;
    using Point3i = Point3T<i32>;

    using Point2sz = Point2T<SizeType>;
    using Point3sz = Point3T<SizeType>;

    using Point2f = Point2T<f32>;
    using Point3f = Point3T<f32>;

    using Point2d = Point2T<f64>;
    using Point3d = Point3T<f64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(Concept::Point2<Point2i>);
    static_assert(Concept::Point3<Point3i>);

    static_assert(Concept::Point2<Point2sz>);
    static_assert(Concept::Point3<Point3sz>);

    static_assert(Concept::Point2<Point2f>);
    static_assert(Concept::Point3<Point3f>);

    static_assert(Concept::Point2<Point2d>);
    static_assert(Concept::Point3<Point3d>);
}

#endif //MATHLIB_POINT_HPP
