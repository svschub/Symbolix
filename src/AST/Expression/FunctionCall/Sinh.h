
#ifndef AST__EXPRESSION__FUNCTIONCALL__SINH_H_
#define AST__EXPRESSION__FUNCTIONCALL__SINH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class Sinh: public FunctionCall {
	public:
		Sinh();
		Sinh(const Sinh& sinhExpr);
		Sinh(Expression * paramExpr);
		virtual ~Sinh();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__SINH_H_ */
