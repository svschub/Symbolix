
#include <math.h>
#include "ArcTan.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArcTan::ArcTan(): FunctionCall() {
	}

    ArcTan::ArcTan(const ArcTan& arcTanExpr): FunctionCall(arcTanExpr) {
	}

    ArcTan::ArcTan(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArcTan::~ArcTan() {
	}


    Expression * ArcTan::copy() {
    	return new ArcTan(*this);
    }

	Expression * ArcTan::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
