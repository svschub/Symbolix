
#include <math.h>
#include <memory>
#include <string>
#include <iostream>

#include "GetDerivativeVisitor.h"


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


	GetDerivativeVisitor::GetDerivativeVisitor(): Visitor() {
	}

	GetDerivativeVisitor::~GetDerivativeVisitor() {
	}


	void GetDerivativeVisitor::setDerivativeVariableName(std::string name) {
		derivativeVariableName = name;
	}

	std::string GetDerivativeVisitor::getDerivativeVariableName() {
		return derivativeVariableName;
	}


	Expression * GetDerivativeVisitor::visit(Number * expression) {
		return new Number(0.0);
	}

	Expression * GetDerivativeVisitor::visit(Variable * expression) {
		Expression * resultExpr = (Expression *)0;
		std::string varName = expression->getName();

		if (varName == derivativeVariableName) {
			resultExpr = new Number(1.0);
		} else {
			Expression * varExpr = (Expression *)0;
			Scope * scope = getCurrentScope();

			while (varExpr == 0 && scope != 0) {
				varExpr = scope->getExpressionByIdentifier(varName);
				scope = scope->getParentScope();
			}

			if (varExpr == 0) {
				throw UnknownIdentifierException(varName);
			}

			resultExpr = varExpr->accept(this);
		}

		return resultExpr;
	}

	Expression * GetDerivativeVisitor::visit(Text * expression) {
        throw InvalidExpressionException(std::string("Text expression not supported by GetDerivativeVisitor"));

        return (Expression *)NULL;
	}

	Expression * GetDerivativeVisitor::visit(Op::Addition * expression) {
		std::unique_ptr<Expression> derivedLeftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> derivedRightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		return new Op::Addition(derivedLeftExprPtr.release(), derivedRightExprPtr.release());
	}

	Expression * GetDerivativeVisitor::visit(Op::Subtraction * expression) {
		std::unique_ptr<Expression> derivedLeftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> derivedRightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		return new Op::Subtraction(derivedLeftExprPtr.release(), derivedRightExprPtr.release());
	}

	Expression * GetDerivativeVisitor::visit(Op::Multiplication * expression) {
		std::unique_ptr<Expression> derivedLeftExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> derivedRightExprPtr((Expression *)expression->getRightExpression()->accept(this));

		return new Op::Addition(
			new Op::Multiplication(expression->getLeftExpression()->copy(), derivedRightExprPtr.release()),
			new Op::Multiplication(expression->getRightExpression()->copy(), derivedLeftExprPtr.release())
		);
	}

	Expression * GetDerivativeVisitor::visit(Op::Division * expression) {
		std::unique_ptr<Expression> derivedNumeratorExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> derivedDenominatorExprPtr((Expression *)expression->getRightExpression()->accept(this));
		Expression * numeratorExpr = expression->getLeftExpression();
		Expression * denominatorExpr = expression->getRightExpression();

		return new Op::Division(
			new Op::Subtraction(
				new Op::Multiplication(derivedNumeratorExprPtr.release(), denominatorExpr->copy()),
				new Op::Multiplication(derivedDenominatorExprPtr.release(), numeratorExpr->copy())
		    ),
		    new Op::Power(denominatorExpr->copy(), new Number(2.0))
		);
	}

	Expression * GetDerivativeVisitor::visit(Op::Negation * expression) {
		std::unique_ptr<Expression> derivedExprPtr((Expression *)expression->getExpression()->accept(this));

		Expression * derivedExpr = derivedExprPtr.release();

		return new Op::Negation(derivedExpr);
	}

	Expression * GetDerivativeVisitor::visit(Op::Power * expression) {
		std::unique_ptr<Expression> derivedBaseExprPtr((Expression *)expression->getLeftExpression()->accept(this));
		std::unique_ptr<Expression> derivedExponentExprPtr((Expression *)expression->getRightExpression()->accept(this));
		Expression * baseExpr = expression->getLeftExpression();
		Expression * exponentExpr = expression->getRightExpression();

		return new Op::Multiplication(
			expression->copy(),
            new Op::Addition(
               	new Op::Multiplication(
               		derivedExponentExprPtr.release(),
               		new Fcn::Ln(baseExpr->copy())
               	),
               	new Op::Multiplication(
               		derivedBaseExprPtr.release(),
               	    new Op::Division(exponentExpr->copy(), baseExpr->copy())
		        )
		    )
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Sqrt * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			new Op::Division(
				new Number(0.5),
				expression->copy()
		    ),
		    derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Exp * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			expression->copy(),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Ln * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			parameterExpr->copy()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Sin * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			new Fcn::Cos(parameterExpr->copy()),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Cos * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			new Op::Negation(new Fcn::Sin(parameterExpr->copy())),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Tan * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
  		    new Op::Addition(
  		    	new Number(1.0),
				new Op::Power(expression->copy(), new Number(2.0))
		    ),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Cot * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
		    new Op::Negation(
				new Op::Addition(
					new Number(1.0),
  		            new Op::Power(expression->copy(), new Number(2.0))
				)
		    ),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Sinh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			new Fcn::Cosh(parameterExpr->copy()),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Cosh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
			new Fcn::Sinh(parameterExpr->copy()),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::Tanh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Multiplication(
  		    new Op::Subtraction(
				new Number(1.0),
				new Op::Power(expression->copy(), new Number(2.0))
		    ),
			derivedParameterExprPtr.release()
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArcSin * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			new Fcn::Sqrt(new Op::Subtraction(
				new Number(1.0),
				new Op::Power(parameterExpr->copy(), new Number(2.0))
			))
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArcCos * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Negation(
			new Op::Division(
				derivedParameterExprPtr.release(),
				new Fcn::Sqrt(new Op::Subtraction(
					new Number(1.0),
					new Op::Power(parameterExpr->copy(), new Number(2.0))
				))
			)
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArcTan * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			new Op::Addition(
			    new Number(1.0),
				new Op::Power(parameterExpr->copy(), new Number(2.0))
			)
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArSinh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			new Fcn::Sqrt(new Op::Addition(
				new Op::Power(parameterExpr->copy(), new Number(2.0)),
		    	new Number(1.0)
			))
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArCosh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			new Fcn::Sqrt(new Op::Subtraction(
				new Op::Power(parameterExpr->copy(), new Number(2.0)),
		    	new Number(1.0)
			))
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::ArTanh * expression) {
		ExpressionList * parameters = expression->getParameterList();
		if (parameters->getLength() != 1) {
			throw InvalidFunctionParametersException();
		}

		Expression * parameterExpr = parameters->getExpressionAt(0);
		std::unique_ptr<Expression> derivedParameterExprPtr((Expression *)parameterExpr->accept(this));

		return new Op::Division(
			derivedParameterExprPtr.release(),
			new Op::Subtraction(
				new Number(1.0),
				new Op::Power(parameterExpr->copy(), new Number(2.0))
		    )
		);
	}

	Expression * GetDerivativeVisitor::visit(Fcn::FunctionByIdentifier * expression) {
		// @todo not yet implemented
		throw UnknownIdentifierException(expression->getName());

		return (Expression *)NULL;
	}

}} /* namespace AST::Visitor */
