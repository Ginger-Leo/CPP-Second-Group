#pragma once
#include <iostream>
#include <string>
#include "Exceptions.hpp"

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat(); 
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);

        
        Bureaucrat(std::string, int);
        void incBureau();
        void deBureau();
        
        std::string getName() const;
        int getGrade() const;
        void setName(std::string);
        void setGrade(int);  
          

    protected: 
        
    private:
        std::string name; 
        int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

/*
Bureaucrat must have a constant name  and a grade (1-150(lowest)), 
use try/catch to get exceptions in grade Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
*/