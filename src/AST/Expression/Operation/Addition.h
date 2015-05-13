
#ifndef AST__EXPRESSION__OPERATION__ADDITION_H_
#define AST__EXPRESSION__OPERATION__ADDITION_H_

#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

	using AST::Visitor::Visitor;


	class Addition: public BinaryOperation {
	public:
		Addition(Expression * left, Expression * right);
		Addition(const Addition& addExpr);
		virtual ~Addition();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__ADDITION_H_ */
