
#include <math.h>
#include <memory>
#include <string>
#include <sstream>

#include "StringifyVisitor.h"


namespace AST { namespace Visitor {

	using AST::Exception::InvalidExpressionException;
	using AST::Exception::InvalidFunctionParametersException;
	using AST::Exception::UnknownIdentifierException;

	using AST::Expression::Expression;
	using AST::Expression::ExpressionList;

	using AST::Expression::Number;
	using AST::Expression::Variable;
	using AST::Expression::Text;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;


	Text * StringifyVisitor::getFunctionTextExpression(Fcn::FunctionCall * fcnExpr, const char * fcnName) {
		ExpressionList * parameters = fcnExpr->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * firstArgExpr = parameters->getExpressionAt(0);

		std::unique_ptr<Text> argExprPtr((Text *)firstArgExpr->accept(this));

		std::string stringifiedExpr = std::string(fcnName);

		if (firstArgExpr->getType() == Number::TYPE || firstArgExpr->getType() == Variable::TYPE) {
			stringifiedExpr += "(" + argExprPtr.get()->getContent() + ")";
		} else {
			stringifiedExpr += argExprPtr.get()->getContent();
		}

		return new Text(stringifiedExpr);
	}


	StringifyVisitor::StringifyVisitor(): Visitor() {
	}

	StringifyVisitor::~StringifyVisitor() {
	}


	Expression * StringifyVisitor::visit(Number * expression) {
		std::ostringstream textStream;
		textStream << expression->getValue();

		return new Text(textStream.str());
	}

	Expression * StringifyVisitor::visit(Variable * expression) {
		return new Text(expression->getName());
	}

	Expression * StringifyVisitor::visit(Text * expression) {
        throw InvalidExpressionException(std::string("Text expression not supported by StringifyVisitor"));

        return (Expression *)NULL;
	}

	Expression * StringifyVisitor::visit(Op::Addition * expression) {
		std::unique_ptr<Text> leftExprPtr((Text *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Text> rightExprPtr((Text *)expression->getRightExpression()->accept(this));

		std::string text = "(" + leftExprPtr.get()->getContent() + " + " + rightExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Op::Subtraction * expression) {
		std::unique_ptr<Text> leftExprPtr((Text *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Text> rightExprPtr((Text *)expression->getRightExpression()->accept(this));

		std::string text = "(" + leftExprPtr.get()->getContent() + " - " + rightExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Op::Multiplication * expression) {
		std::unique_ptr<Text> leftExprPtr((Text *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Text> rightExprPtr((Text *)expression->getRightExpression()->accept(this));

		std::string text = "(" + leftExprPtr.get()->getContent() + " * " + rightExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Op::Division * expression) {
		std::unique_ptr<Text> leftExprPtr((Text *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Text> rightExprPtr((Text *)expression->getRightExpression()->accept(this));

		std::string text = "(" + leftExprPtr.get()->getContent() + " / " + rightExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Op::Negation * expression) {
		std::unique_ptr<Text> exprPtr((Text *)expression->getExpression()->accept(this));

		std::string text = "(-" + exprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Op::Power * expression) {
		std::unique_ptr<Text> leftExprPtr((Text *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Text> rightExprPtr((Text *)expression->getRightExpression()->accept(this));

		std::string text = "pow(" + leftExprPtr.get()->getContent() + ", " + rightExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

	Expression * StringifyVisitor::visit(Fcn::Sqrt * expression) {
		return getFunctionTextExpression(expression, "sqrt");
	}

	Expression * StringifyVisitor::visit(Fcn::Exp * expression) {
		return getFunctionTextExpression(expression, "exp");
	}

	Expression * StringifyVisitor::visit(Fcn::Ln * expression) {
		return getFunctionTextExpression(expression, "ln");
	}

	Expression * StringifyVisitor::visit(Fcn::Sin * expression) {
		return getFunctionTextExpression(expression, "sin");
	}

	Expression * StringifyVisitor::visit(Fcn::Cos * expression) {
		return getFunctionTextExpression(expression, "cos");
	}

	Expression * StringifyVisitor::visit(Fcn::Tan * expression) {
		return getFunctionTextExpression(expression, "tan");
	}

	Expression * StringifyVisitor::visit(Fcn::Cot * expression) {
		return getFunctionTextExpression(expression, "cot");
	}

	Expression * StringifyVisitor::visit(Fcn::Sinh * expression) {
		return getFunctionTextExpression(expression, "sinh");
	}

	Expression * StringifyVisitor::visit(Fcn::Cosh * expression) {
		return getFunctionTextExpression(expression, "cosh");
	}

	Expression * StringifyVisitor::visit(Fcn::Tanh * expression) {
		return getFunctionTextExpression(expression, "tanh");
	}

	Expression * StringifyVisitor::visit(Fcn::ArcSin * expression) {
		return getFunctionTextExpression(expression, "asin");
	}

	Expression * StringifyVisitor::visit(Fcn::ArcCos * expression) {
		return getFunctionTextExpression(expression, "acos");
	}

	Expression * StringifyVisitor::visit(Fcn::ArcTan * expression) {
		return getFunctionTextExpression(expression, "atan");
	}

	Expression * StringifyVisitor::visit(Fcn::ArSinh * expression) {
		return getFunctionTextExpression(expression, "asinh");
	}

	Expression * StringifyVisitor::visit(Fcn::ArCosh * expression) {
		return getFunctionTextExpression(expression, "acosh");
	}

	Expression * StringifyVisitor::visit(Fcn::ArTanh * expression) {
		return getFunctionTextExpression(expression, "atanh");
	}

	Expression * StringifyVisitor::visit(Fcn::FunctionByIdentifier * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Text> argExprPtr((Text *)parameters->getExpressionAt(0)->accept(this));

		std::string text = expression->getName() + "(" + argExprPtr.get()->getContent() + ")";

		return new Text(text);
	}

}} /* namespace AST::Visitor */
