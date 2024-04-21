#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *inputFile)
{
    // std::cout << "BitcoinExchange: Parameter constructor called" << std::endl;
    try
    {
        setDb();
        std::fstream file(inputFile);
        if (!file.is_open())
            throw FileError(std::string(inputFile) + " could not be opened");
        std::string line;
        if (!std::getline(file, line) || line != "date | value")
            throw FileError("header is missing or invalid file format");
        while (file.good() && !file.eof())
        {
            std::getline(file, line);
            if (line.empty())
                continue ;
            try
            {
                pair current = parseLine(line, '|');
                calculate(current);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    // std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
    *this = src;
    return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout << "BitcoinExchange: Destructor called" << std::endl;
    db.clear();
    return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
    if (this != &src)
    {
        // std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
        db.clear();
        db = src.getDb();
    }
    return *this;
}

void    BitcoinExchange::setDb(void)
{
    // std::cout << "BitcoinExchange: setDb called" << std::endl;
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw FileError("data.csv could not be opened");
    std::string line;
    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw FileError("header is missing or invalid");
    while (std::getline(file, line))
    {
        if (line.empty())
            continue ;
        pair current = parseLine(line, ',');
        db.insert(current);
    }
    file.close();
    if (db.empty())
        throw FileError("data.csv is empty");
    return ;
}

mapDb const & BitcoinExchange::getDb(void) const
{
    // std::cout << "BitcoinExchange: getDb called" << std::endl;
    return db;
}

void    BitcoinExchange::calculate(pair const & pair) const
{
    // std::cout << "BitcoinExchange: calculate called" << std::endl;
    long    date = pair.first;
    double  amount = pair.second;
    double  rate = 0.0;
    double  total = 0.0;
    std::string dateStr = secToString(date);
    mapDb::const_iterator it = db.upper_bound(date);
    if (it == db.begin())
        throw FileError("No data available => " + dateStr);
    rate = (--it)->second;
    total = amount * rate;
    std::cout << dateStr << " => " << amount << " = " << total << std::endl;
    return ;
}

pair    BitcoinExchange::parseLine(std::string const & line, char delim)
{
    // std::cout << "BitcoinExchange: parseLine called" << std::endl;
    std::stringstream ss(line);
    std::string token;
    pair result;
    if (!std::getline(ss, token, delim))
        throw FileError("Invalid line format");
    result.first = strToSec(trim(token));
    if (!(ss >> result.second) || ss.rdbuf()->in_avail() != 0)
        throw FileError("Invalid amount format");
    if (result.second < 0)
        throw FileError("negative amount not allowed");
    if (delim == '|' && result.second > 1000)
        throw FileError("amount too large");
    return result;
}

std::string BitcoinExchange::trim(std::string const & str)
{
    // std::cout << "BitcoinExchange: trim called" << std::endl;
    std::string::size_type first = str.find_first_not_of(" ");
    std::string::size_type last = str.find_last_not_of(" ");
    if (first == std::string::npos || last == std::string::npos)
        return std::string();
    return str.substr(first, last - first + 1);
}

std::time_t BitcoinExchange::strToSec(std::string const & str)
{
    // 
    // std::cout << "BitcoinExchange: strToSec called" << std::endl;
    struct std::tm tm = {};
    // std::cout << str << std::endl;
    if (!strptime(str.c_str(), "%Y-%m-%d", &tm) || !isValidDate(tm))
        throw FileError("Invalid date format => " + str);
    std::time_t sec = std::mktime(&tm);
    if (sec == -1)
        throw FileError("Invalid date format => " + str);
    return sec;
}

std::string BitcoinExchange::secToString(std::time_t const & sec)
{
    // std::cout << "BitcoinExchange: secToString called" << std::endl;
    struct tm *tm = std::localtime(&sec);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
    return std::string(buffer);
}

bool         BitcoinExchange::isValidDate(struct std::tm &date)
{
    bool leap_year = ((date.tm_year % 4 == 0 && date.tm_year % 100 != 0) || (date.tm_year % 400 == 0));
    int month_days = 30;
    month_days -= (date.tm_mon == 1);
    month_days -= (!leap_year && date.tm_mon == 1);
    month_days += (date.tm_mon % 2 == 0 && date.tm_mon < 7) || (date.tm_mon % 2 == 1 && date.tm_mon > 6);
    // std::cout << month_days << std::endl;
    return (date.tm_mday <= month_days);
}

BitcoinExchange::FileError::FileError(std::string const & msg) : msg(msg)
{
    // std::cout << "BitcoinExchange: FileError constructor called" << std::endl;
    return ;
}

BitcoinExchange::FileError::~FileError() throw()
{
    // std::cout << "BitcoinExchange: FileError destructor called" << std::endl;
    return ;
}

const char * BitcoinExchange::FileError::what() const throw()
{
    // std::cout << "BitcoinExchange: FileError what called" << std::endl;
    return msg.c_str();
}

/*
    January - 31 days
    February - 28 days in a common year and 29 days in leap years
    March - 31 days
    April - 30 days
    May - 31 days
    June - 30 days
    July - 31 days
    August - 31 days
    September - 30 days
    October - 31 days
    November - 30 days
    December - 31 days
*/