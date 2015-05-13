
#include <math.h>
#include "ArSinh.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    ArSinh::ArSinh(): FunctionCall() {
	}

    ArSinh::ArSinh(const ArSinh& arSinhExpr): FunctionCall(arSinhExpr) {
	}

    ArSinh::ArSinh(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    ArSinh::~ArSinh() {
	}


    Expression * ArSinh::copy() {
    	return new ArSinh(*this);
    }

	Expression * ArSinh::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
