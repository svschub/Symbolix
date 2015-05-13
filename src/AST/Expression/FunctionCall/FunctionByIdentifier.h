
#ifndef AST__EXPRESSION__FUNCTIONCALL__FUNCTIONBYIDENTIFIER_H_
#define AST__EXPRESSION__FUNCTIONCALL__FUNCTIONBYIDENTIFIER_H_

#include <string>
#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

    using AST::Expression::Expression;
    using AST::Visitor::Visitor;


    class FunctionByIdentifier: public FunctionCall {
    	std::string functionName;
	public:
    	FunctionByIdentifier(std::string name);
    	FunctionByIdentifier(const FunctionByIdentifier& fcnExpr);
    	FunctionByIdentifier(Expression * paramExpr);
		virtual ~FunctionByIdentifier();

		virtual Expression * copy();
		virtual std::string getName();
		virtual Expression * accept(Visitor * visitor);
	};

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__FUNCTIONBYIDENTIFIER_H_ */
