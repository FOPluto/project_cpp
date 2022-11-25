#include "gragh.h"
/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
 * @brief 本文件实现的是一个linkedwGragh
 *  以下的类都为实体类，实现Gragh的方法
 *  存储方式：邻接表
*/

#ifndef LINKEDDWGRAGH
#define LINKEDDWGRAGH

class linkedwGragh : public Gragh<int>{

    void insertEdge(Edge edge);

    void insertNode(Node node);

    void dfs_find();

    void bfs_find();

    int degree();

    int outdegree();

    int indegree();

    // 找到两个节点之间的最短距离
    int find_min_function(Node a, Node b);
};


#endif