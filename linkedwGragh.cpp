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

    void insertNode(Node a, Node b, int value);

    // 两个，一个dfs一个dfs，先留一个吧
    void dfs_find();

    void bfs_find();

    // 求解度
    int degree();

    // 求解出度
    int outdegree();

    // 求解入度
    int indegree();

    // 找到两个节点之间的最短距离 返回一个距离
    int find_min_function(Node a, Node b);
    // 找到两个节点之间的最短距离 返回一个路径名的字符串
    vector<string> find_min_path_function(Node a, Node b);
};


#endif