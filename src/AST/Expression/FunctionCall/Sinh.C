
#include <math.h>
#include "Sinh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Sinh::Sinh(): FunctionCall() {
	}

    Sinh::Sinh(const Sinh& sinhExpr): FunctionCall(sinhExpr) {
	}

    Sinh::Sinh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

	Sinh::~Sinh() {
	}


    Expression * Sinh::copy() {
    	return new Sinh(*this);
    }

	Expression * Sinh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
