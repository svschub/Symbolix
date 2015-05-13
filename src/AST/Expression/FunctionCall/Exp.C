
#include <math.h>
#include "Exp.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Exp::Exp(): FunctionCall() {
	}

    Exp::Exp(const Exp& expExpr): FunctionCall(expExpr) {
	}

    Exp::Exp(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Exp::~Exp() {
	}


    Expression * Exp::copy() {
    	return new Exp(*this);
    }

	Expression * Exp::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
