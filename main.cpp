#include <iostream> 

int main ()
{
	std::time_t rawtime;
	std::tm * timeinfo;
	char buffer[80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::string str(buffer);

	std::cout << str;

	return 0;
}
