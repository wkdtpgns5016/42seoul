#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y)
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
	this->x = point.getX();
	this->y = point.getY();
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

std::ostream& operator<<(std::ostream& o, const Point& p)
{
	return (o << "(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ")");
}