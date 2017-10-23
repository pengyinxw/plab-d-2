/*
 * Tutorial.h
 *
 *  Created on: Oct 21, 2009
 *      Author: zhang
 */

#ifndef TUTORIAL_H_
#define TUTORIAL_H_
#include <memory>
// forward declarations
class GraphHandler;

class Tutorial {
public:
	Tutorial();
	
	void run();
	// prevent from using the copy constructor
	Tutorial(const Tutorial&) = delete;
	// prevent from using the assignment operator
	Tutorial& operator=(const Tutorial&) = delete;
	// use virtual destructor
	virtual ~Tutorial() = default;
private:
	std::shared_ptr<GraphHandler>   const graphHandler;
};

#endif /* TUTORIAL_H_ */
