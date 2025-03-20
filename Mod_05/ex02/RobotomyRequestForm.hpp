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
		std::string target;
		int signGrade = 72;
		int execGrade = 45;
};