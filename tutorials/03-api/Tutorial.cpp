/*
 * Tutorial.cpp
 *
 *  Created on: Oct 21, 2009
 *      Author: zhang
 */

#include "Tutorial.h"

#include "Graph/Element.h"
#include "Graph/GraphHandler.h"
#include "Library/ElementInfo.h"
#include "Library/TerminalInfo.h"
#include "Parser/Parser.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

Tutorial::Tutorial() :
	graphHandler(std::make_shared<GraphHandler>()) {
}

void Tutorial::run() {
	std::vector<const char*> argv = {
			"./api_tutorial",                   // executed binary
			"../../examples/circuit01.yal", // yal file name
			"CIRCUIT01",                    // top-level cell name
			"../../examples/library.yal"    // lib file name
	};

	Parser::parse(argv.size(), &argv[0], graphHandler.get());

	//insert code here

}


