#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(const RobotomyRequestForm &source);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
    RobotomyRequestForm(std::string &target);
    ~RobotomyRequestForm();

    std::string getTarget() const;

    void execute(const Bureaucrat &bur) const;
};

#endif