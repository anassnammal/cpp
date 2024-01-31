#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{

}

Point::Point(Point const & p)
{
    *this = p;
}

Point::Point(float const x, float const y) : x(x), y(y)
{

}

Point::~Point(void)
{

}

Point& Point::operator=(Point const & p)
{
    
}

Fixed const & Point::getX(void) const
{
    return (this->x);
}

Fixed const & Point::getY(void) const
{
    return (this->y);
}