#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// OCF
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;

		int getsignGrade() const override;
		int getexecGrade() const override;

	protected:

	private:
		std::string _target;
		const int 	_signGrade = 25;
		const int 	_execGrade = 5;
};;