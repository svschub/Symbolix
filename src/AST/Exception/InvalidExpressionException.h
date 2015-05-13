
#ifndef AST__EXCEPTION__INVALIDEXPRESSIONEXCEPTION_H_
#define AST__EXCEPTION__INVALIDEXPRESSIONEXCEPTION_H_

#include <exception>
#include <string>


namespace AST { namespace Exception {

	class InvalidExpressionException: public std::exception {
		std::string message;
	public:
		InvalidExpressionException() throw();
		InvalidExpressionException(std::string msg) throw();
		virtual ~InvalidExpressionException() throw();

		virtual const char* what() const throw();
	};

}} /* namespace AST::Exception */

#endif /* AST__EXCEPTION__INVALIDEXPRESSIONEXCEPTION_H_ */
