
#ifndef AST__EXPRESSION__FUNCTIONCALL_H_
#define AST__EXPRESSION__FUNCTIONCALL_H_

#include "../Expression.h"
#include "../ExpressionList.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
	using AST::Expression::ExpressionList;


	class FunctionCall: public Expression {
	protected:
		ExpressionList * parameterList;
	public:
		static const int TYPE = 16;

		FunctionCall();
		FunctionCall(const FunctionCall& fcnCallExpr);
		FunctionCall(Expression * paramExpr);
		virtual ~FunctionCall();

		virtual int getType();
		void setParameterList(ExpressionList * paramList);
		ExpressionList * getParameterList();
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL_H_ */
