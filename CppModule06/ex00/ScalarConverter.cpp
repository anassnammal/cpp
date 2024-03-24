#include "ScalarConverter.hpp"

ScalarConverter::type  ScalarConverter::identifyInput(std::string& input)
{
    // bool sign = false;
    bool dot = false;
    bool f = false;

    if (input.length() == 1 && !isdigit(input.at(0)))
        return T_CHAR;
    else if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || input == "inf" || input == "inff")
        return T_SPECIAL;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!i && (input.at(i) == '+' || input.at(i) == '-'))
            continue;
        else if (!dot && input.at(i) == '.')
            dot = true;
        else if (!f && i == input.length() - 1 && input.at(i) == 'f')
            (f = true, input.erase(i));
        else if (!isdigit(input.at(i)))
            return T_INVALID;
    }
    return T_VALID;
}

void ScalarConverter::convert(std::string input)
{
    std::string charConversion = "not possible";
    std::string intConversion = "not possible";
    std::string floatConversion = "not possible";
    std::string doubleConversion = "not possible";
    type t = identifyInput(input);
    std::stringstream ss(input);
    double  d;

    if (t == T_CHAR)
        d = ss.str().at(0);
    else
        ss >> d;
    if (!ss.fail() && t <= T_VALID)
    {
        if (d <= std::numeric_limits<char>::max() && d >= std::numeric_limits<char>::min())
           charConversion = (std::isprint(static_cast<char>(d)) ? ('\'' + std::string(1, static_cast<char>(d)) + '\'') : ("not displayable"));
        if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
           (ss.str(""), ss.clear(), ss << static_cast<int>(d), intConversion = ss.str());
        if (d == floor(d))
            ss << std::fixed << std::setprecision(1);
        if (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max())
           (ss.str(""), ss.clear(), ss << static_cast<float>(d), floatConversion = ss.str() + 'f');
        ss.str(""); ss.clear(); ss << d; doubleConversion = ss.str();
    }
    else if (t == T_SPECIAL)
    {
        floatConversion = ss.str();
        if (floatConversion == "nan" || floatConversion == "+inf" || floatConversion == "-inf" || floatConversion == "inf")
            floatConversion.push_back('f');
        doubleConversion = ss.str();
        if (doubleConversion == "nanf" || doubleConversion == "+inff" || doubleConversion == "-inff" || doubleConversion == "inff")
            doubleConversion.erase(doubleConversion.length() - 1);
    }
    std::cout << "char      : " << charConversion << std::endl;
    std::cout << "int       : " << intConversion << std::endl;
    std::cout << "float     : " << floatConversion << std::endl;
    std::cout << "double    : " << doubleConversion << std::endl;
}
