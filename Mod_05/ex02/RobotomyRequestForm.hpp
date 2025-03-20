#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		// OCF
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;

		int getsignGrade() const override;
		int getexecGrade() const override;

	protected:

	private:
		std::string _target;
		int _signGrade = 72;
		int _execGrade = 45;
};