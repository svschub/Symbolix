
#ifndef AST__VISITOR__SCOPE_H_
#define AST__VISITOR__SCOPE_H_

#include <string>
#include <unordered_map>

#include "../Expression/Expression.h"


namespace AST { namespace Visitor {

    using AST::Expression::Expression;


    class Scope {
    	Scope * parentScope;
		std::unordered_map<std::string, Expression*> variables;
	public:
		Scope();
		virtual ~Scope();

		virtual void setParentScope(Scope * parent);
	    virtual Scope * getParentScope();

	    virtual Expression * getExpressionByIdentifier(std::string name);
	    virtual void setExpressionByIdentifier(std::string name, Expression * expression);
	    virtual void removeExpressionByIdentifier(std::string name);
	};

}} /* namespace AST::Visitor */

#endif /* AST__VISITOR__SCOPE_H_ */
