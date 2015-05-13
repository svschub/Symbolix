
#ifndef AST__EXPRESSION__NUMBER_H_
#define AST__EXPRESSION__NUMBER_H_

#include "Expression.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	class Number: public Expression {
	protected:
		double value;

	public:
    	static const int TYPE = 1;

    	Number(double num);
		Number(const Number& numExpr);
		virtual ~Number();

		virtual int getType();
		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);

		void setValue(double val);
		double getValue();
	};

} }

#endif /* AST__EXPRESSION__NUMBER_H_ */
