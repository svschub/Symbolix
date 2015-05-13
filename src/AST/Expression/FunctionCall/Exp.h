
#ifndef AST__EXPRESSION__FUNCTIONCALL__EXP_H_
#define AST__EXPRESSION__FUNCTIONCALL__EXP_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class Exp: public FunctionCall {
	public:
    	Exp();
    	Exp(const Exp& expExpr);
    	Exp(Expression * paramExpr);
		virtual ~Exp();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__EXP_H_ */
