
#ifndef AST__EXPRESSION__OPERATION__POWER_H_
#define AST__EXPRESSION__OPERATION__POWER_H_

#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


    class Power: public BinaryOperation {
	public:
		Power(Expression * left, Expression * right);
		Power(const Power& powExpr);
		virtual ~Power();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__POWER_H_ */
