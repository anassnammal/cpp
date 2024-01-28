#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	this->size = 0;
	this->it = 0;
}

PhoneBook::~PhoneBook(void)
{
	 
}

void			PhoneBook::addContact(void)
{
	Contact	&c = this->contact[this->it];;
	c.setFirstName( PhoneBook::_prompt(false, ENTER(FN)));
	c.setLastName( PhoneBook::_prompt(false, ENTER(LN)));
	c.setNickName( PhoneBook::_prompt(false, ENTER(NN)));
	c.setPhoneNumber( PhoneBook::_prompt(true, ENTER(PN)));
	c.setDarkestSecret( PhoneBook::_prompt(false, ENTER(DS)));
	this->size += (this->size < 8);
	++(this->it) %= 8;
	::system("clear");
}

std::string		PhoneBook::_prompt(bool d, std::string msg)
{
	std::stringstream	input_stream;
	std::string			input;
	std::string			parsed;

	std::cout << BG_COLOR << msg << BG_NOCLR;
	do
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
			std::exit(0);
		else if (!input.empty())
		{
			input_stream.str(input);
			while ((input_stream >> input))
				parsed += input + ' ';
			parsed.pop_back();
			std::size_t p = parsed.find_first_not_of(" 0123456789", (parsed[0] == '+'));
			if (d && p != std::string::npos) parsed.clear();
		}
		else
			std::cout << std::endl;
		input_stream.clear();
	} while (parsed.empty());
	
	return (parsed);
}

void			PhoneBook::printContact(Contact const & c)
{
	std::cout << OUTPUT(FN) << c.getFirstName() << std::endl;
	std::cout << OUTPUT(LN) << c.getLastName() << std::endl;
	std::cout << OUTPUT(NN) << c.getNickName() << std::endl;
	std::cout << OUTPUT(PN) << c.getPhoneNumber() << std::endl;
	std::cout << OUTPUT(DS) << c.getDarkestSecret() << std::endl;
}

void			PhoneBook::listContact(void) const
{
	::system("clear");
	std::cout << BG_COLOR;
	std::cout << std::setw(10) << IN << '|';
	std::cout << std::setw(10) << FN << '|';
	std::cout << std::setw(10) << LN << '|';
	std::cout << std::setw(10) << NN <<  '|' << std::endl;
	std::cout << BG_NOCLR;
	for (int i = 0; i < this->size; ++i)
	{
		std::cout << std::setw(10) << i + 1 << '|';
		std::string fn(this->contact[i].getFirstName());
		std::cout << std::setw(10) << TURNCATE_IF(fn) << '|';
		std::string ln(this->contact[i].getLastName());
		std::cout << std::setw(10) << TURNCATE_IF(ln) << '|';
		std::string nn(this->contact[i].getNickName());
		std::cout << std::setw(10) << TURNCATE_IF(nn) << '|' << std::endl;
	}
}

void			PhoneBook::searchContact(void) const
{
	int			i;

	this->listContact();
	i = 0;
	do
		std::cout << ENTER(IN);
	while (!(std::cin >> i) && std::cin.good());
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (i > 0 && i <= this->size)
	{
		::system("clear");
		PhoneBook::printContact(this->contact[i - 1]);
	}
}

void			PhoneBook::launch(void)
{
	std::string input;

	::system("clear");
	std::cout << "\tWelcome to PhoneBook" << std::endl;
	do
	{
		input = _prompt(false, "Enter a COMMAND <ADD> <SEARCH> <EXIT>:");
		if (input == "ADD")
			this->addContact();
		else if (input == "SEARCH")
			this->searchContact();
	}
	while (input != "EXIT");
	::system("clear");
}