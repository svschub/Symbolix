
#ifndef AST__EXPRESSION__FUNCTIONCALL__TANH_H_
#define AST__EXPRESSION__FUNCTIONCALL__TANH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class Tanh: public FunctionCall {
	public:
    	Tanh();
    	Tanh(const Tanh& tanhExpr);
    	Tanh(Expression * paramExpr);
		virtual ~Tanh();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__TANH_H_ */
