#pragma once
#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string  name; const
        int grade;
    protected:
    
    public:
        Bureaucrat();
        ~Bureaucrat(); 
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        Bureaucrat(std::string name, int grade);
        void incBureau();
        void deBureau();
        
        std::string getName();
        void        setName(std::string);
        std::string getGrade();
        void        setGrade(std::string);

};


/*
Bureaucrat must have a constant name  and a grade (1-150(lowest)), 
use try/catch to get exceptions in grade Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
*/