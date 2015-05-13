
#include <string>

#include "FormulaException.h"


FormulaException::FormulaException() throw(): message("") {
}

FormulaException::FormulaException(std::string msg) throw(): message(msg) {
}

FormulaException::FormulaException(const char * msg) throw(): message(std::string(msg)) {
}

FormulaException::~FormulaException() throw() {
}

const char* FormulaException::what() const throw() {
	return message.c_str();
}
