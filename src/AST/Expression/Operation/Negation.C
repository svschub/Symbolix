
#include "Negation.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	Negation::Negation(Expression * expr): UnaryOperation(expr) {
	}

	Negation::Negation(const Negation& negExpr): UnaryOperation(negExpr) {
	}

	Negation::~Negation() {
	}


	Expression * Negation::copy() {
        return new Negation(*this);
	}

	Expression * Negation::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
