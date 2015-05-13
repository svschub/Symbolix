
#include "Visitor.h"
#include <iostream>


namespace AST { namespace Visitor {

	Visitor::Visitor() {
		Scope * scope = new Scope();
		scopes.push(scope);
		globalScope = scope;
	}

	Visitor::~Visitor() {
		removeScopes();
	}

	int Visitor::pushScope() {
		Scope * scope = new Scope();

		std::cout << "pushScope(): size=" << scopes.size() << std::endl;
		if (!scopes.empty()) {
            scope->setParentScope(scopes.top());
		}

		scopes.push(scope);

		return scopes.size();
	}

	int Visitor::popScope() {
		if (!scopes.empty()) {
			Scope * currentScope = scopes.top();
			delete currentScope;
			scopes.pop();

			if (scopes.empty()) {
				globalScope = (Scope *)NULL;
			}
		}

		return scopes.size();
	}

	void Visitor::removeScopes() {
		while (popScope() > 0) {
		}
	}

	Scope * Visitor::getCurrentScope() {
		Scope * currentScope;

        if (!scopes.empty()) {
        	currentScope = scopes.top();
        } else {
        	currentScope = (Scope *)NULL;
        }

        return currentScope;
	}

	Scope * Visitor::getGlobalScope() {
        return globalScope;
	}

	void Visitor::clearScopes() {
		removeScopes();
	    pushScope();
	}

}} /* namespace AST::Visitor */
