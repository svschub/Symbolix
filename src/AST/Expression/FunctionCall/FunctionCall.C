
#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::ExpressionList;


    FunctionCall::FunctionCall(): parameterList(0) {
	}

    FunctionCall::FunctionCall(const FunctionCall& fcnCallExpr) {
    	parameterList = new ExpressionList(*fcnCallExpr.parameterList);
    }

    /**
     * Constructur to create a function call with one argument
     */
    FunctionCall::FunctionCall(Expression * paramExpr) {
    	parameterList = new ExpressionList();
    	parameterList->add(paramExpr);
    }

    FunctionCall::~FunctionCall() {
    	if (parameterList != 0) {
    		delete parameterList;
    	}
	}


    int FunctionCall::getType() {
		return FunctionCall::TYPE;
	}

    void FunctionCall::setParameterList(ExpressionList * paramList) {
		parameterList = paramList;
    }

    ExpressionList * FunctionCall::getParameterList() {
        return parameterList;
    }
}}}
