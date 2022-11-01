#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;

	public:
		Point();
		Point(const Point& point);
		Point(const Fixed x, const Fixed y);
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
		Point& operator= (const Point& point);
};

std::ostream& operator<<(std::ostream& o, const Point& p);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
