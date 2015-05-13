
#ifndef AST__EXPRESSION__EXPRESSIONLIST_H_
#define AST__EXPRESSION__EXPRESSIONLIST_H_

#include <vector>
#include "Expression.h"


namespace AST { namespace Expression {

    class ExpressionList {
		std::vector<Expression*> expressions;

	public:
		ExpressionList();
		ExpressionList(const ExpressionList& expressionList);
		virtual ~ExpressionList();

		virtual ExpressionList * copy();
		void add(Expression * expression);
		Expression * getExpressionAt(int index);
		int getLength();
	};

} }

#endif /* AST__EXPRESSION__EXPRESSIONLIST_H_ */
