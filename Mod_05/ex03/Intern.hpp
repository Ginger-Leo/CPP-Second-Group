#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern&) = delete;

        AForm* makeForm(const std::string& formName, const std::string& target);

    protected:
    
    private:
        static const std::string formTypes[3];

};