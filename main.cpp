#include <iostream> 
#include <iomanip>

int main () {
	std::string	input = "   anasss   nsshh  j    ";
	int	start = 0;
	int	end;

	// std::getline(std::cin, input); 
	while (start > -1)
	{
		start = input.find_first_of(" \n\t\r\f\v", start);
		if (start > -1)
			input.erase(start, end - start);
		end  = input.find_first_not_of(" \n\t\r\f\v", start);
		end = end > -1 ? end - (bool)start : input.end() - input.begin();
		std::cout << input << std::endl;
		start += (start > -1);
	}
  return 0;
}
