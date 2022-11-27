/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
 * @brief 本文件写的是虚类，其中的函数都为纯虚函数
 * 
*/


#ifndef GRAGH_
#define GRAGH_

#include "edge.h"


template<class T>
class Gragh{
    public:
    virtual Graph(){}
    virtual int getNumberOfEdge() = 0;
    virtual int getNumberOfNode() = 0;
    virtual bool insertEdge(string start, string destination, T distance) = 0;
    virtual void insertNode(string name) = 0;
    virtual int degree() const = 0;
    virtual int out_degree() const = 0;
    virtual int in_degree() const = 0;
};


#endif