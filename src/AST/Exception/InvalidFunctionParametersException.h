
#ifndef AST__EXCEPTION__INVALIDFUNCTIONPARAMETERSEXCEPTION_H_
#define AST__EXCEPTION__INVALIDFUNCTIONPARAMETERSEXCEPTION_H_


#include <exception>


namespace AST { namespace Exception {

	class InvalidFunctionParametersException: public std::exception {
	public:
		InvalidFunctionParametersException() throw();
		virtual ~InvalidFunctionParametersException() throw();

		virtual const char* what() const throw();
	};

}} /* namespace AST::Exception */

#endif /* AST__EXCEPTION__INVALIDFUNCTIONPARAMETERSEXCEPTION_H_ */
