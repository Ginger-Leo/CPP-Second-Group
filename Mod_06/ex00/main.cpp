#include "converter.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Incorrect arguments given.\nTry this: ./converter A\n";
        return 1;
    }

    std::string target = av[1];
    ScalarConverter::convert(target);
    return 0;
}

/*
{
    int         i = 42;
    char        c = 'A';
    float       f = 42.0f;
    double      d = 42.0;
    std::string s = "should not convert";
    std::string pl = "+inff"; // should handle

    std::cout << "Int test:\n";
    ScalarConverter::convert(std::to_string(i));
    
    std::cout << "\nChar test:\n";
    ScalarConverter::convert(std::string(1, c));
    
    std::cout << "\nFloat test:\n";
    ScalarConverter::convert(std::to_string(f));
    
    std::cout << "\nDouble test:\n";
    ScalarConverter::convert(std::to_string(d));
    
    std::cout << "\nString test:\n";
    ScalarConverter::convert(s);
    
    std::cout << "\nPseudo literal test:\n";
    ScalarConverter::convert(pl);
   
    return 0;
} 
    */