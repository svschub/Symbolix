
#ifndef AST__EXPRESSION_H_
#define AST__EXPRESSION_H_


namespace AST { namespace Visitor {
    class Visitor;
}}


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	class Expression {
	public:
		Expression();
		virtual ~Expression();

		virtual Expression * accept(Visitor * visitor) = 0;

		virtual int getType() = 0;
		virtual Expression * copy() = 0;
	};

}}

#endif /* AST__EXPRESSION_H_ */
