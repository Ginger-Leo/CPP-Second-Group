#include "converter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(std::string target)
{
    if (target.empty())
    {
        std::cerr << "Error: Input is empty" << std::endl;
        return;
    }

    if (target.length() == 1 && std::isprint(target[0]) && !std::isdigit(target[0]))
        convertChar(target);

        else if (std::isdigit(target[0]) || 
             ((target[0] == '-' || target[0] == '+') && target.size() > 1 && std::isdigit(target[1])))
        convertInt(target);

    else if (target.find('.') != std::string::npos && target.back() == 'f')
        convertFloat(target);

    else if (target.find('.') != std::string::npos)
        convertDouble(target);

    else if (target == "-inf" || target == "+inf" || target == "nan" || 
             target == "-inff" || target == "+inff" || target == "nanf")
    {
        std::cout << "char  : impossible" << std::endl;
        std::cout << "int   : impossible" << std::endl;
        if (target.back() == 'f')
        {
            std::cout << "float : " << target << std::endl;
            std::cout << "double: " << target.substr(0, target.size() - 1) << std::endl;
        }
        else
        {
            std::cout << "float : " << target + "f" << std::endl;
            std::cout << "double: " << target << std::endl;
        }
    }

    else
        std::cerr << "Error: Invalid input" << std::endl;
}

void ScalarConverter::convertChar(std::string target)
{
    if (target.length() == 1 && std::isprint(target[0]) && !std::isdigit(target[0]))
    {
        char c = target[0];
        std::cout << "char  : '" << c << "'" << std::endl;
        std::cout << "int   : " << static_cast<int>(c) << std::endl;
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else
    {
        std::cerr << "Error : Invalid char input" << std::endl;
    }
}

void ScalarConverter::convertInt(std::string target)
{
    try
    {
        int value = std::stoi(target);
        std::cout << "char  : ";
        if (value >= 32 && value <= 126)
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int   : " << value << std::endl;
        std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : Invalid int input" << std::endl;
    }
}

void ScalarConverter::convertFloat(std::string target)
{
    try
    {
        float value = std::stof(target);
        std::cout << "char  : ";
        if (value >= 32 && value <= 126 && static_cast<int>(value) == value)
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else if (value < 32 || value > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "int   : ";
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && static_cast<int>(value) == value)
            std::cout << static_cast<int>(value) << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "float : " << value << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : Invalid float input" << std::endl;
    }
}

void ScalarConverter::convertDouble(std::string target)
{
    try
    {
        double value = std::stod(target);
        std::cout << "char  : ";
        if (value >= 32 && value <= 126 && static_cast<int>(value) == value)
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else if (value < 32 || value > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "int   : ";
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && static_cast<int>(value) == value)
            std::cout << static_cast<int>(value) << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "float : ";
        if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
            std::cout << static_cast<float>(value) << "f" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "double: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : Invalid double input" << std::endl;
    }
}

