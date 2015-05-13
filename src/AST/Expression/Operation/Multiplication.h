
#ifndef AST__EXPRESSION__OPERATION__MULTIPLICATION_H_
#define AST__EXPRESSION__OPERATION__MULTIPLICATION_H_

#include "BinaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


    class Multiplication: public BinaryOperation {
	public:
		Multiplication(Expression * left, Expression * right);
		Multiplication(const Multiplication& mulExpr);
		virtual ~Multiplication();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__MULTIPLICATION_H_ */
