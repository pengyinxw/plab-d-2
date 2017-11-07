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
    std::cout << graphHandler->getElement(5)->getName() << std::endl << "outgoing: \n";
    std::vector<const Net*> outNets = graphHandler->getElement(5)->getOutNets();
    for (const Net* n:outNets)
        std::cout << n->getId() << " , " << n->getName() << std::endl;
    std::cout<<"incoming: \n";
    std::vector<const Net*> inNets = graphHandler->getElement(5)->getInNets();
    for (const Net* n:inNets)
        std::cout << n->getId() << " , " << n->getName() << std::endl;

    std::cout<<"Alle Elemente:"<<std::endl;
    std::vector<const Element*> elems = graphHandler->getAllElements();
    for (const Element* e:elems)
        std::cout << e->getId() << " , " << e->getName() << " , " << e->getElementInfo()->getType() << std::endl;

    std::cout<<"Terminals von C2:"<<std::endl;
    std::vector<const TerminalInfo*> inTerm =  graphHandler->getElement(1)->getElementInfo()->getInputTerminalInfos();
    std::vector<const TerminalInfo*> outTerm =  graphHandler->getElement(1)->getElementInfo()->getOutputTerminalInfos();
    for (const TerminalInfo* t:inTerm)
        std::cout << t->getName() << " , " << t->getType() << std::endl;
    for (const TerminalInfo* t:outTerm)
        std::cout << t->getName() << " , " << t->getType() << std::endl;
}


