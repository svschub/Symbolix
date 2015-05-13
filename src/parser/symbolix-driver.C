#include "symbolix-driver.h"
#include "symbolix-parser.hh"


symbolix_driver::symbolix_driver():
    trace_scanning(false),
    trace_parsing(false),
    parsedAST(NULL),
    str_buffer(NULL)
{
}

symbolix_driver::~symbolix_driver()
{
	if (parsedAST != NULL) {
		delete parsedAST;
	}
}

int symbolix_driver::parse(const std::string formulaStr)
{
	str = formulaStr;

	scan_begin();
    yy::symbolix_parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();

    return res;
}

void symbolix_driver::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void symbolix_driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}
