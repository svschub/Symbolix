
#include "InvalidFunctionParametersException.h"

namespace AST { namespace Exception {

	InvalidFunctionParametersException::InvalidFunctionParametersException() throw() {
	}

	InvalidFunctionParametersException::~InvalidFunctionParametersException() throw() {
	}

	const char* InvalidFunctionParametersException::what() const throw() {
	    return "Invalid function parameters";
	}

}} /* namespace AST::Exception */
