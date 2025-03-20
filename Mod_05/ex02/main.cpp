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


    std::cout << "first test: constructing with copies\n";
    std::cout << Marcus << std::endl;
    std::cout << Bruce << std::endl;
    std::cout << Edward << std::endl;

    std::cout << "Second test: Changing names\n";
    Bruce.setName("Bruce");
    std::cout << Marcus << std::endl;
    std::cout << Bruce << std::endl;
    
    std::cout << "Third test: Changing grades\n";
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
    // std::cout << Davis << std::endl;
    std::cout << Bruce << std::endl;

    std::cout << "\033[1m\033[4mEX01\033[0m\n";
    std::cout << "Forth test: signing and executing grades\n";

    AForm first;
    AForm second("second form");

    std::cout << first << std::endl;
    std::cout << second << std::endl;
	first.setsignGrade(50);
    Edward.signAForm(first);
    second.beSigned(Bruce);
    std::cout << first << std::endl;
    std::cout << second << std::endl;

	std::cout << "\033[1m\033[4mEX02\033[0m\n";

    return 82;
}
