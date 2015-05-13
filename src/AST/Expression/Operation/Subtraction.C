
#include "Subtraction.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	Subtraction::Subtraction(Expression * left, Expression * right): BinaryOperation(left, right) {
	}

	Subtraction::Subtraction(const Subtraction& subExpr): BinaryOperation(subExpr) {
	}

	Subtraction::~Subtraction() {
	}


	Expression * Subtraction::copy() {
        return new Subtraction(*this);
	}

	Expression * Subtraction::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
