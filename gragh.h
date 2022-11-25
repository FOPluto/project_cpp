#include "edge.h"
/**
 * @author zhangjunyong
 * @brief 本文件写的是虚类，其中的函数都为纯虚函数
*/


#ifndef GRAGH
#define GRAGH

template<class T> class gragh{
    public:
    virtual int getNumberOfEdge() = 0;
    virtual int getNumberOfNode() = 0;
    virtual void insertEdge(Edge edge) = 0;
    virtual void insertNode(Node node) = 0;
    virtual void dfs_find() = 0;
    virtual void bfs_find() = 0;
    virtual int degree() = 0;
    virtual int out_degree() = 0;
    virtual int in_degree() = 0;
};


#endif