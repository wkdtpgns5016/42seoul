#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed zComponentA = ((a.getX() - point.getX()) * (c.getY() - point.getY())) - ((c.getX() - point.getX()) * (a.getY() - point.getY()));
	Fixed zComponentB = ((c.getX() - point.getX()) * (b.getY() - point.getY())) - ((b.getX() - point.getX()) * (c.getY() - point.getY()));
	Fixed zComponentC = ((b.getX() - point.getX()) * (a.getY() - point.getY())) - ((a.getX() - point.getX()) * (b.getY() - point.getY()));

	if (zComponentA > 0 && zComponentB > 0 && zComponentC > 0)
		return (true);
	else if (zComponentA < 0 && zComponentB < 0 && zComponentC < 0)
		return (true);
	else return (false);
}
