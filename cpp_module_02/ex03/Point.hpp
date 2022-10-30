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
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
		Point& operator= (const Point& point);
};

#endif
