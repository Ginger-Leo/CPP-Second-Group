#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{	
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
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
