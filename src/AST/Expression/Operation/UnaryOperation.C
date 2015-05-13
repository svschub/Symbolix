
#include "UnaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

	UnaryOperation::UnaryOperation(Expression * expr) {
		expression = expr;
	}

	UnaryOperation::UnaryOperation(const UnaryOperation& opExpr) {
		expression = opExpr.expression->copy();
	}

	UnaryOperation::~UnaryOperation() {
		if (expression != 0) {
			delete expression;
		}
	}


	int UnaryOperation::getType() {
		return UnaryOperation::TYPE;
	}

	Expression * UnaryOperation::getExpression() {
		return expression;
	}

}}}

