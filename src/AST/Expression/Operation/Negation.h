
#ifndef AST__EXPRESSION__OPERATION__NEGATION_H_
#define AST__EXPRESSION__OPERATION__NEGATION_H_

#include "UnaryOperation.h"


namespace AST { namespace Expression { namespace Operation {

    using AST::Visitor::Visitor;


	class Negation: public UnaryOperation {
	public:
		Negation(Expression * expr);
		Negation(const Negation& negExpr);
		virtual ~Negation();

		virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__OPERATION__NEGATION_H_ */
