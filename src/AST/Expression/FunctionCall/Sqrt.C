
#include <math.h>
#include "Sqrt.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Sqrt::Sqrt(): FunctionCall() {
	}

    Sqrt::Sqrt(const Sqrt& sqrtExpr): FunctionCall(sqrtExpr) {
	}

    Sqrt::Sqrt(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Sqrt::~Sqrt() {
	}


    Expression * Sqrt::copy() {
    	return new Sqrt(*this);
    }

	Expression * Sqrt::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
