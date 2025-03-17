#include <iostream>
#include "Bureaucrat.hpp"

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
    Davis.setGrade(162);
    Bruce.setGrade(5);
    std::cout << Marcus << std::endl;
    std::cout << Davis << std::endl;
    std::cout << Bruce << std::endl;

    return 82;
}
