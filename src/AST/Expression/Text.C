
#include "Text.h"
#include "../Visitor/Visitor.h"


namespace AST { namespace Expression {

    using AST::Visitor::Visitor;


	Text::Text(std::string text) {
		content = text;
	}

	Text::Text(const Text& textExpr): content(textExpr.content) {
	}

	Text::~Text() {
	}


	int Text::getType() {
		return Text::TYPE;
	}

	Expression * Text::copy() {
		return new Text(*this);
	}

	Expression * Text::accept(Visitor * visitor) {
		return visitor->visit(this);
	}

	std::string Text::getContent() {
		return content;
	}

}}
