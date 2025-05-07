#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\033[1m\033[4mEX00\033[0m\n";
    Bureaucrat Marcus("Marcus", 1);
    Bureaucrat Bruce(Marcus);
    Bureaucrat Edward("Ed", 150);


    std::cout << "\nfirst test: constructing with copies\n";
    std::cout << Marcus << std::endl;
    std::cout << Bruce << std::endl;
    std::cout << Edward << std::endl;

    std::cout << "\nSecond test: Changing names\n";
    Bruce.setName("Bruce");
    std::cout << Marcus << std::endl;
    std::cout << Bruce << std::endl;
    
    std::cout << "\nThird test: Changing grades\n";
    try 
    {
        Marcus.setGrade(162);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        Marcus.setGrade(150);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        Bruce.setGrade(5);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << Marcus << std::endl;
    std::cout << Bruce << std::endl;

    
	std::cout << "\033[1m\033[4mEX02\033[0m\n";
    std::cout << "\nForth test: creating new forms\n";
    std::cout << "\n\n-----HERE----\n\n";
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotform("Bruce");
    std::cout << shrubberyForm << std::endl;
    
    std::cout << "\nFifth test: signing and executing grades\n";
    std::cout << "Formname: "<< shrubberyForm.getTarget() << std::endl << "Form sign grade: " << shrubberyForm.getsignGrade() << std::endl << "Form exec grade: " << shrubberyForm.getexecGrade() <<std::endl;
    try
    {
        robotform.beSigned(Bruce);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while signing the form: " << e.what() << std::endl;
    }

    std::cout << "\nSixth test: executing Robotomy form 10 times\n";
    
    for (int i = 0; i < 10; i++)
        robotform.execute(Bruce);

    std::cout << "\nSeventh test: Presidential pardon form\n";
    PresidentialPardonForm PForm("Rick");

    try
    {
        PForm.beSigned(Marcus);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        PForm.beSigned(Bruce);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    PForm.execute(Bruce);

    return 0;
}
