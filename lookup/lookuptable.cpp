#include "lookuptable.h"

LookupTable::LookupTable(){
}

Logic  LookupTable::lookupAnd(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupAnd[m][n]);
}

Logic  LookupTable::lookupOr(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupOr[m][n]);
}

Logic  LookupTable::lookupNot(Logic input) {
    return Logic(tablookupNot[int(input)]);
}

Logic  LookupTable::lookupXnor(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupXnor[m][n]);
}

Logic  LookupTable::lookupXor(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupXor[m][n]);
}

Logic  LookupTable::lookupNand(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupNand[m][n]);
}

Logic  LookupTable::lookupNor(std::vector<Logic>input) {
    int n,m;
    n = int(input.at(0));
    m = int(input.at(1));
    return Logic(tablookupNor[m][n]);
}

Logic LookupTable::judgement(std::vector<Logic> input, ElementType type) {
    int n,m;

    n = int(input.at(0));

    if(input.size() == 2) { // NOT needs only one input: there is no second one
        m = int(input.at(1));
    }

    switch (type) {
    case ElementType::And:
        return Logic(tablookupAnd[m][n]);
    case ElementType::Or:
        return Logic(tablookupOr[m][n]);
    case ElementType::Not:
        return Logic(tablookupNot[n]);;
    default:
        assert(false);
        break;
    }
}

 /*   if (type==ElementType.And ){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupAnd(input)<<std::endl;
        Logic test = LookupTable::lookupAnd(input);
        return  Logic(1);
    } else if (type==ElementType.Or){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupOr(input)<<std::endl;
        return  lookupOr(input);
    }else if (type==ElementType.Not){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupNot(input)<<std::endl;
        return  lookupNot(input);
    }else if (type==ElementType.Xnor){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupXnor(input)<<std::endl;
        return  lookupXnor(input);
    }else if (type==ElementType.Xor){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupXor(input)<<std::endl;
        return  lookupXor(input);
    }else if (type==ElementType.Nand){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupNand(input)<<std::endl;
        return  lookupNand(input);
    }else if (type==ElementType.Nor){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupNor(input)<<std::endl;
        return  lookupNor(input);
    }
    return false;
 */


LookupTable::~LookupTable(){
}

int main() {
    return 0;
}
