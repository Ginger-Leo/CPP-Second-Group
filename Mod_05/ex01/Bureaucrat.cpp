#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat() // Default constructor
{
}

Bureaucrat::~Bureaucrat() // Default destructor
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) // Copy constructor
{
    name = other.name;
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) // Copy assignment operator
{
    if (this == &other)
        return *this; 
    this->name = other.name;
    this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) // Paramatised constructor
{
    if (grade < 1)
    throw GradeTooHighException();

    else if (grade > 150)
    throw GradeTooLowException();

    this->name = name;
    this->grade = grade;
}

void Bureaucrat::incBureau() // Grade increase
{
    if (grade > 1)
    grade--;
    else 
    std::cout << "Grade maxed out. Congratulations.\n";
}

void Bureaucrat::deBureau() // Grade decrease
{
    if (grade < 150)
    grade++;
    else
    std::cout << "Your grade could not be lower, something has gone terribly wrong.\n";
}

std::string Bureaucrat::getName() const // Name getter
{
    return name;
}

int Bureaucrat::getGrade() const // Grade getter
{
    return grade;
}

void Bureaucrat::setName(std::string newName) // Name setter
{
    name = newName;
}

void Bureaucrat::setGrade(int newGrade) // Grade setter
{
    if (newGrade < 1)
        throw GradeTooHighException();
    else if (newGrade > 150)
        throw GradeTooLowException();
    grade = newGrade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) // Overload insertion operator
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}
