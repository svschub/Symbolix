
#include <math.h>
#include "Sin.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Sin::Sin(): FunctionCall() {
	}

    Sin::Sin(const Sin& sinExpr): FunctionCall(sinExpr) {
	}

    Sin::Sin(Expression * paramExpr): FunctionCall(paramExpr) {
	}

	Sin::~Sin() {
	}


    Expression * Sin::copy() {
    	return new Sin(*this);
    }

	Expression * Sin::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
