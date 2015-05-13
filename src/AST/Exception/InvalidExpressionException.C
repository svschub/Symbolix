
#include "InvalidExpressionException.h"


namespace AST { namespace Exception {

	InvalidExpressionException::InvalidExpressionException() throw() {
	}

	InvalidExpressionException::InvalidExpressionException(std::string msg) throw() {
	    message = msg;
	}

	InvalidExpressionException::InvalidExpressionException::~InvalidExpressionException() throw() {
	}

	const char* InvalidExpressionException::what() const throw() {
	    return message.c_str();
	}

}} /* namespace AST::Exception */
