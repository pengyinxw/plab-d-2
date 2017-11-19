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

Logic LookupTable::judge_all(std::vector<Logic> input, Logic output, ElementType type) {
    int in1 = 2;
    int in2 = 2;
    int out = 2;

    in1 = int(input.at(0));
    // NOT needs only one input: there is no second one
    if(input.size() == 2)
    {
        in2 = int(input.at(1));
    }
    out = int(output);

    int search_x = 2;
    std::vector<int> combined = { in1, in2, out };
    std::vector<int>::iterator found_x;

    // search for logical x in vector
    found_x = find(combined.begin(), combined.end(), search_x);

    if ( found_x != combined.end()) { // found X in vector
        int index = std::distance(combined.begin(), found_x); // index in vector := value with X
        if ( index == 2 ) { // output = X; easiest case
            switch (type) {
            case ElementType::And:
                return Logic(tablookupAnd[in1][in2]);
            case ElementType::Or:
                return Logic(tablookupOr[in1][in2]);
            case ElementType::Not:
                return Logic(tablookupNot[in1]);;
            default:
                assert(false);
                break;
            }
        }
        else { // one input is X; output has static value
            switch (type) { 

            case ElementType::And: // !!!! am ende error Fall einbauen ( for schleife nichts gefunden) ??? !!!!
                if (index == 0) {
                    for (int i=0; i<=4; i++ ) {
                        // spalte fest; teste fuer jede Zeile (input damit vollstaendig) ob Wert = output
                        if ( tablookupAnd[i][in2] == out ) {
                            return Logic(i);
                        }
                    }
                }
                else {
                    for (int i=0; i<=4; i++ ) {
                        // hier zeile fest; teste jede Spalte, wie oben
                        if ( tablookupAnd[in1][i] == out ) {
                            return Logic(i);
                        }
                    }
                }

            case ElementType::Or:
                if (index == 0) {
                    for (int i=0; i<=4; i++ ) {
                        // spalte fest; teste fuer jede Zeile (input damit vollstaendig) ob Wert = output
                        if ( tablookupOr[i][in2] == out ) {
                            return Logic(i);
                        }
                    }
                }
                else {
                    for (int i=0; i<=4; i++ ) {
                        // hier zeile fest; teste jede Spalte, wie oben
                        if ( tablookupOr[in1][i] == out ) {
                            return Logic(i);
                        }
                    }
                }

            case ElementType::Not:
                for (int i=0; i<=4; i++ ) {
                    // teste welcher input richtigen output erzaeugt
                    if ( tablookupNot[i] == out ) {
                        return Logic(i);
                    }
                }

            default:
                assert(false);
                break;
            }
        }
    }
    else { // no X in in- and output
        return Logic(5); // error
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
