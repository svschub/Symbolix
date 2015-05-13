
#ifndef AST__EXPRESSION__OPERATION__BINARYOPERATION_H_
#define AST__EXPRESSION__OPERATION__BINARYOPERATION_H_

#include "../Expression.h"


namespace AST { namespace Expression { namespace Operation {

	class BinaryOperation: public Expression {
	protected:
		Expression * leftExpression;
		Expression * rightExpression;
	public:
		static const int TYPE = 64;

		BinaryOperation(Expression * left, Expression * right);
		BinaryOperation(const BinaryOperation& opExpr);
		virtual ~BinaryOperation();

		virtual int getType();
		Expression * getLeftExpression();
		Expression * getRightExpression();
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__BINARYOPERATION_H_ */
