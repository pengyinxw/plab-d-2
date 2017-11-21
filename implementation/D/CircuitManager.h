#ifndef CIRCUITMANAGER_H
#define CIRCUITMANAGER_H

/**
  * @brief ?
  *
  * @author ?
  *
  * @date ??.11.2017
  *
  * @version 1.0
  */

#include <string>

class CircuitManager
{
private:
    setNetId(size_t netid);
    setErrorType(std::string errorType);
public:
    CircuitManager();
    void init(int netId);
};

#endif // CIRCUITMANAGER_H
