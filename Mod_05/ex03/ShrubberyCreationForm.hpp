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
		std::string getType() const;
		std::string getTarget() const;
		std::string getName() const override;
		void execute(const Bureaucrat&) const override;

		void setAuthorised(bool);
		bool isAuthorised() const;
		void beSigned(Bureaucrat&) override;

	protected:

	private:
		std::string _name;
		std::string _target;
		std::string _type;
		int _signGrade = 145;
		int _execGrade = 137;
		bool _authorised;
};
