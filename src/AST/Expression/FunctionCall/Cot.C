
#include <math.h>
#include "Cot.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Cot::Cot(): FunctionCall() {
	}

    Cot::Cot(const Cot& cotExpr): FunctionCall(cotExpr) {
	}

    Cot::Cot(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Cot::~Cot() {
	}


    Expression * Cot::copy() {
    	return new Cot(*this);
    }

	Expression * Cot::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
