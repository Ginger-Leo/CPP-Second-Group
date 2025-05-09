#pragma once
#include <iostream>
#include <string>
#include <cstdlib> //stoi, stof, stod.
#include <limits>
#include <algorithm>
#include <cmath> // handling 'nan' and 'inf'.
#include <iomanip> // formatting floating point output.
#include <cctype> // for checking char is printable.

class ScalarConverter
{
    private:
    static void convertChar(std::string);
    static void convertInt(std::string);
    static void convertFloat(std::string);
    static void convertDouble(std::string);
    
    protected:
    
    public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    
    static void convert(std::string);
};