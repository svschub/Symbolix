
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARCCOS_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARCCOS_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class ArcCos: public FunctionCall {
	public:
		ArcCos();
        ArcCos(const ArcCos& arcCosExpr);
        ArcCos(Expression * paramExpr);
		virtual ~ArcCos();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARCCOS_H_ */
