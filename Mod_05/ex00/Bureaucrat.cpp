#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat::Bureaucrat& operator=(const Bureaucrat& other){
    if (this == &other)
        return *this; 
    this->name = other.name;
    this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade){
    this->name = name;
    this->grade = grade;
}

Bureaucrat::void incBureau();
Bureaucrat::void deBureau();


Bureaucrat::std::string getName(){
    return name;
}

Bureaucrat::void setName(std::string new_name){
    name = new_name;
}

Bureaucrat::int getGrade(){
    return grade;
}

Bureaucrat::void setGrade(int new_grade){
    grade = new_grade;
}