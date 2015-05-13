
#include "Division.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


    Division::Division(Expression * left, Expression * right): BinaryOperation(left, right) {
	}

    Division::Division(const Division& divExpr): BinaryOperation(divExpr) {
	}

	Division::~Division() {
	}


	Expression * Division::copy() {
        return new Division(*this);
	}

	Expression * Division::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
