#ifndef NODE
#define NODE

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

template<class T>
class Node{
    public:

    // 该点的编号
    int index;

    // 权重
    T value;

    // 是否被遍历过
    bool st;

    Node(T value, int index){
        this->value = value;
        this->index = index;
        this->st = false;
    }

    Node(){
        this->st = false;
    }

	// 重载==，用于remove方法的判断
	bool operator==(Node node)
	{
		if (node.index == this->index)return true;
		else return false;
	}
};

class NodeList
{
public:
	static int cnt;

    int idx;

	int indegree;  //当前点入度

	int outdegree;   //当前点出度

	string info;        //当前点信息（城市名）

    bool st;                //记录是否被遍历过了

	NodeList(int the_indegree = 0, string the_info = "")
	{
		indegree = 0;
		outdegree = 0;
		indegree = the_indegree;
		info = the_info;
	}
	//重载==，用于search方法
	bool operator==(string to)
	{
		if (to == this->info)return true;
		else return false;
	}
};

#endif