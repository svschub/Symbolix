
#include <math.h>
#include "Tanh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Tanh::Tanh(): FunctionCall() {
	}

    Tanh::Tanh(const Tanh& tanhExpr): FunctionCall(tanhExpr) {
	}

    Tanh::Tanh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Tanh::~Tanh() {
	}


    Expression * Tanh::copy() {
    	return new Tanh(*this);
    }

	Expression * Tanh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
