#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include "template.h"
#include<vector>
#include<iostream>
#include<string>

class LookupTable
{
   ElementType gatetype;
public:
    LookupTable();
    ~LookupTable();
    std::vector<Logic>input;
   Logic judgement(vector<Logic>input,ElementType type);

private:
    Logic lookupAnd();
    Logic lookupOr();
    Logic lookupNot();
    Logic lookupXnor();
    Logic lookupXor();
    Logic lookupNand();
    Logic lookupNor();

    int lookupAnd[5][5] = {
                         {0,0,0,0,0},
                         {0,1,2,3,4},
                         {0,2,2,2,2},
                         {0,3,2,3,0},
                         {0,4,2,0,4}
    };
    int lookupOr[5][5] = {
                          {0,1,2,3,4},
                          {1,1,1,1,1},
                          {2,1,2,2,2},
                          {3,1,2,3,1},
                          {4,1,2,1,4}

    };
    int lookupNot[5] = { 1,0,2,4,3};
    int lookupXnor[5][5] = {
                         {1,0,2,4,3},
                         {0,1,2,3,4},
                         {2,2,2,2,2},
                         {4,3,2,1,0},
                         {3,4,2,0,1}
};
    int lookupXor[5][5] = {
                         {0,1,2,3,4},
                         {1,0,2,4,3},
                         {2,2,2,2,2},
                         {3,4,2,0,1},
                         {4,3,2,1,0}
};
    int lookupNand[5][5] = {
                        {1,1,1,1,1},
                        {1,0,2,4,3},
                        {1,2,2,2,2},
                        {1,4,2,4,1},
                        {1,3,2,1,3}
};
    int lookupNor[5][5] = {
                            {1,0,2,4,3},
                            {0,0,0,0,0},
                            {2,0,2,2,2},
                            {4,0,2,4,0},
                            {3,0,2,0,3}
    };

};

#endif // LOOKUPTABLE_H
//LogicX = 2;
//LogicD = 3;
//LogicnotD = 4;
