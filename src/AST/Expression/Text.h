
#ifndef AST__EXPRESSION__TEXT_H_
#define AST__EXPRESSION__TEXT_H_

#include <string>
#include "Expression.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	class Text: public Expression {
	protected:
		std::string content;

	public:
    	static const int TYPE = 4;

    	Text(std::string text);
    	Text(const Text& textExpr);
		virtual ~Text();

		virtual int getType();
        virtual Expression * copy();
		virtual Expression * accept(Visitor * visitor);
		std::string getContent();
	};

} }

#endif /* AST__EXPRESSION__TEXT_H_ */
