
#ifndef AST__EXPRESSION__VARIABLE_H_
#define AST__EXPRESSION__VARIABLE_H_

#include <string>
#include "Expression.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	class Variable: public Expression {
	protected:
		std::string name;

	public:
    	static const int TYPE = 2;

    	Variable(std::string varName);
		Variable(const Variable& varExpr);
		virtual ~Variable();

		virtual int getType();
        virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
		std::string getName();
	};

} }

#endif /* AST__EXPRESSION__VARIABLE_H_ */
