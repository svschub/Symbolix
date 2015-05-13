
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARCOSH_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARCOSH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class ArCosh: public FunctionCall {
	public:
    	ArCosh();
		ArCosh(const ArCosh& arCoshExpr);
		ArCosh(Expression * paramExpr);
		virtual ~ArCosh();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARCOSH_H_ */
