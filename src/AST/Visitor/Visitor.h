
#ifndef AST__VISITOR__VISITOR_H_
#define AST__VISITOR__VISITOR_H_

#include <stack>
#include <iostream>

#include "../Exception/Exceptions.h"

#include "../Expression/Expression.h"
#include "../Expression/ExpressionList.h"

#include "../Expression/Number.h"
#include "../Expression/Variable.h"
#include "../Expression/Text.h"

#include "../Expression/Operation/Addition.h"
#include "../Expression/Operation/Subtraction.h"
#include "../Expression/Operation/Multiplication.h"
#include "../Expression/Operation/Division.h"
#include "../Expression/Operation/Negation.h"
#include "../Expression/Operation/Power.h"

#include "../Expression/FunctionCall/BasicFunctions.h"
#include "../Expression/FunctionCall/FunctionByIdentifier.h"

#include "Scope.h"


namespace AST { namespace Visitor {

    using AST::Expression::Expression;
	using AST::Expression::Number;
	using AST::Expression::Variable;
	using AST::Expression::Text;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;


	class Visitor {
        std::stack<Scope*> scopes;
		Scope * globalScope;

	protected:
        virtual int pushScope();
		virtual int popScope();
        virtual void removeScopes();

	public:
		Visitor();
		virtual ~Visitor();

		virtual Scope * getCurrentScope();
		virtual Scope * getGlobalScope();
		virtual void clearScopes();

		virtual Expression * visit(Number * expression) = 0;
		virtual Expression * visit(Variable * expression) = 0;
		virtual Expression * visit(Text * expression) = 0;
	    virtual Expression * visit(Op::Addition * expression) = 0;
		virtual Expression * visit(Op::Subtraction * expression) = 0;
		virtual Expression * visit(Op::Multiplication * expression) = 0;
		virtual Expression * visit(Op::Division * expression) = 0;
		virtual Expression * visit(Op::Negation * expression) = 0;
		virtual Expression * visit(Op::Power * expression) = 0;
		virtual Expression * visit(Fcn::Sqrt * expression) = 0;
		virtual Expression * visit(Fcn::Exp * expression) = 0;
		virtual Expression * visit(Fcn::Ln * expression) = 0;
		virtual Expression * visit(Fcn::Sin * expression) = 0;
		virtual Expression * visit(Fcn::Cos * expression) = 0;
		virtual Expression * visit(Fcn::Tan * expression) = 0;
		virtual Expression * visit(Fcn::Cot * expression) = 0;
		virtual Expression * visit(Fcn::Sinh * expression) = 0;
		virtual Expression * visit(Fcn::Cosh * expression) = 0;
		virtual Expression * visit(Fcn::Tanh * expression) = 0;
		virtual Expression * visit(Fcn::ArcSin * expression) = 0;
		virtual Expression * visit(Fcn::ArcCos * expression) = 0;
		virtual Expression * visit(Fcn::ArcTan * expression) = 0;
		virtual Expression * visit(Fcn::ArSinh * expression) = 0;
		virtual Expression * visit(Fcn::ArCosh * expression) = 0;
		virtual Expression * visit(Fcn::ArTanh * expression) = 0;
		virtual Expression * visit(Fcn::FunctionByIdentifier * expression) = 0;
	};

}} /* namespace AST::Visitor */

#endif /* AST__VISITOR__VISITOR_H_ */
