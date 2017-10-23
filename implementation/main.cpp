/*
 * main.cpp
 *
 *  Created on: Sep 28, 2009
 *      Author: hoelldam
 *     Updated: kuswik, 2016
 */

#include "Graph/GraphHandler.h"
#include "Parser/Parser.h"

#include "Analysis-D/AnalysisD.h"
#include "Analysis-STA/AnalysisSTA.h"

int main(int argc, const char** argv) {
    GraphHandler graphHandler;

    Parser::parse(argc, argv, &graphHandler);

    AnalysisD analysisD(&graphHandler);
    analysisD.run();

    AnalysisSTA analysisSTA(&graphHandler);
    analysisSTA.run();

    return 0;
}
