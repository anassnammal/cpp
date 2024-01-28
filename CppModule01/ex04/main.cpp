#include <iostream>
#include <fstream>

static void	replace(std::string &buff, std::string &s1, std::string &s2)
{
	std::size_t	s = 0;
	std::size_t	len = s1.length();

	while (s != std::string::npos)
	{
		s = buff.find(s1, s);
		if (s != std::string::npos)
		{
			buff.erase(s, len);
			buff.insert(s, s2);
			s++;
		}
	}
}

int main(int ac, char const **av)
{
	if (ac == 4)
	{
		std::string buff;
		std::string target(av[2]);
		std::string repl(av[3]);
		std::fstream infile(av[1], std::fstream::in);
		if (!infile.is_open())
			std::exit(1);
		std::fstream outfile(std::string(av[1]) + ".replace", std::fstream::out);
		if (!outfile.is_open())
			std::exit(2);
		std::getline(infile, buff, '\0');
		replace(buff, target, repl);
		outfile << buff;
		infile.close();
		outfile.close();
	}
	else
		std::cout << "USAGE: [file] [string_to_replace] [replacement_string]" << std::endl;
	return 0;
}