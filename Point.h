#pragma once
#include <iostream>
template <class TYPE>

class Point
{
public:
	Point();
	Point(TYPE, TYPE);
	TYPE getmX()const;
	TYPE getmY()const;
	void setmX(const TYPE);
	void setmY(const TYPE);
	Point operator+(const Point secondPoint);
	bool operator==(const Point & secondPoint) const;

	void display() const;
	double distance(const Point);

private:
	TYPE mX;
	TYPE mY;

};

#include "Point.inl"