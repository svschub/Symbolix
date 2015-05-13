
#include <math.h>
#include <memory>
#include <string>

#include "GetResultVisitor.h"


namespace AST { namespace Visitor {

	using AST::Exception::InvalidExpressionException;
	using AST::Exception::DivisionByZeroException;
	using AST::Exception::InvalidFunctionParametersException;
	using AST::Exception::UnknownIdentifierException;

	using AST::Expression::Expression;
	using AST::Expression::ExpressionList;

	using AST::Expression::Number;
	using AST::Expression::Variable;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;


	GetResultVisitor::GetResultVisitor(): Visitor() {
	}

	GetResultVisitor::~GetResultVisitor() {
	}


	Expression * GetResultVisitor::visit(Number * expression) {
		return new Number(expression->getValue());
	}

	Expression * GetResultVisitor::visit(Variable * expression) {
		std::string varName = expression->getName();
		Expression * resultExpr = (Expression *)NULL;
		Scope * scope = getCurrentScope();

		while (resultExpr == NULL && scope != NULL) {
			resultExpr = scope->getExpressionByIdentifier(varName);
			scope = scope->getParentScope();
		}

		if (resultExpr == NULL) {
			throw UnknownIdentifierException(varName);
		}

		std::unique_ptr<Number> resultExprPtr((Number *)resultExpr->accept(this));

		return new Number(resultExprPtr.get()->getValue());
	}

	Expression * GetResultVisitor::visit(Text * expression) {
        throw InvalidExpressionException(std::string("Text expression not supported by GetResultVistor"));

        return (Expression *)NULL;
	}

	Expression * GetResultVisitor::visit(Op::Addition * expression) {
		std::unique_ptr<Number> leftExprPtr((Number *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Number> rightExprPtr((Number *)expression->getRightExpression()->accept(this));

		return new Number(leftExprPtr.get()->getValue() + rightExprPtr.get()->getValue());
	}

	Expression * GetResultVisitor::visit(Op::Subtraction * expression) {
		std::unique_ptr<Number> leftExprPtr((Number *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Number> rightExprPtr((Number *)expression->getRightExpression()->accept(this));
		double result = leftExprPtr.get()->getValue() - rightExprPtr.get()->getValue();

		return new Number(result);
	}

	Expression * GetResultVisitor::visit(Op::Multiplication * expression) {
		std::unique_ptr<Number> leftExprPtr((Number *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Number> rightExprPtr((Number *)expression->getRightExpression()->accept(this));

		return new Number(leftExprPtr.get()->getValue() * rightExprPtr.get()->getValue());
	}

	Expression * GetResultVisitor::visit(Op::Division * expression) {
		std::unique_ptr<Number> leftExprPtr((Number *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Number> rightExprPtr((Number *)expression->getRightExpression()->accept(this));

		if (rightExprPtr.get()->getValue() == 0.0) {
			throw DivisionByZeroException();
		}

		return new Number(leftExprPtr.get()->getValue() / rightExprPtr.get()->getValue());
	}

	Expression * GetResultVisitor::visit(Op::Negation * expression) {
		std::unique_ptr<Number> exprPtr((Number *)expression->getExpression()->accept(this));

		return new Number(-exprPtr.get()->getValue());
	}

	Expression * GetResultVisitor::visit(Op::Power * expression) {
		std::unique_ptr<Number> leftExprPtr((Number *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Number> rightExprPtr((Number *)expression->getRightExpression()->accept(this));

		return new Number(pow(leftExprPtr.get()->getValue(), rightExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Sqrt * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(sqrt(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Exp * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(exp(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Ln * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(log(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Sin * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(sin(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Cos * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(cos(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Tan * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(tan(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Cot * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(1.0/tan(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Sinh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(sinh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Cosh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(cosh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::Tanh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(tanh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArcSin * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(asin(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArcCos * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(acos(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArcTan * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(atan(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArSinh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(asinh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArCosh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(acosh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::ArTanh * expression) {
		ExpressionList * parameters = expression->getParameterList();

		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		std::unique_ptr<Number> argExprPtr((Number *)parameters->getExpressionAt(0)->accept(this));

		return new Number(atanh(argExprPtr.get()->getValue()));
	}

	Expression * GetResultVisitor::visit(Fcn::FunctionByIdentifier * expression) {
		// @todo not yet implemented
		throw UnknownIdentifierException(expression->getName());

		return (Expression *)NULL;
	}

}} /* namespace AST::Visitor */
