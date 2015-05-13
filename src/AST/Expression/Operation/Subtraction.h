
#ifndef AST__EXPRESSION__OPERATION__SUBTRACTION_H_
#define AST__EXPRESSION__OPERATION__SUBTRACTION_H_

#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	class Subtraction: public BinaryOperation {
	public:
		Subtraction(Expression * left, Expression * right);
		Subtraction(const Subtraction& subExpr);
		virtual ~Subtraction();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__SUBTRACTION_H_ */
