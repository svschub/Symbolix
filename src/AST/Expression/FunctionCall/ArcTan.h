
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARCTAN_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARCTAN_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class ArcTan: public FunctionCall {
	public:
    	ArcTan();
    	ArcTan(const ArcTan& arcTanExpr);
    	ArcTan(Expression * paramExpr);
		virtual ~ArcTan();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARCTAN_H_ */
