/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
*/

#ifndef EDGE_
#define EDGE_

#include "node.h"

// 代表无穷远
const int INF = 0x3f3f3f3f;

class Edge{
    public:
    //权重和边的两边
    Node a, b;

    int w;
    
    Edge();

    Edge(Node a, Node b, int w): a(a), b(b), w(w){}
};

Edge::Edge(){
    w = INF;
}

#endif