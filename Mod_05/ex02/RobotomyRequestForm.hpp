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
		std::string getName() const override;

		void execute(const Bureaucrat&);
		void beSigned(Bureaucrat&) override;

	protected:

	private:
		std::string _name;
		std::string _type;
		std::string _target;
		int _signGrade = 72;
		int _execGrade = 45;
		bool _authorised;
};