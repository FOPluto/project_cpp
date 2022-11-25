/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
*/

#include "node.h"


#ifndef EDGE
#define EDGE

// 代表无穷远
const int INF = 0x3f3f3f3f;

class Edge{
    //权重和边的两边
    nodePosision a, b;

    int w;
    
    Edge();

    Edge(Node a, Node b, int w): a(&a), b(&b), w(w){}
};

Edge::Edge(){
    a = b = NULL;
    w = INF;
}

#endif