#include "Intern.hpp"

const std::string Intern::formTypes[3] = {
    "SForm",
    "RForm",
    "PForm"
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other) 
{
    (void)other;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm* form = nullptr;

    if (formName == formTypes[0])
    {
        form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    }
    else if (formName == formTypes[1])
    {
        form = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    }
    else if (formName == formTypes[2])
    {
        form = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    }
    else
    {
        std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    }

    return form;
}