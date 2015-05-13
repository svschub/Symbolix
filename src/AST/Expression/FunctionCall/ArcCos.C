
#include <math.h>
#include "ArcCos.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArcCos::ArcCos(): FunctionCall() {
	}

    ArcCos::ArcCos(const ArcCos& arcCosExpr): FunctionCall(arcCosExpr) {
	}

    ArcCos::ArcCos(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArcCos::~ArcCos() {
	}


    Expression * ArcCos::copy() {
    	return new ArcCos(*this);
    }

	Expression * ArcCos::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
