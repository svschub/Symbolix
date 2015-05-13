
#include "FunctionByIdentifier.h"
#include "../../Visitor/Visitor.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Visitor::Visitor;


    FunctionByIdentifier::FunctionByIdentifier(std::string name): FunctionCall() {
    	functionName = name;
	}

    FunctionByIdentifier::FunctionByIdentifier(const FunctionByIdentifier& fcnExpr): FunctionCall(fcnExpr), functionName(fcnExpr.functionName) {
	}

    FunctionByIdentifier::FunctionByIdentifier(Expression * paramExpr): FunctionCall(paramExpr) {
	}

    FunctionByIdentifier::~FunctionByIdentifier() {
	}


    Expression * FunctionByIdentifier::copy() {
    	return new FunctionByIdentifier(*this);
    }

    std::string FunctionByIdentifier::getName() {
    	return functionName;
    }

	Expression * FunctionByIdentifier::accept(Visitor * visitor) {
        return visitor->visit(this);
	}

}}}

