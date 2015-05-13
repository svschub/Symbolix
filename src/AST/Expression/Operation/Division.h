
#ifndef AST__EXPRESSION__OPERATION__DIVISION_H_
#define AST__EXPRESSION__OPERATION__DIVISION_H_

#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


    class Division: public BinaryOperation {
	public:
		Division(Expression * left, Expression * right);
		Division(const Division& divExpr);
		virtual ~Division();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__DIVISION_H_ */
