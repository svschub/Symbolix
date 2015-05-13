
#ifndef AST__EXPRESSION__FUNCTIONCALL__COT_H_
#define AST__EXPRESSION__FUNCTIONCALL__COT_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class Cot: public FunctionCall {
	public:
    	Cot();
    	Cot(const Cot& cotExpr);
    	Cot(Expression * paramExpr);
		virtual ~Cot();

		virtual Expression * copy();
        virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__COT_H_ */
