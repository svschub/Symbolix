
#ifndef AST__EXPRESSION__FUNCTIONCALL__TAN_H_
#define AST__EXPRESSION__FUNCTIONCALL__TAN_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class Tan: public FunctionCall {
	public:
    	Tan();
    	Tan(const Tan& tanExpr);
    	Tan(Expression * paramExpr);
		virtual ~Tan();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__TAN_H_ */
