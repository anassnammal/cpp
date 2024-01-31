#include "Point.hpp"

// A x ( B y − C y ) + B x ( C y − A y ) + C x ( A y − B y )

Fixed claculateArea(Point const &a, Point const &b, Point const &c)
{
    Fixed const ax = a.getX();
    Fixed const ay = a.getY();
    Fixed const bx = b.getX();
    Fixed const by = b.getY();
    Fixed const cx = c.getX();
    Fixed const cy = c.getY();

    return (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed const area = claculateArea(a, b, c);
    Fixed const area1 = claculateArea(a, b, point);
    Fixed const area2 = claculateArea(b, c, point);
    Fixed const area3 = claculateArea(c, a, point);

    return (area == area1 + area2 + area3);
}