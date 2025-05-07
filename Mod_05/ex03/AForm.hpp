#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        //OCF
        AForm();
        ~AForm();
        AForm(const AForm&);
        AForm& operator=(const AForm&);

        AForm(std::string);

        //Getters & Setters
        void setAuthorised(bool);
        void setsignGrade(int);
        void setexecGrade(int);
        virtual std::string getName() const;
        virtual int getsignGrade() const;
        virtual int getexecGrade() const;
        bool isAuthorised() const;
		virtual void beSigned(Bureaucrat&) = 0;

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
        int           		_signGrade;
        int          		_execGrade;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);
