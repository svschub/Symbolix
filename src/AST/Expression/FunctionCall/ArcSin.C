
#include <math.h>
#include "ArcSin.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArcSin::ArcSin(): FunctionCall() {
	}

    ArcSin::ArcSin(const ArcSin& arcSinExpr): FunctionCall(arcSinExpr) {
	}

    ArcSin::ArcSin(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArcSin::~ArcSin() {
	}


    Expression * ArcSin::copy() {
    	return new ArcSin(*this);
    }

	Expression * ArcSin::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
