/*
 * Vector.h
 *
 *  Created on: Jun 1, 2018
 *      Author: adolfo
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>

template <typename RealType>
class Vector2D
{
public:
	Vector2D();
	Vector2D(RealType x, RealType y);
	Vector2D(const Vector2D& otherVector);

	const Vector2D& operator +=(const Vector2D& otherVector);
	const Vector2D& operator -=(const Vector2D& otherVector);
	const Vector2D& operator *=(RealType scalar);
	const Vector2D& operator /=(RealType scalar);
	const Vector2D operator -() const;

	std::ostream& Display(std::ostream& output) const;
	RealType Length() const;
	Vector2D& Normalize();
	void Set(RealType x, RealType y);

	RealType mX, mY;
};

template <typename RealType>
const Vector2D<RealType> operator +(Vector2D<RealType> v1, const Vector2D<RealType>& v2);

template <typename RealType>
const Vector2D<RealType> operator -(Vector2D<RealType> v1, const Vector2D<RealType>& v2);

template <typename RealType>
const Vector2D<RealType> operator *(Vector2D<RealType> v, RealType scalar);

template <typename RealType>
const Vector2D<RealType> operator *(RealType scalar, Vector2D<RealType> v);

template <typename RealType>
const Vector2D<RealType> operator /(Vector2D<RealType> v, RealType scalar);

template <typename RealType>
std::ostream& operator <<(std::ostream& output, const Vector2D<RealType>& v);

#endif /* VECTOR2D_H_ */
