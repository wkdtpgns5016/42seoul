#include "Point.hpp"
#include <iostream>

void check_point(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point))
		std::cout << point << " is inside of a triangle" << "\n";
	else
		std::cout << point << " is outside of a triangle" << "\n";
}

int main(void) {
	Point t1(Fixed(-5), Fixed(-5));
	Point t2(Fixed(0), Fixed(5));
	Point t3(Fixed(5), Fixed(-5));

	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(-5), Fixed(-5));
	Point c(Fixed(-4), Fixed(-5));
	Point d(Fixed(10), Fixed(10));

	check_point(t1, t2, t3, a);
	check_point(t1, t2, t3, b);
	check_point(t1, t2, t3, c);
	check_point(t1, t2, t3, d);

	return (0);
}
