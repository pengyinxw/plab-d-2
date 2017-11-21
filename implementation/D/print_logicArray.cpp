void print_logicArray(){
    ElementType gateType = LogicData.getType();
    std::vector<Logic> input = LogicData.getInput();
    Logic output = LogicData.getOutput();
    std::vector<const Net*> outNets = graphHandler->getElement(6)->getOutNets();
       for (const Net* n:outNets){
          netidOut = n->getId();
       }
    std::vector<const Net*> inNets = graphHandler->getElement(6)->getInNets();
       for (const Net* n:inNets){
          netidIn = n->getId();
        }
       for (const Element* e:graghHandler->getAllElements()){
           int GateID = e->getId();
       }
       int i = GateID;
       for(i=0,i<array.size(),i++){//array store the gates
    std::cout<<"die Type der Gätter:"<<gateType<<std::endl;
    std::cout<<"die Inputwerte :"<<input<<std::endl;
    std::cout<<"die Outputwerte:"<<output<<std::endl;
    std::cout<<"die NetID von Input:"<<netidIn<<std::endl;
    std::cout<<"die NetID von Output:"<<netidOut<<std::endl;
    std::cout<<"die ID der Gätter:"<<GateID<<std::endl;
       }

}
