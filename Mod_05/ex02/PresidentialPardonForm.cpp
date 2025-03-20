#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{	
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
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