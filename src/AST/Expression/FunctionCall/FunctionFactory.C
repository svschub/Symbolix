
#include "FunctionCall.h"

#include "BasicFunctions.h"
#include "FunctionByIdentifier.h"

#include "FunctionFactory.h"


namespace AST { namespace Expression { namespace FunctionCall {

    FunctionCall * FunctionFactory::getInstanceByName(std::string functionName) {
    	FunctionCall * functionCall;

    	if (functionName == "sqrt") {
    		functionCall = new Sqrt();
    	} else if (functionName == "exp") {
    		functionCall = new Exp();
    	} else if (functionName == "ln") {
    	    functionCall = new Ln();
    	} else if (functionName == "sin") {
    		functionCall = new Sin();
    	} else if (functionName == "cos") {
    		functionCall = new Cos();
    	} else if (functionName == "tan") {
    		functionCall = new Tan();
    	} else if (functionName == "cot") {
    		functionCall = new Cot();
    	} else if (functionName == "asin") {
    		functionCall = new ArcSin();
    	} else if (functionName == "acos") {
    		functionCall = new ArcCos();
    	} else if (functionName == "atan") {
    		functionCall = new ArcTan();
    	} else if (functionName == "sinh") {
    		functionCall = new Sinh();
    	} else if (functionName == "cosh") {
    		functionCall = new Cosh();
    	} else if (functionName == "tanh") {
    		functionCall = new Tanh();
    	} else if (functionName == "asinh") {
    		functionCall = new ArSinh();
    	} else if (functionName == "acosh") {
    		functionCall = new ArCosh();
    	} else if (functionName == "atanh") {
    		functionCall = new ArTanh();
    	} else {
    		functionCall = new FunctionByIdentifier(functionName);
    	}

    	return functionCall;
	}

}}}

