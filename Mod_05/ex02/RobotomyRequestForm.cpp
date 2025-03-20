#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{	
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
{
	_target = ref._target;
}

int RobotomyRequestForm::getsignGrade() const 
{
	return _signGrade;
}

int RobotomyRequestForm::getexecGrade() const 
{
	return _execGrade;
}