/*
 * AnalysisD.h
 *
 *  Created on: Sep 28, 2009
 *      Author: hoelldam
 *     Updated: kuswik, 2016
 */

#ifndef ANALYSISD_H_
#define ANALYSISD_H_

// forward declarations
class GraphHandler;

class AnalysisD {
public:
    AnalysisD(const GraphHandler* graphHandler) :
        graphHandler(graphHandler) {
    }
    virtual ~AnalysisD() {
    }

    void run();

private:
    // prevent from using the default constructor, copy constructor and assignment operator
    AnalysisD();
    AnalysisD(const AnalysisD&);
    AnalysisD& operator=(const AnalysisD&);

    const GraphHandler* graphHandler;
};

#endif /* ANALYSISD_H_ */
