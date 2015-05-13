
#include "Scope.h"


namespace AST { namespace Visitor {

	Scope::Scope() {
		parentScope = (Scope *)0;
	}

	Scope::~Scope() {
		if (variables.size() > 0) {
			for (std::unordered_map<std::string, Expression*>::iterator variablesIterator=variables.begin();
				 variablesIterator != variables.end();
			     ++variablesIterator) {

				Expression * expression = (*variablesIterator).second;
				delete expression;
			}
		}
	}

	void Scope::setParentScope(Scope * parent) {
		parentScope = parent;
	}

	Scope * Scope::getParentScope() {
		return parentScope;
	}

	Expression * Scope::getExpressionByIdentifier(std::string name) {
		Expression * expression;

        if (variables.find(name) != variables.end()) {
            expression = variables[name];
        } else {
        	expression = (Expression *)0;
        }

        return expression;
	}

	void Scope::setExpressionByIdentifier(std::string name, Expression * expression) {
        if (variables.find(name) != variables.end()) {
            delete variables[name];
        }

        variables[name] = expression;
	}

	void Scope::removeExpressionByIdentifier(std::string name) {
        if (variables.find(name) != variables.end()) {
            delete variables[name];
            variables.erase(name);
        }
	}

}} /* namespace AST::Visitor */
