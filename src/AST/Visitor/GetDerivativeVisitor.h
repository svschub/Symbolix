
#ifndef AST__VISITOR__GETDERIVATIVEVISITOR_H_
#define AST__VISITOR__GETDERIVATIVEVISITOR_H_

#include <string>

#include "Visitor.h"


namespace AST { namespace Visitor {

	using AST::Expression::Expression;
	using AST::Expression::Number;
	using AST::Expression::Variable;
	using AST::Expression::Text;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;


	class GetDerivativeVisitor: public Visitor {
		std::string derivativeVariableName;
	public:
		GetDerivativeVisitor();
		virtual ~GetDerivativeVisitor();

		virtual void setDerivativeVariableName(std::string name);
		virtual std::string getDerivativeVariableName();

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

#endif /* AST__VISITOR__GETDERIVATIVEVISITOR_H_ */
