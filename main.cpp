#include <iostream> 
#include <iomanip>

#define SPACES " \n\t\r\f\v"

static std::string	read_from_input(void)
{
	std::string input;
	int			s, e;

	do
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
			std::exit(0);
		do
		{
			s = input.find_first_of(SPACES, s);
			e = input.find_first_not_of(SPACES, s);
			if (s > -1)
			{
				if (s == 0 || e == -1)
					input.erase(s, e - s);
				else
					input.replace(s, e - s, " ");
				s++;
			}
		} while (e != -1);
		
	}
	while (input.empty());

	return (input);
}

int main () {
	std::string	input = read_from_input();

	std::cout << input << std::endl;

  return 0;
}
