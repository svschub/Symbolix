
#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    BinaryOperation::BinaryOperation(Expression * left, Expression * right) {
    	leftExpression = left;
    	rightExpression = right;
	}

    BinaryOperation::BinaryOperation(const BinaryOperation& opExpr) {
    	leftExpression = opExpr.leftExpression->copy();
    	rightExpression = opExpr.rightExpression->copy();
	}

    BinaryOperation::~BinaryOperation() {
		if (leftExpression != 0) {
			delete leftExpression;
		}

		if (rightExpression != 0) {
			delete rightExpression;
		}
	}


    int BinaryOperation::getType() {
		return BinaryOperation::TYPE;
	}

    Expression * BinaryOperation::getLeftExpression() {
    	return leftExpression;
    }

    Expression * BinaryOperation::getRightExpression() {
    	return rightExpression;
    }

}}}

