
#include "Addition.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace Operation {

	using AST::Visitor::Visitor;


	Addition::Addition(Expression * left, Expression * right): BinaryOperation(left, right) {
	}

	Addition::Addition(const Addition& addExpr): BinaryOperation(addExpr) {
	}

	Addition::~Addition() {
	}


	Expression * Addition::copy() {
        return new Addition(*this);
	}

	Expression * Addition::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

}}}
