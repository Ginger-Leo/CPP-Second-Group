#pragma once
#include <iostream>

class GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Grade is too low!";
        }
};

class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high!";
                }
        };