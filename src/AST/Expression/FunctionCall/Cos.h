
#ifndef AST__EXPRESSION__FUNCTIONCALL__COS_H_
#define AST__EXPRESSION__FUNCTIONCALL__COS_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class Cos: public FunctionCall {
	public:
		Cos();
		Cos(const Cos& cosExpr);
		Cos(Expression * paramExpr);
		virtual ~Cos();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__COS_H_ */
