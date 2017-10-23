/*
 * AnalysisSTA.h
 *
 *  Created on: Sep 28, 2009
 *      Author: hoelldam
 *     Updated: kuswik, 2016
 */

#ifndef ANALYSISSTA_H_
#define ANALYSISSTA_H_

// forward declarations
class GraphHandler;

class AnalysisSTA {
public:
    AnalysisSTA(const GraphHandler* graphHandler) :
        graphHandler(graphHandler) {
    }
    virtual ~AnalysisSTA() {
    }

    void run();

private:
    // prevent from using the default constructor, copy constructor and assignment operator
    AnalysisSTA();
    AnalysisSTA(const AnalysisSTA&);
    AnalysisSTA& operator=(const AnalysisSTA&);

    const GraphHandler* graphHandler;
};

#endif /* ANALYSISSTA_H_ */
