#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

Point::~Point()
{

}

Point& Point::operator= (const Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}