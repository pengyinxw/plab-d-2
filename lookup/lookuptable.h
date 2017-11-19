#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include "../api/include/template.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class LookupTable
{
   ElementType gatetype;
public:
    LookupTable();
    ~LookupTable();
    std::vector<Logic>input;
   Logic judgement(std::vector<Logic>input,ElementType type);
   Logic judge_all(std::vector<Logic> input, Logic output, ElementType type);

private:
    Logic lookupAnd(std::vector<Logic>input);
    Logic lookupOr(std::vector<Logic>input);
    Logic lookupNot(Logic input);
    Logic lookupXnor(std::vector<Logic>input);
    Logic lookupXor(std::vector<Logic>input);
    Logic lookupNand(std::vector<Logic>input);
    Logic lookupNor(std::vector<Logic>input);

    int tablookupAnd[5][5] = {
        {0,0,0,0,0},
        {0,1,2,3,4},
        {0,2,2,2,2},
        {0,3,2,3,0},
        {0,4,2,0,4}
    };
    int tablookupOr[5][5] = {
        {0,1,2,3,4},
        {1,1,1,1,1},
        {2,1,2,2,2},
        {3,1,2,3,1},
        {4,1,2,1,4}
    };
    int tablookupXnor[5][5] = {
        {1,0,2,4,3},
        {0,1,2,3,4},
        {2,2,2,2,2},
        {4,3,2,1,0},
        {3,4,2,0,1}
    };
    int tablookupXor[5][5] = {
        {0,1,2,3,4},
        {1,0,2,4,3},
        {2,2,2,2,2},
        {3,4,2,0,1},
        {4,3,2,1,0}
    };
    int tablookupNand[5][5] = {
        {1,1,1,1,1},
        {1,0,2,4,3},
        {1,2,2,2,2},
        {1,4,2,4,1},
        {1,3,2,1,3}
    };
    int tablookupNor[5][5] = {
        {1,0,2,4,3},
        {0,0,0,0,0},
        {2,0,2,2,2},
        {4,0,2,4,0},
        {3,0,2,0,3}
    };
    int tablookupNot[5] = { 1,0,2,4,3};
    
};

#endif // LOOKUPTABLE_H
//LogicX = 2;
//LogicD = 3;
//LogicnotD = 4;
