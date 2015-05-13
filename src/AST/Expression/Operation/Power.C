
#include "Power.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	Power::Power(Expression * left, Expression * right): BinaryOperation(left, right) {
	}

	Power::Power(const Power& powExpr): BinaryOperation(powExpr) {
	}

	Power::~Power() {
	}


	Expression * Power::copy() {
        return new Power(*this);
	}

	Expression * Power::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
