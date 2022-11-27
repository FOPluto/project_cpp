#include "linkedwGragh.h"

int main(){
    linkedwGragh<double>* myGragh = new linkedwGragh<double>(10);

    string names[4] = { "北京","长沙","秦皇岛","上海" };
    for(auto item : names){
        myGragh->insertNode(item);
    }
    bool temp = myGragh->insertEdge("长沙", "北京", 100.2);
    temp = myGragh->insertEdge("长沙", "秦皇岛", 314.514);
    temp = myGragh->insertEdge("长沙", "上海", 314.514);
    temp = myGragh->insertEdge("北京", "秦皇岛", 314.514);
    // temp = myGragh->insertEdge("北京", "上海", 314.514);
    // temp = myGragh->insertEdge("秦皇岛", "长沙", 1145.14);
    // temp = myGragh->insertEdge("上海", "长沙", 165.14);
    // temp = myGragh->insertEdge("上海", "北京", 365.14);
    // temp = myGragh->insertEdge("上海", "秦皇岛", 365.14);
    
    int res = myGragh->dfs_find("上海", "长沙");

    if(res == FOUND){
        puts("Yes");
    } else if(res == NOT_FOUND){
        puts("No");
    } else if(res == ERROR){
        puts("Error");
    }

    return 0;
}