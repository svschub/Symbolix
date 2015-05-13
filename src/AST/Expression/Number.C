
#include "Number.h"
#include "../Visitor/Visitor.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	Number::Number(double val) {
		value = val;
	}

	Number::Number(const Number& numExpr): value(numExpr.value) {
	}

	Number::~Number() {
	}


	int Number::getType() {
		return Number::TYPE;
	}

	Expression * Number::copy() {
		return new Number(*this);
	}

	Expression * Number::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

	void Number::setValue(double val) {
		value = val;
	}

	double Number::getValue() {
		return value;
	}

}}
