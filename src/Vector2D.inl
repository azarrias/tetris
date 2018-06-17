/*
 * Vector2D.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: adolfo
 */

#ifndef VECTOR2D_INL_
#define VECTOR2D_INL_

#include <cmath>
#include <iostream>
#include "Vector2D.h"

template <typename RealType>
Vector2D<RealType>::Vector2D()
: mX(0), mY(0)
{}

template <typename RealType>
Vector2D<RealType>::Vector2D(RealType x, RealType y)
: mX(x), mY(y)
{}

template <typename RealType>
Vector2D<RealType>::Vector2D(const Vector2D& otherVector)
: mX(otherVector.mX), mY(otherVector.mY)
{}

template <typename RealType>
const Vector2D<RealType>& Vector2D<RealType>::operator +=(const Vector2D& otherVector)
{
	mX += otherVector.mX;
	mY += otherVector.mY;
	return *this;
}

template <typename RealType>
const Vector2D<RealType>& Vector2D<RealType>::operator -=(const Vector2D& otherVector)
{
	mX -= otherVector.mX;
	mY -= otherVector.mY;
	return *this;
}

template <typename RealType>
const Vector2D<RealType>& Vector2D<RealType>::operator *=(RealType scalar)
{
	mX *= scalar;
	mY *= scalar;
	return *this;
}

template <typename RealType>
const Vector2D<RealType>& Vector2D<RealType>::operator /=(RealType scalar)
{
	mX /= scalar;
	mY /= scalar;
	return *this;
}

template <typename RealType>
const Vector2D<RealType> Vector2D<RealType>::operator -() const
{
	return Vector2D<RealType>(-mX, -mY);
}

template <typename RealType>
std::ostream& Vector2D<RealType>::Display(std::ostream& output) const
{
	output << "(" << mX << ", " << mY << ")";
	return output;
}

template <typename RealType>
RealType Vector2D<RealType>::Length() const
{
	return std::sqrt(mX * mX + mY * mY);
}

template <typename RealType>
Vector2D<RealType>& Vector2D<RealType>::Normalize()
{
	*this /= Length();
	return *this;
}

template <typename RealType>
void Vector2D<RealType>::Set(RealType x, RealType y)
{
	mX = x;
	mY = y;
}

template <typename RealType>
const Vector2D<RealType> operator +(Vector2D<RealType> v1, const Vector2D<RealType>& v2)
{
	v1.mX += v2.mX;
	v1.mY += v2.mY;
	return v1;
}

template <typename RealType>
const Vector2D<RealType> operator -(Vector2D<RealType> v1, const Vector2D<RealType>& v2)
{
	v1.mX -= v2.mX;
	v1.mY -= v2.mY;
	return v1;
}

template <typename RealType>
const Vector2D<RealType> operator *(Vector2D<RealType> v, RealType scalar)
{
	v.mX *= scalar;
	v.mY *= scalar;
	return v;
}

template <typename RealType>
const Vector2D<RealType> operator *(RealType scalar, Vector2D<RealType> v)
{
	return v * scalar;
}

template <typename RealType>
const Vector2D<RealType> operator /(Vector2D<RealType> v, RealType scalar)
{
	v.mX /= scalar;
	v.mY /= scalar;
	return v;
}

template <typename RealType>
std::ostream& operator <<(std::ostream& output, const Vector2D<RealType>& v)
{
	return v.Display(output);
}

typedef Vector2D<float> Vector2Df;
typedef Vector2D<int> Vector2Di;

#endif /* VECTOR2D_INL_ */
