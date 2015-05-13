
#ifndef AST__EXPRESSION__OPERATION__UNARYOPERATION_H_
#define AST__EXPRESSION__OPERATION__UNARYOPERATION_H_

#include "../Expression.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	class UnaryOperation: public Expression {
	protected:
		Expression * expression;
	public:
    	static const int TYPE = 32;

    	UnaryOperation(Expression * expr);
		UnaryOperation(const UnaryOperation& opExpr);
		virtual ~UnaryOperation();

		virtual int getType();
		Expression * getExpression();
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__UNARYOPERATION_H_ */
