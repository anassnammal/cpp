#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>

typedef std::map<std::time_t, double> mapDb;
typedef std::pair<std::time_t, double> pair;

class BitcoinExchange
{
    mapDb       db;

    BitcoinExchange(void);
    void    calculate(pair const & pair) const;

public:
    BitcoinExchange(const char *filename);
    BitcoinExchange(BitcoinExchange const & src);
    ~BitcoinExchange(void);

    BitcoinExchange   & operator=(BitcoinExchange const & src);

    void                setDb(void);
    mapDb const       & getDb(void) const;

    static pair         parseLine(std::string const & line, char delim);
    static std::string  trim(std::string const & str);
    static std::time_t  strToSec(std::string const & str);
    static std::string  secToString(std::time_t const & sec);

    class FileError : public std::exception
    {
        std::string msg;
    public:
        FileError(std::string const & msg);
        virtual ~FileError() throw();
        virtual const char * what() const throw();
    };
};

