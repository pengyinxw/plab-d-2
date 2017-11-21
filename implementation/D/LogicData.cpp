/**
  * @brief Core datastructure for gates of circuitmanager.  
  *
  * @author Daphne Schoessow
  *
  * @date 21.11.2017
  *
  * @version 1.0
  */

#include "LogicData.h"

LogicData::LogicData(ElementType gate, std::vector<Logic> in, Logic out)
:gateType(gate), input(in), output(out), complete(0) {}

LogicData::LogicData(ElementType gate, std::vector<Logic> in, Logic out, std::vector<int> netIn, int netOut)
:gateType(gate), input(in), output(out), netidIn(netIn), netidOut(netOut), complete(0) {}


ElementType getType() {
    return LogicData::gateType;
}

std::vector<Logic> getInput() {
    return LogicData::input;
}

Logic getOutput() {
    return LogicData::output;
}

std::vector<int> getNetIdIn() {
    return LogicData::netidIn;
}

int getNetIdOut() {
    return LogicData::netidOut;
}

bool getComplete() {
    return LogicData::complete;
}

void setInput(std::vector<Logic> newInput) {
    LogicData::input = newInput;
}

void setOutput(Logic newOutput) {
    LogicData::output = newOutput;
}

void setComplete(bool newComplete) {
    LogicData::complete = newComplete;
}
