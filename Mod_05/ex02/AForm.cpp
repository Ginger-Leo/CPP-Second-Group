#include "AForm.hpp"

AForm::AForm() : _name("Default"), _authorised(false), _signGrade(150), _execGrade(150) // Default constructor
{
}

AForm::AForm(std::string AFormName) : _name(AFormName), _authorised(false), _signGrade(150), _execGrade(150) // Parametrized constructor
{
}

AForm::~AForm() // Default destructor
{
}

AForm::AForm(const AForm& ref)  : _name (ref._name), _authorised (ref._authorised), _signGrade (ref._signGrade),_execGrade (ref._execGrade) // Copy constructor
{
}

//  "DELETED" method
// AForm& AForm::operator=(const AForm& other) //copy assignment operator
// {
//     if (this == &other)
//         return *this; 
//     this->_name = other._name;
//     this->_signGrade = other._signGrade;
//     this->_execGrade = other._execGrade;
//     return *this;
// }

//Getters & Setters
void AForm::setAuthorised(bool button)
{
    if (button == false)
        _authorised = true;
    else if (button == true)
       _authorised = false;
}

void AForm::setsignGrade(int newGrade)
{
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    _signGrade = newGrade;
}

void AForm::setexecGrade(int newGrade)
{
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    _execGrade = newGrade;
}

std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getsignGrade() const
{
    return this->_signGrade;
}

int AForm::getexecGrade() const
{
    return this->_execGrade;
}

bool AForm::isAuthorised() const
{
    return this->_authorised;
}

void AForm::beSigned(Bureaucrat& ref)
{
    if (ref.getGrade() <= getsignGrade())
    {
        std::cout << ref.getName() << " signed " << getName() << std::endl;
        _authorised = true;
    }
    else if (ref.getGrade() > getsignGrade())
        throw GradeTooLowException();
    
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os << "AForm               : " << b.getName() << std::endl
       << "Authorised         : " << b.isAuthorised() << std::endl
       << "Sign grade         : " << b.getsignGrade() << std::endl
       << "Execute Grade level: " << b.getexecGrade() << std::endl;
    return os;
}
