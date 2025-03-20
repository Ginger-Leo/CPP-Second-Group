#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        //OCF
        Form();
        ~Form();
        Form(const Form&);
        Form& operator=(const Form&);

        Form(std::string);

        //Getters & Setters
        void setName(std::string);
        void setAuthorised(bool);
        void setsignGrade(int);
        void setexecGrade(int);
        std::string getName() const;
        int getsignGrade() const;
        int getexecGrade() const;
        bool isAuthorised() const;
        void beSigned(Bureaucrat&);

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
        const std::string   _name;
        bool                _authorised;
        const int           _signGrade;
        const int           _execGrade;

};

std::ostream& operator<<(std::ostream& os, const Form& b) = delete;
