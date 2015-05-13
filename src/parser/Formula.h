
#ifndef FORMULA_H_
#define FORMULA_H_

#include <string>
#include <iostream>
#include <unordered_map>

#include "symbolix-driver.h"
#include "../AST/AST.h"


using AST::Expression::Expression;
using AST::Expression::Number;


class Formula {
    symbolix_driver driver;
    std::string formula;
    Expression * formulaExpr;
    std::unordered_map<std::string, Number*> variables;

	void setFormulaString(std::string formulaStr);
	void setFormulaExpr(Expression * expr);
    int parse();

public:
	Formula();
	Formula(const Formula& f);
	Formula(const char * formulaStr);
	Formula(std::string formulaStr);
	Formula(Expression * expression);
	virtual ~Formula();

	std::string getFormulaString();
	Formula& setVariable(const char * varName, double value);
	Formula& unsetVariable(const char * varName);

	double evaluate();
	Formula differentiateWithRespectTo(std::string varName);
	Formula differentiateWithRespectTo(const char * varName);

    friend std::ostream& operator<<(std::ostream& stream, const Formula& f);
};

#endif /* FORMULA_H_ */
