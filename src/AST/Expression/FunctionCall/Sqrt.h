
#ifndef AST__EXPRESSION__FUNCTIONCALL__SQRT_H_
#define AST__EXPRESSION__FUNCTIONCALL__SQRT_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class Sqrt: public FunctionCall {
	public:
    	Sqrt();
		Sqrt(const Sqrt& sqrtExpr);
		Sqrt(Expression * paramExpr);
		virtual ~Sqrt();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__SQRT_H_ */
