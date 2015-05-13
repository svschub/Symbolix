
#include <math.h>
#include "ArCosh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArCosh::ArCosh(): FunctionCall() {
	}

    ArCosh::ArCosh(const ArCosh& arCoshExpr): FunctionCall(arCoshExpr) {
	}

    ArCosh::ArCosh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArCosh::~ArCosh() {
	}


    Expression * ArCosh::copy() {
    	return new ArCosh(*this);
    }

	Expression * ArCosh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
