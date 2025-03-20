#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() // Default constructor
{
}

Bureaucrat::~Bureaucrat() // Default destructor
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) // Copy constructor
{
    _name = other._name;
    _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) // Copy assignment operator
{
    if (this == &other)
        return *this; 
    this->_name = other._name;
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) // Paramatised constructor
{
    if (grade < 1)
    throw GradeTooHighException();

    else if (grade > 150)
    throw GradeTooLowException();

    this->_name = name;
    this->_grade = grade;
}

void Bureaucrat::incBureau() // Grade increase
{
    if (_grade > 1)
    _grade--;
    else 
    std::cout << "Grade maxed out. Congratulations.\n";
}

void Bureaucrat::deBureau() // Grade decrease
{
    if (_grade < 150)
    _grade++;
    else
    std::cout << "Your grade could not be lower, something has gone terribly wrong.\n";
}

std::string Bureaucrat::getName() const // Name getter
{
    return _name;
}

int Bureaucrat::getGrade() const // Grade getter
{
    return _grade;
}

void Bureaucrat::setName(std::string newName) // Name setter
{
    _name = newName;
}

void Bureaucrat::setGrade(int newGrade) // Grade setter
{
    if (newGrade < 1)
        throw GradeTooHighException();
    else if (newGrade > 150)
        throw GradeTooLowException();
    _grade = newGrade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) // Overload insertion operator
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}
