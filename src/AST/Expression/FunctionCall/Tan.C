
#include <math.h>
#include "Tan.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Tan::Tan(): FunctionCall() {
	}

    Tan::Tan(const Tan& tanExpr): FunctionCall(tanExpr) {
	}

    Tan::Tan(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Tan::~Tan() {
	}


    Expression * Tan::copy() {
    	return new Tan(*this);
    }

	Expression * Tan::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
