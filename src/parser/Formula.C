
#include <memory>

#include "Formula.h"
#include "FormulaException.h"


void Formula::setFormulaString(std::string formulaStr) {
	formula = formulaStr;
}

void Formula::setFormulaExpr(Expression * expr) {
	formulaExpr = expr;
}

int Formula::parse() {
	int parseResultCode = driver.parse(formula);

	if (parseResultCode == 0) {
		formulaExpr = driver.parsedAST;
	} else {
		formulaExpr = NULL;
		throw FormulaException("error parsing formula");
	}

	return parseResultCode;
}


Formula::Formula(): formulaExpr(NULL) {
}

Formula::Formula(const Formula& f): formula(f.formula) {
	std::cout << "Formula copy constructor" << std::endl;
    if (f.formulaExpr != NULL) {
    	formulaExpr = f.formulaExpr->copy();
    } else {
    	formulaExpr = NULL;
    }
}

Formula::Formula(const char * formulaStr):
	formula(std::string(formulaStr)),
	formulaExpr(NULL) {
	parse();
}

Formula::Formula(std::string formulaStr):
	formula(formulaStr),
	formulaExpr(NULL) {
	parse();
}

Formula::Formula(Expression * expression):
	formulaExpr(expression) {
}

Formula::~Formula() {
	using AST::Expression::Number;

	if (variables.size() > 0) {
		for (std::unordered_map<std::string, Number*>::iterator variablesIterator=variables.begin();
			 variablesIterator != variables.end();
		     ++variablesIterator) {

			Number * expression = (*variablesIterator).second;
			delete expression;
		}
	}
}


std::string Formula::getFormulaString() {
	return formula;
}

Formula& Formula::setVariable(const char * varName, double value) {
	using AST::Expression::Number;

	std::string name(varName);
	Number * numExpr;

	if (variables.find(name) != variables.end()) {
    	numExpr = (Number *)variables[name];
    	numExpr->setValue(value);
    } else {
    	numExpr = new Number(value);
    	variables[name] = numExpr;
    }

    return *this;
}

Formula& Formula::unsetVariable(const char * varName) {
	std::string name(varName);

	if (variables.find(name) != variables.end()) {
        delete variables[name];
        variables.erase(name);
    }

    return *this;
}

double Formula::evaluate() {
    using AST::Expression::Number;
    using AST::Visitor::GetResultVisitor;
    using AST::Visitor::Scope;

    if (formulaExpr == NULL) {
    	throw FormulaException("invalid formula");
    }

    std::unique_ptr<GetResultVisitor> getResultVisitorPtr(new GetResultVisitor());

    if (variables.size() > 0) {
     	std::string varName;
       	Number * numExpr;
       	Scope * currentScope = getResultVisitorPtr.get()->getCurrentScope();

    	for (std::unordered_map<std::string, Number*>::iterator variablesIterator=variables.begin();
    		 variablesIterator != variables.end();
    	     ++variablesIterator) {

    		varName = (*variablesIterator).first;
    		numExpr = (*variablesIterator).second;
    		currentScope->setExpressionByIdentifier(varName, numExpr->copy());
    	}
    }

    std::unique_ptr<Number> resultExprPtr((Number *)formulaExpr->accept(getResultVisitorPtr.get()));

    return resultExprPtr.get()->getValue();
}

Formula Formula::differentiateWithRespectTo(std::string varName) {
	using AST::Expression::Expression;
	using AST::Expression::Text;
    using AST::Visitor::GetDerivativeVisitor;
    using AST::Visitor::StringifyVisitor;
    using AST::Visitor::SimplifyVisitor;

    if (formulaExpr == NULL) {
    	throw FormulaException("invalid formula");
    }

	std::unique_ptr<GetDerivativeVisitor> getDerivativeVisitorPtr(new GetDerivativeVisitor());
	std::unique_ptr<SimplifyVisitor> simplifyVisitorPtr(new SimplifyVisitor());
	std::unique_ptr<StringifyVisitor> stringifyVisitorPtr(new StringifyVisitor());

	getDerivativeVisitorPtr.get()->setDerivativeVariableName(varName);

    std::unique_ptr<Expression> derivativeExprPtr((Expression *)formulaExpr->accept(getDerivativeVisitorPtr.get()));
	std::unique_ptr<Expression> simplifiedDerivativeExprPtr((Expression *)derivativeExprPtr.get()->accept(simplifyVisitorPtr.get()));
    std::unique_ptr<Text> stringifiedDerivativeExprPtr((Text *)simplifiedDerivativeExprPtr.get()->accept(stringifyVisitorPtr.get()));

	Formula derivative;
    derivative.setFormulaString(stringifiedDerivativeExprPtr.get()->getContent());
    derivative.setFormulaExpr(simplifiedDerivativeExprPtr.release());

	return derivative;
}

Formula Formula::differentiateWithRespectTo(const char * varName) {
	return differentiateWithRespectTo(std::string(varName));
}


std::ostream& operator<<(std::ostream& stream, const Formula& f) {
    stream << f.formula;
    return stream;
}
