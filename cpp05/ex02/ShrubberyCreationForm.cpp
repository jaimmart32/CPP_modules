#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
: AForm("ShrubberyCreationForm",145,137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source)
: AForm(source), target(source.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
    if (this != &source)
    {
        this->AForm::operator=(source);
        this->target = source.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

const char *ShrubberyCreationForm::execute(const Bureaucrat &bur) const
{
    try
    {
        if(!this->getIsSigned())
            throw UnsignedException();
        else if(this->getExecGrade() < bur.getGrade())
            throw GradeTooLowException();
        std::string file_name = this->target + "_shrubbery";
        const char* file_name_cstr = file_name.c_str();//needed to match std::ofstream constructor
        std::ofstream wrightfile(file_name_cstr);
        if(!wrightfile.is_open())
            throw UnopenedException();
        for (int i = 0; i < 7; i++)
	    {
	    	wrightfile << "    **" << std::endl
	    			   << "   ****" << std::endl
	    			   << "  ******" << std::endl
	    			   << " ********" << std::endl
	    			   << "    ***" << std::endl
	    			   << "   *****" << std::endl
	    			   << "  *******" << std::endl
	    			   << " *********" << std::endl
	    			   << "***********" << std::endl
	    			   << "  *******" << std::endl
	    			   << " *********" << std::endl
	    			   << "***********" << std::endl
	    			   << "     *" << std::endl
	    			   << "     *" << std::endl
	    			   << "     *" << std::endl	    			   
	    			   << std::endl;
	    }
	    wrightfile.close();
        return NULL;
    }
    catch(const UnsignedException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "form is unsigned";
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "bureaucrat's grade is to low to execute form";
    }
    catch(const UnopenedException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "file couldn't be opened";
    }
}

const char *ShrubberyCreationForm::UnopenedException::what() const throw()
{
    return "\033[0;31mError: couldn't open file\033[0m";
}