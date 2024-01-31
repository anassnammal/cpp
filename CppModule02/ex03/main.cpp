#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void ) {

	Point const a(1 ,1);
	Point const b(1 ,2);
	Point const c(2,1);
	Point const p(1.5,1.2);
	if (bsp(a, b, c, p))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return 0;
}