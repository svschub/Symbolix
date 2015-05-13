
#ifndef AST__EXPRESSION__FUNCTIONCALL__SIN_H_
#define AST__EXPRESSION__FUNCTIONCALL__SIN_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class Sin: public FunctionCall {
	public:
		Sin();
		Sin(const Sin& sinExpr);
		Sin(Expression * paramExpr);
		virtual ~Sin();

		virtual Expression * copy();
        virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__SIN_H_ */
