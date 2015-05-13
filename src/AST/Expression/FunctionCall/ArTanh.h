
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARTANH_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARTANH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class ArTanh: public FunctionCall {
	public:
    	ArTanh();
    	ArTanh(const ArTanh& arTanhExpr);
    	ArTanh(Expression * paramExpr);
		virtual ~ArTanh();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARTANH_H_ */
