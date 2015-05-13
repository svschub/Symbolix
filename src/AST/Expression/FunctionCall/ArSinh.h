
#ifndef AST__EXPRESSION__FUNCTIONCALL__ARSINH_H_
#define AST__EXPRESSION__FUNCTIONCALL__ARSINH_H_

#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


	class ArSinh: public FunctionCall {
	public:
    	ArSinh();
    	ArSinh(const ArSinh& arSinhExpr);
    	ArSinh(Expression * paramExpr);
		virtual ~ArSinh();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__ARSINH_H_ */
