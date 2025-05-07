#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{	
	_name = target;
	_type = "PForm";
	_target = target;
	_authorised = 0;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref)
{
	_target = ref._target;
}

int PresidentialPardonForm::getsignGrade() const 
{
	return _signGrade;
}

int PresidentialPardonForm::getexecGrade() const 
{
	return _execGrade;
}

std::string PresidentialPardonForm::getName() const
{
	return _name;
}

std::string PresidentialPardonForm::getType() const
{
	return _type;
}

void PresidentialPardonForm::beSigned(Bureaucrat& ref)
{
    if (ref.getGrade() <= getsignGrade())
    {
        std::cout << ref.getName() << " signed " << getType() << std::endl;
        _authorised = true;
    }
    else
        throw GradeTooLowException();
}

void PresidentialPardonForm::execute(const Bureaucrat& ref)
{
	if (ref.getGrade() > this->getexecGrade())
		throw GradeTooLowException();
	if (this->_authorised )
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
	else	
		std::cout << "PForm not authorised\n";
}
