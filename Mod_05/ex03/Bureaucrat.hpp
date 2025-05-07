#pragma once
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat(); 
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&) = delete;

        
        Bureaucrat(std::string, int);
        void incBureau();
        void deBureau();
        
        std::string getName() const;
        int getGrade() const;
        void setName(std::string);
        void setGrade(int);  
        void signAForm(AForm&); 

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
          

    protected: 
        
    private:
        std::string     name; 
        int             grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
