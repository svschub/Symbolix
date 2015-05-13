
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARCSIN_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARCSIN_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class ArcSin: public FunctionCall {
	public:
    	ArcSin();
    	ArcSin(const ArcSin& arcSinExpr);
    	ArcSin(Expression * paramExpr);
		virtual ~ArcSin();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARCSIN_H_ */
