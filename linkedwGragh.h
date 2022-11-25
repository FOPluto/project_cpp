/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
 * @brief 本文件实现的是一个linkedwGragh
 *  以下的类都为实体类，实现Gragh的方法
 *  存储方式：邻接表
*/

#ifndef LINKEDDWGRAGH
#define LINKEDDWGRAGH

#include "gragh.h"


const int max_number = 100010;

class linkedwGragh : public Gragh<int>{

    public:

    int numberOfNode;

    int numberOfEdge;

    // 节点列表的头结点
    nodePosision node_list[max_number];

    // 用到的索引
    int idx = -1;

    // 构造函数
    linkedwGragh(int numberOfVertices){
        while (1) 
		{
			if (numberOfVertices < 0) 
			{
				cout << "请重新输入：" << endl;
				cin >> numberOfVertices;
			}
			else 
			{
				break;
			}
		}
        this->node_list[++ idx] = new Node();
        numberOfEdge = 0;
        numberOfNode = 0;
    }
    
    private:

    // 插入边的函数
    void insertEdge(Edge edge);

    void insertNode(Node node);

    // 求解度
    int degree() const;

    // 求解出度
    int out_degree() const;

    // 求解入度
    int in_degree() const;

    public:

    int getNumberOfEdge(){return numberOfEdge;}
    int getNumberOfNode(){return numberOfNode;}
    
    // 下面需要实现的是一些图的算法，返回值和参数列表可以修改，必要的时候可以修改类其中的属性，但是必须提前告知

    // 两个，一个dfs一个bfs，都实现一下吧
    void dfs_find();

    void bfs_find();
    
    // 拓扑序列
    void topo_find();

    void kruskal();

    void prim();

    void dijkstra();

    // 找到两个节点之间的最短距离 返回一个距离
    int find_min_function(Node a, Node b);
    // 找到两个节点之间的最短距离 返回一个路径名的字符串
    vector<string> find_min_path_function(Node a, Node b);
};

// 插入边的函数，头插法
void linkedwGragh::insertEdge(Edge edge){
    this->numberOfEdge ++;
    edge.b.next_node = edge.a.next_node;
    edge.a.next_node = &edge.b;
}

// 插入点的函数
void linkedwGragh::insertNode(Node node){
    this->numberOfNode ++;
    this->node_list[++ idx] = &node;
}

void linkedwGragh::dfs_find(){

}


// 计算度
int linkedwGragh::degree() const{
    return -1;
}

int linkedwGragh::out_degree() const {
    return -1;
    }

int linkedwGragh::in_degree() const {
    return -1;
    }
#endif