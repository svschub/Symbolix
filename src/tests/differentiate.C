#include <string>
#include <iostream>
#include <exception>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "../parser/Formula.h"


int main(int argc, char *argv[])
{
	namespace po = boost::program_options;
	namespace fs = boost::filesystem;

	po::options_description desc("Allowed options");
	desc.add_options()
   	    ("formula", po::value<std::string>(), "formula to parse")
   	    ("diff", po::value<std::string>(), "variable to differentiate with respect to")
	;

	po::variables_map varMap;
	po::store(po::parse_command_line(argc, argv, desc), varMap);
	po::notify(varMap);

	if (varMap.count("formula") == 0) {
	    std::cout << "Usage: " << fs::basename(argv[0]) << " --formula <formula to parse> --diff <variable name>" << std::endl;
	    return 0;
	}

	if (varMap.count("diff") == 0) {
	    std::cout << "Usage: " << fs::basename(argv[0]) << " --formula <formula to parse> --diff <variable name>" << std::endl;
	    return 0;
	}

	std::string formulaStr(varMap["formula"].as<std::string>());
	std::string diffVarStr(varMap["diff"].as<std::string>());

	try {
            Formula formula(formulaStr);
            Formula derivative = formula.differentiateWithRespectTo(diffVarStr);

	    std::cout << derivative << std::endl;
	} catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}

    return 0;
}

