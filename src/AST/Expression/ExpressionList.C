
#include "ExpressionList.h"


namespace AST { namespace Expression {

	ExpressionList::ExpressionList() {
	}

	ExpressionList::ExpressionList(const ExpressionList& expressionList) {
		Expression * expression;

		for (std::vector<Expression*>::const_iterator expressionsIterator=expressionList.expressions.begin();
		     expressionsIterator != expressionList.expressions.end();
		     ++expressionsIterator) {

			expression = *expressionsIterator;
			add(expression->copy());
		}
	}

	ExpressionList::~ExpressionList() {
		Expression * expression;

		for (std::vector<Expression*>::iterator expressionsIterator=expressions.begin();
		     expressionsIterator != expressions.end();
		     ++expressionsIterator) {

			expression = *expressionsIterator;
			delete expression;
		}
	}

	ExpressionList * ExpressionList::copy() {
        return new ExpressionList(*this);
	}

	void ExpressionList::add(Expression * expression) {
        expressions.push_back(expression);
	}

	Expression * ExpressionList::getExpressionAt(int index) {
		return expressions[index];
	}

	int ExpressionList::getLength() {
		return expressions.size();
	}

}}
