
#include "Variable.h"
#include "../Visitor/Visitor.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	Variable::Variable(std::string varName) {
		name = varName;
	}

	Variable::Variable(const Variable& varExpr): name(varExpr.name) {
	}

	Variable::~Variable() {
	}


	int Variable::getType() {
		return Variable::TYPE;
	}

	Expression * Variable::copy() {
		return new Variable(*this);
	}

	Expression * Variable::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

	std::string Variable::getName() {
		return name;
	}

}}
