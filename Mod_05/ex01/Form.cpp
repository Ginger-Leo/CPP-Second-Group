#include "Form.hpp"

Form::Form() : _name("Default"), _authorised(false), _signGrade(150), _execGrade(150) // Default constructor
{
}

Form::Form(std::string formName) : _name(formName), _authorised(false), _signGrade(150), _execGrade(150) // Parametrized constructor
{
}

Form::~Form() // Default destructor
{
}

Form::Form(const Form& ref) // Copy constructor
{
    _name = ref._name;
    _authorised = ref._authorised;
    _signGrade = ref._signGrade;
    _execGrade = ref._execGrade;
}

Form& Form::operator=(const Form& other) //copy assignment operator
{
    if (this == &other)
        return *this; 
    this->_name = other._name;
    this->_signGrade = other._signGrade;
    this->_execGrade = other._execGrade;
    return *this;
}

//Getters & Setters
void Form::setName(std::string newName)
{
    _name = newName;
}

void Form::setAuthorised(bool button)
{
    if (button == false)
        _authorised = true;
    else if (button == true)
       _authourised = false;
}

void Form::setsignGrade(int newGrade)
{
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    _signGrade = newGrade;
}

void Form::setexecGrade(int newGrade)
{
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    _execGrade = newGrade;
}

std::string Form::getName() const
{
    return this->_name;
}

int Form::getsignGrade() const
{
    return this->_signGrade;
}

int Form::getexecGrade() const
{
    return this->_execGrade;
}

bool Form::isAuthorised() const
{
    return this->_authorised;
}

void Form::beSigned(Bureaucrat& ref)
{
    if (ref.getGrade() =< getsignGrade())
    {
        std::cout << ref.getName() << " signed " << getName() << std::endl;
        _authorised = true;
    }
    else if (ref.getGrade() > getsignGrade())
        throw GradeTooLowException();
    
}

std::ostream& Form::operator<<(std::ostream& os, const Form& b)
{
    os << "Form               : " << b.getName() << std::endl
       << "Authorised         : " << b.isAuthorised() << std::endl
       << "Sign grade         : " << b.getsignGrade() << std::endl
       << "Execute Grade level: " << b.getexecGrade() << std::endl;
    return os;
}
