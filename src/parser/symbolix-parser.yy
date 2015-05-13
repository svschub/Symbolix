%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "2.6.90.8-d4fe"

%defines
%define parser_class_name { symbolix_parser }

%code requires {
#include <math.h>
#include <string>
#include <iostream>

#include "../AST/AST.h"

using AST::Expression::Expression;
using AST::Expression::ExpressionList;
using AST::Expression::Number;
using AST::Expression::Variable;
namespace Op = AST::Expression::Operation;
namespace Fcn = AST::Expression::FunctionCall;

class symbolix_driver;
}

// The parsing context.
%parse-param { symbolix_driver& driver }
%lex-param   { symbolix_driver& driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.str;
};

%debug
%error-verbose

// Symbols.
%union
{
    double            dval;
    std::string       *sval;
    Expression        *exprPtr;
    ExpressionList    *exprListPtr;
    Fcn::FunctionCall *fcnCallPtr;
};

%code {
#include "symbolix-driver.h"
}

%token END 0 "end of file"
%token NUMBER IDENTIFIER NEG
%type <sval>         IDENTIFIER "identifier"
%type <dval>         NUMBER     "number"
%type <exprPtr>      exp        "expression" 
%type <exprListPtr>  list
%type <fcnCallPtr>   fcn


%left '+' '-';
%left '*' '/';
%precedence NEG;   /* negation--unary minus */
%right '^';        /* exponentiation */

%destructor { delete $$; } IDENTIFIER exp list fcn

%%
%start unit;

unit: 
    exp                          { driver.parsedAST = $1; }
    ;

list:
    exp                          { $$ = new ExpressionList(); $$->add($1); }
    | list ',' exp               { $1->add($3); $$ = $1; }
    ;

fcn:
    IDENTIFIER '(' list ')'      { $$ = Fcn::FunctionFactory::getInstanceByName(*$1); $$->setParameterList($3); delete $1; }
    ;

exp:
    exp '+' exp                  { $$ = new Op::Addition($1, $3); }
    | exp '-' exp                { $$ = new Op::Subtraction($1, $3); }
    | exp '*' exp                { $$ = new Op::Multiplication($1, $3); }
    | exp '/' exp                { $$ = new Op::Division($1, $3); }
    | exp '^' exp                { $$ = new Op::Power($1, $3); }
    | '-' exp %prec NEG          { $$ = new Op::Negation($2); }
    | '(' exp ')'                { $$ = $2; }
    | fcn                        { $$ = $1; }
    | IDENTIFIER                 { $$ = new Variable(*$1); delete $1; }
    | NUMBER                     { $$ = new Number($1); }
    ;

%%
void yy::symbolix_parser::error(const yy::symbolix_parser::location_type& l, const std::string& m)
{
    driver.error(l, m);
}
