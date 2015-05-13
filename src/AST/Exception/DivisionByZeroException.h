
#ifndef AST__EXCEPTION__DIVISIONBYZEROEXCEPTION_H_
#define AST__EXCEPTION__DIVISIONBYZEROEXCEPTION_H_

#include <exception>


namespace AST { namespace Exception {

	class DivisionByZeroException: public std::exception {
	public:
		DivisionByZeroException() throw();
		virtual ~DivisionByZeroException() throw();

		virtual const char* what() const throw();
	};

}} /* namespace AST::Exception */

#endif /* AST__EXCEPTION__DIVISIONBYZEROEXCEPTION_H_ */
