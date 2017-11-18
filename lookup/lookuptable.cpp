#include "lookuptable.h"

LookupTable::LookupTable(){
}
Logic  LookupTable::lookupAnd(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupAnd[m][n];

}
Logic  LookupTable::lookupOr(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupOr[m][n];

}
Logic  LookupTable::lookupNot(Logic input){

            return lookupNot[input];

}
Logic  LookupTable::lookupXnor(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupXnor[m][n];

}
Logic  LookupTable::lookupXor(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupXor[m][n];

}
Logic  LookupTable::lookupNand(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupNand[m][n];

}
Logic  LookupTable::lookupNor(vector<Logic>input){
          n = input.at(0);
          m = input.at(1);
          return lookupNor[m][n];

}
Logic judgement(vector<Logic>input,ElementType type){
    if (type==ElementType.And ){
       // std::cout<<"Das Input ist"<<vector<Logic>input<<std::endl;
       // std::cout<<"Das Output ist"<<lookupAnd(input)<<std::endl;
        return  lookupAnd(input);

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
}

LookupTable::~LookupTable(){
}


