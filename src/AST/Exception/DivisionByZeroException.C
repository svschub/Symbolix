
#include "DivisionByZeroException.h"


namespace AST { namespace Exception {

	DivisionByZeroException::DivisionByZeroException() throw() {
	}

	DivisionByZeroException::~DivisionByZeroException() throw() {
	}

	const char* DivisionByZeroException::what() const throw() {
	    return "Division by zero";
	}

}} /* namespace AST::Exception */
