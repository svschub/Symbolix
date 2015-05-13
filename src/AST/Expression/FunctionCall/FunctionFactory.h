
#ifndef AST__EXPRESSION__FUNCTIONCALL__FUNCTIONFACTORY_H_
#define AST__EXPRESSION__FUNCTIONCALL__FUNCTIONFACTORY_H_

#include <string>
#include "FunctionCall.h"


namespace AST { namespace Expression { namespace FunctionCall {

	class FunctionFactory {
		public:
		    static FunctionCall * getInstanceByName(std::string functionName);
    };

}}}

#endif /* AST__EXPRESSION__FUNCTIONCALL__FUNCTIONFACTORY_H_ */
