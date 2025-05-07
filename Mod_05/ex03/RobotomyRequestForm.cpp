#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{	
	_name = target;
	_type = "RForm";
	_target = target;
	_authorised = 0;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref)
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
std::string RobotomyRequestForm::getName() const 
{
	return _name;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->isAuthorised())
		std::cout << "Robotomy form not authorised\n";
	if (executor.getGrade() > this->getexecGrade())
		std::cout << " Bureaucrat exec grade not high enough\n";
	
	std::cout << "Drilling noises... " << std::endl;


	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed!" << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat& ref)
{
    if (ref.getGrade() <= getsignGrade())
    {
        std::cout << ref.getName() << " signed " << getName() << std::endl;
        _authorised = true;
    }
    else
        throw GradeTooLowException();
}
