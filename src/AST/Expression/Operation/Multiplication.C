
#include "Multiplication.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	Multiplication::Multiplication(Expression * left, Expression * right): BinaryOperation(left, right) {
	}

	Multiplication::Multiplication(const Multiplication& mulExpr): BinaryOperation(mulExpr) {
	}

	Multiplication::~Multiplication() {
	}


	Expression * Multiplication::copy() {
        return new Multiplication(*this);
	}

	Expression * Multiplication::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
