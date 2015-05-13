
#include <math.h>
#include "Cos.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Cos::Cos(): FunctionCall() {
	}

    Cos::Cos(const Cos& cosExpr): FunctionCall(cosExpr) {
	}

    Cos::Cos(Expression * paramExpr): FunctionCall(paramExpr) {
	}

	Cos::~Cos() {
	}


    Expression * Cos::copy() {
    	return new Cos(*this);
    }

	Expression * Cos::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
