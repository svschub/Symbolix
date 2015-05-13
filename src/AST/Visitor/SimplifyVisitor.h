
#ifndef AST__VISITOR__SIMPLIFYVISITOR_H_
#define AST__VISITOR__SIMPLIFYVISITOR_H_

#include "Visitor.h"


namespace AST { namespace Visitor {

	using AST::Expression::Expression;
	using AST::Expression::Number;
	using AST::Expression::Variable;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;


	class SimplifyVisitor: public Visitor {
		Expression * simplifiedFunctionExpression(Fcn::FunctionCall * fcnExpr);
	public:
		SimplifyVisitor();
		virtual ~SimplifyVisitor();

		virtual Expression * visit(Number * expression);
		virtual Expression * visit(Variable * expression);
		virtual Expression * visit(Text * expression);
        virtual Expression * visit(Op::Addition * expression);
		virtual Expression * visit(Op::Subtraction * expression);
		virtual Expression * visit(Op::Multiplication * expression);
		virtual Expression * visit(Op::Division * expression);
		virtual Expression * visit(Op::Negation * expression);
		virtual Expression * visit(Op::Power * expression);
		virtual Expression * visit(Fcn::Sqrt * expression);
		virtual Expression * visit(Fcn::Exp * expression);
		virtual Expression * visit(Fcn::Ln * expression);
		virtual Expression * visit(Fcn::Sin * expression);
		virtual Expression * visit(Fcn::Cos * expression);
		virtual Expression * visit(Fcn::Tan * expression);
		virtual Expression * visit(Fcn::Cot * expression);
		virtual Expression * visit(Fcn::Sinh * expression);
		virtual Expression * visit(Fcn::Cosh * expression);
		virtual Expression * visit(Fcn::Tanh * expression);
		virtual Expression * visit(Fcn::ArcSin * expression);
		virtual Expression * visit(Fcn::ArcCos * expression);
		virtual Expression * visit(Fcn::ArcTan * expression);
		virtual Expression * visit(Fcn::ArSinh * expression);
		virtual Expression * visit(Fcn::ArCosh * expression);
		virtual Expression * visit(Fcn::ArTanh * expression);
		virtual Expression * visit(Fcn::FunctionByIdentifier * expression);
	};

}} /* namespace AST::Visitor */

#endif /* AST__VISITOR__SIMPLIFYVISITOR_H_ */
