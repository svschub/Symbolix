
#ifndef FORMULAEXCEPTION_H_
#define FORMULAEXCEPTION_H_

#include <exception>

class FormulaException: public std::exception {
	std::string message;
public:
	FormulaException() throw();
	FormulaException(std::string msg) throw();
	FormulaException(const char * msg) throw();
	virtual ~FormulaException() throw();

	virtual const char* what() const throw();
};

#endif /* FORMULAEXCEPTION_H_ */
