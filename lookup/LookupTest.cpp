/**
  * @brief Tests fuer LookupTable
  *
  * @author Daphne Schoessow
  *
  * @date 20.11.2017
  *
  * @version 1.0
  */

#include "LookupTable.h"

/**
 * @brief Output on console to check the funktion easier
 * @param input input value(s) (after lookup)
 * @param output output value (after lookup)
 * @param type gate type
 */

void testOutput(std::vector<Logic> input, Logic output, ElementType type) {
    std::cout<<"Die Funktion ist "<<type<<std::endl;
    if(input.size()>1)
        std::cout<<"Der Input ist "<<input.at(0) << ", " << input.at(1)<<std::endl;
    else
        std::cout<<"Der Input ist "<<input.at(0) <<std::endl;
    std::cout<<"Der Output ist "<<output<<std::endl;
}
/**
 * @brief some testcases for LookupTable
 */
int main() {
    LookupTable lt = LookupTable();
    std::cout<<"---2 bekannte Eingänge---"<<std::endl;
    std::vector<Logic> input = {Logic::logic0, Logic::logic1};
    std::vector<Logic> shortInput ={Logic::logicD};
    Logic output = Logic::logicX;
    Logic out = lt.judge_all(input, output, ElementType::And);
    testOutput(input, out, ElementType::And);
    out=lt.judge_all(input, output, ElementType::Or);
    testOutput(input, out, ElementType::Or);
    out = lt.judge_all(shortInput, output, ElementType::Not);
    testOutput(shortInput, out, ElementType::Not);

    std::cout<<"---Input1 bekannt, bekannter Ausgang---"<<std::endl;
    input = {Logic::logic1, Logic::logicX};
    shortInput ={Logic::logicX};
    output =Logic::logic0;
    out = lt.judge_all(input, output, ElementType::And);
    std::vector<Logic> returnedInput = {input.at(0), out};
    testOutput(returnedInput, output, ElementType::And);
    out=lt.judge_all(input, output, ElementType::Or);
    returnedInput = {input.at(0), out};
    testOutput(returnedInput, output, ElementType::Or);
    out = lt.judge_all(shortInput, output, ElementType::Not);
    returnedInput = {out};
    testOutput(returnedInput, output, ElementType::Not);

    std::cout<<"---Input2 bekannt, bekannter Ausgang---"<<std::endl;
    input = {Logic::logicX, Logic::logic0};
    output =Logic::logic1;
    out = lt.judge_all(input, output, ElementType::And);
    returnedInput = {out, input.at(1)};
    testOutput(returnedInput, output, ElementType::And);
    out=lt.judge_all(input, output, ElementType::Or);
    returnedInput = {out, input.at(1)};
    testOutput(returnedInput, output, ElementType::Or);

    return 0;
}
