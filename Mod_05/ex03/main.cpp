#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\033[1m\033[4mEX03\033[0m\n";

    Intern intern;
    Bureaucrat bureaucrat("Jeff", 1);

    std::cout << "\nEight test: Creating forms with the intern\n";
    
    AForm* internShrubberyForm = intern.makeForm("SForm", "home");
    AForm* robotomyForm = intern.makeForm("RForm", "Bruce");
    AForm* pardonForm = intern.makeForm("PForm", "Rick");
    AForm* invalidForm = intern.makeForm("invalid form", "target");
    
    std::cout << "\nNinth test: Testing forms\n";
    
    if (internShrubberyForm)
    {
        internShrubberyForm->beSigned(bureaucrat);
        internShrubberyForm->execute(bureaucrat);
        delete internShrubberyForm;
    }

    if (robotomyForm)
    {
        robotomyForm->beSigned(bureaucrat);
        robotomyForm->execute(bureaucrat);
        delete robotomyForm;
    }

    if (pardonForm)
    {
        pardonForm->beSigned(bureaucrat);
        pardonForm->execute(bureaucrat);
        delete pardonForm;
    }

    if (invalidForm)
    {
        delete invalidForm;
    }
   

    return 0;
}
