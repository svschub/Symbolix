
#include <math.h>
#include <iostream>
#include <exception>
#include <memory>

#include "../AST/AST.h"


int main()
{
	using AST::Expression::Expression;
	using AST::Expression::ExpressionList;
	using AST::Expression::Number;
	using AST::Expression::Variable;
	using AST::Expression::Text;
    using AST::Visitor::GetResultVisitor;
    using AST::Visitor::GetDerivativeVisitor;
    using AST::Visitor::StringifyVisitor;
    using AST::Visitor::SimplifyVisitor;

	namespace Op = AST::Expression::Operation;
	namespace Fcn = AST::Expression::FunctionCall;

/*
	ExpressionList * parameters = new ExpressionList();
	parameters->add(new Number(1.0));
	Fcn::FunctionCall * sinFcn = Fcn::FunctionFactory::getInstanceByName(std::string("sin"));
	sinFcn->setParameterList(parameters);
*/
	std::unique_ptr<Expression> formulaExprPtr(new Op::Multiplication(
		new Number(2.0),
		new Fcn::Sin(
//		    new Op::Addition(new Number(1.0), new Variable(std::string("x"))))
            new Variable(std::string("x"))
	    )
	));

	std::unique_ptr<Expression> formulaExprPtr2(formulaExprPtr.get()->copy());

	std::unique_ptr<GetResultVisitor> getResultVisitorPtr(new GetResultVisitor());
	getResultVisitorPtr.get()->getCurrentScope()->setExpressionByIdentifier(std::string("x"), new Number(1.0));

	std::unique_ptr<StringifyVisitor> stringifyVisitorPtr(new StringifyVisitor());

	std::unique_ptr<GetDerivativeVisitor> getDerivativeVisitorPtr(new GetDerivativeVisitor());
	getDerivativeVisitorPtr.get()->setDerivativeVariableName(std::string("x"));

	std::unique_ptr<SimplifyVisitor> SimplifyVisitorPtr(new SimplifyVisitor());

	try {
        std::cout << "Result(*): " << (double)(2*sin(1.0+1.0)) << std::endl;

        std::unique_ptr<Text> textExprPtr((Text *)formulaExprPtr.get()->accept(stringifyVisitorPtr.get()));
        std::cout << "Formula: " << textExprPtr.get()->getContent() << std::endl;

        std::unique_ptr<Number> resultExprPtr((Number *)formulaExprPtr.get()->accept(getResultVisitorPtr.get()));
        std::cout << "Result: " << resultExprPtr.get()->getValue() << std::endl;

        std::unique_ptr<Number> resultExprPtr2((Number *)formulaExprPtr2.get()->accept(getResultVisitorPtr.get()));
        std::cout << "Result2: " << resultExprPtr2.get()->getValue() << std::endl;

        std::unique_ptr<Expression> derivativeExprPtr((Expression *)formulaExprPtr.get()->accept(getDerivativeVisitorPtr.get()));
        std::unique_ptr<Text> stringifiedDerivativeExprPtr((Text *)derivativeExprPtr.get()->accept(stringifyVisitorPtr.get()));
        std::cout << "Derivative: " << stringifiedDerivativeExprPtr.get()->getContent() << std::endl;

        std::unique_ptr<Expression> simplifiedDerivativeExprPtr((Expression *)derivativeExprPtr.get()->accept(SimplifyVisitorPtr.get()));
        std::unique_ptr<Text> stringifiedDerivativeExprPtr2((Text *)simplifiedDerivativeExprPtr.get()->accept(stringifyVisitorPtr.get()));
        std::cout << "simplified Derivative: " << stringifiedDerivativeExprPtr2.get()->getContent() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error evaluating formula: " << e.what() << std::endl;
	}
}
