#include "linkedwGragh.h"

int main(){
    linkedwGragh<double>* myGragh = new linkedwGragh<double>(10);

    string names[4] = { "北京","长沙","秦皇岛","上海" };
    for(auto item : names){
        myGragh->insertNode(item);
    }
    myGragh->insertEdge("长沙", "北京", 100.2);
    myGragh->insertEdge("北京", "秦皇岛", 114.514);

    
    return 0;
}