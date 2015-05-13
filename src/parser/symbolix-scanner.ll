%{ /* -*- C++ -*- */
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <string>
#include "symbolix-driver.h"
#include "symbolix-parser.hh"

/* Work around an incompatibility in flex (at least versions
   2.5.31 through 2.5.33): it generates code that does
   not conform to C89.  See Debian bug 333231
   <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.  */
#undef yywrap
#define yywrap() 1

/* By default yylex returns int, we use token_type.
   Unfortunately yyterminate by default returns 0, which is
   not of token_type.  */
#define yyterminate() return token::END
%}

%option noyywrap nounput batch debug

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}


%%
%{
    typedef yy::symbolix_parser::token token;
%}

%{
  yylloc->step();
%}

[ \t]                                 { yylloc->step(); }
[0-9]+(\.[0-9]+)?(e(\+|\-)?[0-9]+)?   { yylval->dval = atof(yytext); return token::NUMBER; }
[\(\),=^\+\-\*\/]                     { return yy::symbolix_parser::token_type(yytext[0]); }
[a-zA-Z\_][a-zA-z0-9\_]*              { yylval->sval = new std::string(yytext); return token::IDENTIFIER; }
[\n]+                                 { yylloc->lines(yyleng); yylloc->step(); }
.                                     { driver.error(*yylloc, "invalid character"); }

%%

void symbolix_driver::scan_begin()
{
    yy_flex_debug = trace_scanning;
    
    YY_BUFFER_STATE string_buffer = yy_scan_string(str.c_str());
    str_buffer = (void *)string_buffer;

    yy_switch_to_buffer(string_buffer);
}

void symbolix_driver::scan_end()
{
    YY_BUFFER_STATE string_buffer = (YY_BUFFER_STATE)str_buffer;
    yy_delete_buffer(string_buffer);
}

