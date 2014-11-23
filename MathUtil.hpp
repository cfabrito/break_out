#ifndef MATH_UTIL_HPP
#define MATH_UTIL_HPP

#include <cmath>

template<typename T>
inline T degToRad(T degrees)
{
    return degrees * (M_PI / 180.f);
}

template<typename T>
inline T radToDeg(T radians)
{
    return radians * (180.f / M_PI);
}

#endif
