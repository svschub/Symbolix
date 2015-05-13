
#include <string>

#include "UnknownIdentifierException.h"


namespace AST { namespace Exception {

	UnknownIdentifierException::UnknownIdentifierException() throw() {
		identifierName = "";
	}

	UnknownIdentifierException::UnknownIdentifierException(std::string identifier) throw() {
		identifierName = identifier;
	}

	UnknownIdentifierException::~UnknownIdentifierException() throw() {
	}

	const char* UnknownIdentifierException::what() const throw() {
		std::string message = "Unknown identifier '" + identifierName + "'";
		return message.c_str();
	}

}} /* namespace AST::Exception */
