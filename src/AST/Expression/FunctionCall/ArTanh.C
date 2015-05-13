
#include <math.h>
#include "ArTanh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArTanh::ArTanh(): FunctionCall() {
	}

    ArTanh::ArTanh(const ArTanh& arTanhExpr): FunctionCall(arTanhExpr) {
	}

    ArTanh::ArTanh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArTanh::~ArTanh() {
	}


    Expression * ArTanh::copy() {
    	return new ArTanh(*this);
    }

	Expression * ArTanh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
