#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

template <class TYPE>
Point<TYPE>::Point()
{
	mX = 0;
	mY = 0;
}

template <class TYPE>
Point<TYPE>::Point<TYPE>(TYPE inX, TYPE inY)
{
	mX = inX;
	mY = inY;

}

template <class TYPE>
void Point<TYPE>::setmX(const TYPE inX)
{
	mX = inX;
}

template <class TYPE>
void Point<TYPE>::setmY(const TYPE inY)
{
	mY = inY;

}

template <class TYPE>
Point<TYPE> Point<TYPE>::operator+(const Point secondPoint)
{
	Point  newPoint;
	newPoint.mX = mX + secondPoint.mX;
	newPoint.mY = mY + secondPoint.mY;

	return newPoint;
}

template<class TYPE>
inline bool Point<TYPE>::operator==(const Point& secondPoint) const
{
	if (mX == secondPoint.mX &&mY == secondPoint.mY)
		return true;
	else
		return false;
}

template <class TYPE>
TYPE Point<TYPE>::getmX()const
{
	return mX;
}

template <class TYPE>
TYPE Point<TYPE>::getmY()const
{
	return mY;
}

template <class TYPE>
void Point<TYPE>::display() const
{
	cout << "(" << getmX() << "," << getmY() << ")";
}

template <class TYPE>
double Point<TYPE>::distance(const Point a) //point a is the other point.
{
	int xComponent, yComponent; //I used part1 and part2 because there was a big mess and I needed it simplier
	double ans;
	xComponent = (getmY() - a.getmY());
	yComponent = (getmX() - a.getmX());

	ans = sqrt(pow(xComponent, 2) + pow(yComponent, 2)); //Pow is for exponent
	return ans;
}