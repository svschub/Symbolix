
#include <math.h>
#include "Cosh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Cosh::Cosh(): FunctionCall() {
	}

    Cosh::Cosh(const Cosh& coshExpr): FunctionCall(coshExpr) {
	}

    Cosh::Cosh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

	Cosh::~Cosh() {
	}


    Expression * Cosh::copy() {
    	return new Cosh(*this);
    }

	Expression * Cosh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
