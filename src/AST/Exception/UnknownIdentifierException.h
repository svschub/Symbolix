
#ifndef AST__EXCEPTION__UNKNOWNIDENTIFIEREXCEPTION_H_
#define AST__EXCEPTION__UNKNOWNIDENTIFIEREXCEPTION_H_

#include <exception>


namespace AST { namespace Exception {

	class UnknownIdentifierException: public std::exception {
		std::string identifierName;
	public:
		UnknownIdentifierException() throw();
		UnknownIdentifierException(std::string identifier) throw();
		virtual ~UnknownIdentifierException() throw();

		virtual const char* what() const throw();
	};

}} /* namespace AST::Exception */

#endif /* AST__EXCEPTION__UNKNOWNIDENTIFIEREXCEPTION_H_ */
