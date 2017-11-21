#ifndef LOGICDATA_H
#define LOGICDATA_H

/**
  * @brief Header for LogicData
  *
  * @author Daphne Schoessow
  *
  * @date 21.11.2017
  *
  * @version 1.0
  */

#include "../../api/include/template.h"
#include <vector>

class LogicData
{
    private:
        const ElementType gateType;
        std::vector<Logic> input;
        Logic output;
        std::vector<int> netidIn;
        int netidOut;
        bool complete;

    public:
        LogicData(ElementType gate, std::vector<Logic> in, Logic out);
        LogicData(ElementType gate, std::vector<Logic> in, Logic out, std::vector<int> netIn, int netOut);
        ElementType getType();
        std::vector<Logic> getInput();
        Logic getOutput();
        void setInput(std::vector<Logic> newInput);
        void setOutput(Logic newOutput);

};

#endif // LOGICDATA_H
