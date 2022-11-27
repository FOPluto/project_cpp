/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
*/

#ifndef EDGE_
#define EDGE_

#include "node.h"

// 代表无穷远
const int INF = 0x3f3f3f3f;

template<class T>
class Edge{
    public:
    //权重和目标点，这里仅存目标点
    int v1;     // 点1的编号
    int v2;     // 点2的编号
    T w;           // 到达该点的权重
    
    Edge()
    {
        v1 = -1;
        v2 = -1;
        w = 0;
    }
    Edge(int the_v1, int the_v2, T the_w)
    {
        v1 = the_v1;
        v2 = the_v2;
        w = the_w;
    }
};

#endif