
#ifndef AST__EXPRESSION__FUNCTIONCALL__LN_H_
#define AST__EXPRESSION__FUNCTIONCALL__LN_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class Ln: public FunctionCall {
	public:
    	Ln();
    	Ln(const Ln& lnExpr);
    	Ln(Expression * paramExpr);
		virtual ~Ln();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__LN_H_ */
