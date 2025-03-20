#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// OCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = delete;

		int getsignGrade() const override;
		int getexecGrade() const override;

	protected:

	private:
		std::string _target;
		int _signGrade = 145;
		int _execGrade = 137;
};
