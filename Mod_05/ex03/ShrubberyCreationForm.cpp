#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{	
    _name = target;
	_target = target;
	_type = "SForm";
    _authorised = 0;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref)
{
	_target = ref._target;
}

int ShrubberyCreationForm::getsignGrade() const 
{
	return _signGrade;
}

int ShrubberyCreationForm::getexecGrade() const 
{
	return _execGrade;
}

bool ShrubberyCreationForm::isAuthorised() const
{
	return this->_authorised;
}

std::string ShrubberyCreationForm::getType() const
{
	return _type;
}
std::string ShrubberyCreationForm::getName() const
{
	return _name;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}
		
void ShrubberyCreationForm::beSigned(Bureaucrat& ref)
{
    if (ref.getGrade() <= getsignGrade())
    {
        std::cout << ref.getName() << " signed " << getName() << std::endl;
        _authorised = true;
    }
    else
        throw GradeTooLowException();
}

void ShrubberyCreationForm::setAuthorised(bool button)
{
    if (button == false)
        _authorised = true;
    else if (button == true)
       _authorised = false;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    std::cout << executor.getName() << " does very little.\n";
}