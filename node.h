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


class Node{
    public:
    //表示地点名
    string name;

    //距离
    int length;

    //下一个节点地址
    Node* next_node;


    Node(string name = ""){
        this->next_node = NULL;
        this->name = name;
    }

    Node(Node currentNode, string name){
        currentNode.next_node = new Node(name);
    }
	//重载==，用于remove方法的判断
	bool operator==(Node node)
	{
		if (node.name == this->name)return true;
		else return false;
	}
};

typedef Node* nodePosision;


#endif