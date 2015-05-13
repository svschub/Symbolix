
#include <math.h>
#include <memory>
#include <string>

#include "SimplifyVisitor.h"


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


	Expression * SimplifyVisitor::simplifiedFunctionExpression(Fcn::FunctionCall * fcnExpr) {
        return fcnExpr->copy();
	}


	SimplifyVisitor::SimplifyVisitor(): Visitor() {
	}

	SimplifyVisitor::~SimplifyVisitor() {
	}


	Expression * SimplifyVisitor::visit(Number * expression) {
		return expression->copy();
	}

	Expression * SimplifyVisitor::visit(Variable * expression) {
		Expression * simplifiedExpr;
		std::string varName = expression->getName();
		Expression * varExpr = (Expression *)NULL;
		Scope * scope = getCurrentScope();

		while (varExpr == NULL && scope != NULL) {
			varExpr = scope->getExpressionByIdentifier(varName);
			scope = scope->getParentScope();
		}

		if (varExpr == NULL) {
			simplifiedExpr = expression->copy();
		} else {
			std::unique_ptr<Expression> simplifiedExprPtr((Expression *)varExpr->accept(this));
			simplifiedExpr = simplifiedExprPtr.release();
		}

		return simplifiedExpr;
	}

	Expression * SimplifyVisitor::visit(Text * expression) {
        throw InvalidExpressionException(std::string("Text expression not supported by SimplifyVisitor"));

        return (Expression *)NULL;
	}

	Expression * SimplifyVisitor::visit(Op::Addition * expression) {
		std::unique_ptr<Expression> leftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> rightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		Expression * leftExpr = leftExprPtr.get();
		Expression * rightExpr = rightExprPtr.get();

		Number * leftNumExpr = (leftExpr->getType() == Number::TYPE ? (Number *)leftExpr : (Number *)NULL);
		Number * rightNumExpr = (rightExpr->getType() == Number::TYPE ? (Number *)rightExpr : (Number *)NULL);

		Expression * simplifiedExpr;

		if (leftNumExpr != NULL && rightNumExpr != NULL) {
            simplifiedExpr = new Number(leftNumExpr->getValue() + rightNumExpr->getValue());
		} else if (leftNumExpr != NULL && leftNumExpr->getValue() == 0.0) {
			simplifiedExpr = rightExprPtr.release();
		} else if (rightNumExpr != NULL && rightNumExpr->getValue() == 0.0) {
			simplifiedExpr = leftExprPtr.release();
		} else {
			simplifiedExpr = new Op::Addition(leftExprPtr.release(), rightExprPtr.release());
		}

		return simplifiedExpr;
	}

	Expression * SimplifyVisitor::visit(Op::Subtraction * expression) {
		std::unique_ptr<Expression> leftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> rightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		Expression * leftExpr = leftExprPtr.get();
		Expression * rightExpr = rightExprPtr.get();

		Number * leftNumExpr = (leftExpr->getType() == Number::TYPE ? (Number *)leftExpr : (Number *)NULL);
		Number * rightNumExpr = (rightExpr->getType() == Number::TYPE ? (Number *)rightExpr : (Number *)NULL);

		Expression * simplifiedExpr;

		if (leftNumExpr != NULL && rightNumExpr != NULL) {
            simplifiedExpr = new Number(leftNumExpr->getValue() - rightNumExpr->getValue());
		} else if (leftNumExpr != NULL && leftNumExpr->getValue() == 0.0) {
			simplifiedExpr = new Op::Negation(rightExprPtr.release());
		} else if (rightNumExpr != NULL && rightNumExpr->getValue() == 0.0) {
			simplifiedExpr = leftExprPtr.release();
		} else {
			simplifiedExpr = new Op::Subtraction(leftExprPtr.release(), rightExprPtr.release());
		}

		return simplifiedExpr;
	}

	Expression * SimplifyVisitor::visit(Op::Multiplication * expression) {
		std::unique_ptr<Expression> leftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> rightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		Expression * leftExpr = leftExprPtr.get();
		Expression * rightExpr = rightExprPtr.get();

		Number * leftNumExpr = (leftExpr->getType() == Number::TYPE ? (Number *)leftExpr : (Number *)NULL);
		Number * rightNumExpr = (rightExpr->getType() == Number::TYPE ? (Number *)rightExpr : (Number *)NULL);

		Expression * simplifiedExpr;

		if (leftNumExpr != NULL && rightNumExpr != NULL) {
            simplifiedExpr = new Number(leftNumExpr->getValue() * rightNumExpr->getValue());
		} else if (leftNumExpr != NULL && leftNumExpr->getValue() == 0.0) {
			simplifiedExpr = new Number(0.0);
		} else if (rightNumExpr != NULL && rightNumExpr->getValue() == 0.0) {
			simplifiedExpr = new Number(0.0);
		} else if (leftNumExpr != NULL && leftNumExpr->getValue() == 1.0) {
			simplifiedExpr = rightExprPtr.release();
		} else if (rightNumExpr != NULL && rightNumExpr->getValue() == 1.0) {
			simplifiedExpr = leftExprPtr.release();
		} else {
			simplifiedExpr = new Op::Multiplication(leftExprPtr.release(), rightExprPtr.release());
		}

		return simplifiedExpr;
	}

	Expression * SimplifyVisitor::visit(Op::Division * expression) {
		std::unique_ptr<Expression> numeratorExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> denominatorExprPtr((Expression *)expression->getRightExpression()->accept(this));

		Expression * numeratorExpr = numeratorExprPtr.get();
		Expression * denominatorExpr = denominatorExprPtr.get();

		Number * numeratorNumExpr = (numeratorExpr->getType() == Number::TYPE ? (Number *)numeratorExpr : (Number *)NULL);
		Number * denominatorNumExpr = (denominatorExpr->getType() == Number::TYPE ? (Number *)denominatorExpr : (Number *)NULL);

		Expression * simplifiedExpr;

		if (denominatorNumExpr != NULL && denominatorNumExpr->getValue() == 0.0) {
            throw DivisionByZeroException();
		}

		if (numeratorNumExpr != NULL && denominatorNumExpr != NULL) {
            simplifiedExpr = new Number(numeratorNumExpr->getValue() / denominatorNumExpr->getValue());
		} else if (numeratorNumExpr != NULL && numeratorNumExpr->getValue() == 0.0) {
			simplifiedExpr = new Number(0.0);
		} else if (denominatorNumExpr != NULL && denominatorNumExpr->getValue() == 1.0) {
			simplifiedExpr = numeratorExprPtr.release();
		} else {
			simplifiedExpr = new Op::Division(numeratorExprPtr.release(), denominatorExprPtr.release());
		}

		return simplifiedExpr;
	}

	Expression * SimplifyVisitor::visit(Op::Negation * expression) {
		return expression->copy();
	}

	Expression * SimplifyVisitor::visit(Op::Power * expression) {
		return expression->copy();
	}

	Expression * SimplifyVisitor::visit(Fcn::Sqrt * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Exp * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Ln * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Sin * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Cos * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Tan * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Cot * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Sinh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Cosh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::Tanh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArcSin * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArcCos * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArcTan * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArSinh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArCosh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::ArTanh * expression) {
		return simplifiedFunctionExpression(expression);
	}

	Expression * SimplifyVisitor::visit(Fcn::FunctionByIdentifier * expression) {
		return simplifiedFunctionExpression(expression);
	}

}} /* namespace AST::Visitor */
