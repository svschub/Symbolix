
#include <math.h>
#include "Ln.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    Ln::Ln(): FunctionCall() {
	}

    Ln::Ln(const Ln& lnExpr): FunctionCall(lnExpr) {
	}

    Ln::Ln(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    Ln::~Ln() {
	}


    Expression * Ln::copy() {
    	return new Ln(*this);
    }

	Expression * Ln::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
