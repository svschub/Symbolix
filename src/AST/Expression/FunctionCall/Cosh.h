
#ifndef AST__EXPRESSION__FUNCTIONCALL__COSH_H_
#define AST__EXPRESSION__FUNCTIONCALL__COSH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class Cosh: public FunctionCall {
	public:
    	Cosh();
    	Cosh(const Cosh& coshExpr);
    	Cosh(Expression * paramExpr);
        virtual ~Cosh();

		virtual Expression * copy();
        virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__COSH_H_ */
