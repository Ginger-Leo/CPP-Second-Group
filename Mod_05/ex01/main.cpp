#include <iostream>
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

int main()
{
    Bureaucrat Marcus("Marcus", 1);
    Bureaucrat Davis = Marcus;
    Bureaucrat Bruce(Marcus);

    std::cout << "first test: constructing with copies\n";
    std::cout << Marcus << std::endl;
    std::cout << Davis << std::endl;
    std::cout << Bruce << std::endl;

    std::cout << "Second test: Changing names\n";
    Davis.setName("Davis");
    Bruce.setName("Bruce");
    std::cout << Marcus << std::endl;
    std::cout << Davis << std::endl;
    std::cout << Bruce << std::endl;
    
    std::cout << "Third test: Changing grades\n";
    try 
    {
        Davis.setGrade(162);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        Bruce.setGrade(5);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << Marcus << std::endl;
    std::cout << Davis << std::endl;
    std::cout << Bruce << std::endl;

    return 82;
}
