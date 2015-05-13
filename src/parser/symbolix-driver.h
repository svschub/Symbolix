#ifndef SYMBOLIX_DRIVER_HH
#define SYMBOLIX_DRIVER_HH

#include <string>
#include <map>
#include "symbolix-parser.hh"
#include "../AST/AST.h"


#define YY_DECL                                        \
  yy::symbolix_parser::token_type                         \
  yylex(yy::symbolix_parser::semantic_type* yylval,      \
        yy::symbolix_parser::location_type* yylloc,      \
        symbolix_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;


using AST::Expression::Expression;

// Conducting the whole scanning and parsing.
class symbolix_driver
{

public:
    // Whether scanner traces should be generated.
    bool trace_scanning;
    // Whether parser traces should be generated.
    bool trace_parsing;

    // parsed abstract syntax tree of the formula.
    Expression * parsedAST;

    std::string str;
    void * str_buffer;

    symbolix_driver();
    virtual ~symbolix_driver();

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // Run the parser on file F.
    // Return 0 on success.
    int parse(const std::string formulaStr);

    // Error handling.
    void error(const yy::location& l, const std::string& m);
    void error(const std::string& m);
};

#endif // ! SYMBOLIX_DRIVER_HH
