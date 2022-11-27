/**
 * @author 张骏勇 张自豪 曹祯浩 李钜环
 * @brief 本文件实现的是一个linkedwGragh
 *  以下的类都为实体类，实现Gragh的方法
 *  存储方式：邻接表
*/

#ifndef LINKEDDWGRAGH
#define LINKEDDWGRAGH

#define NOT_FOUND -1
#define ERROR 0x3f3f3f3f
#define FOUND 1

#include "gragh.h"


const int max_number = 100010;

template<class T>
class linkedwGragh : public Gragh<T>{

    public:

    int numberOfNode;

    int numberOfEdge;

    // 邻接数组用的
    vector<vector<Node<T>>> node_array;

    // 存点的主数组
    vector<NodeList> nodes_list;

    // 存边
    vector<Edge<T>> edge_list;

    // 用到的索引
    int idx = 0;

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
        numberOfEdge = 0;
        numberOfNode = 0;
    }
    
    private:

    // dfs函数内部递归实现
    bool rdfs(NodeList start, NodeList destination);


    // 求解度
    int degree() const;

    // 求解出度
    int out_degree() const;

    // 求解入度
    int in_degree() const;

    public:

    // 插入边的函数
    bool insertEdge(string start, string destination, T distance);

    // 插入点的函数
    void insertNode(string name);

    // 获取节点和边的数量
    int getNumberOfEdge(){return numberOfEdge;}
    int getNumberOfNode(){return numberOfNode;}
    
    // 下面需要实现的是一些图的算法，返回值和参数列表可以修改，必要的时候可以修改类其中的属性，但是必须提前告知

    // 两个，一个dfs一个bfs，都实现一下吧
    int dfs_find(string start, string destination);

    int bfs_find(string start, string destination, vector<string>& ans);
    
    // 拓扑序列
    void topo_find();

    void kruskal();

    void prim();

    void dijkstra();

    // 找到两个节点之间的最短距离 返回一个距离
    int find_min_function(Node<T> a, Node<T> b);
    // 找到两个节点之间的最短距离 返回一个路径名的字符串
    vector<string> find_min_path_function(Node<T> a, Node<T> b);
};

// 插入边的函数，头插法
template<class T>
bool linkedwGragh<T>::insertEdge(string start, string destination, T distance){
    this->numberOfEdge ++;

    NodeList a, b;

    int idx_a, idx_b;
    bool flag_a = false, flag_b = false;
    int flag = 0;
    for(auto item = this->nodes_list.begin();item != this->nodes_list.end();item ++){
        if(item->info == start) {
            a = *item;
            idx_a = flag;
            flag_a = true;
        }
        if(item->info == destination) {
            b = *item;
            idx_b = flag;
            flag_b = true;
        }
        flag ++;
    }
    if(!flag_a || !flag_b) return false;

    a.outdegree ++;
    b.indegree ++;
    // 存一下边
    Edge<T>* edge_temp = new Edge<T>(idx_a, idx_b, distance);
    this->edge_list.push_back(*edge_temp);

    // 存一下点到node_array中
    Node<T>* a_ = new Node<T>(distance, idx_b);

    this->node_array[idx_a].push_back(*a_);
    return true;
}

// 插入点的函数
template<class T>
void linkedwGragh<T>::insertNode(string name){
    this->numberOfNode ++;
    vector<Node<T>> temp_Node;
    this->node_array.push_back(temp_Node);

    NodeList* temp_node_list = new NodeList(0, name);

    temp_node_list->idx = this->idx ++;

    this->nodes_list.push_back(*temp_node_list);
}

template<class T>
int linkedwGragh<T>::dfs_find(string start, string destination){
    NodeList a, b;

    int idx_a, idx_b;
    bool flag_a = false, flag_b = false;
    int flag = 0;
    for(auto item = this->nodes_list.begin();item != this->nodes_list.end();item ++){
        if(item->info == start) {
            a = *item;
            idx_a = flag;
            flag_a = true;
        }
        if(item->info == destination) {
            b = *item;
            idx_b = flag;
            flag_b = true;
        }
        flag ++;
    }
    if(!flag_a || !flag_b) return ERROR;

    for(auto item : this->nodes_list){
        item.st = false;  //全部初始化一下
    }

    bool res = this->rdfs(a, b);

    if(!res) return NOT_FOUND;
    else return FOUND;
}

template<class T>
bool linkedwGragh<T>::rdfs(NodeList start, NodeList destination){
    if(start.info == destination.info){
        return true;
    }
    for(auto item = this->node_array[start.idx].begin();item != this->node_array[start.idx].end();item ++){
        int t = item->index;
        if(!this->nodes_list[t].st){  // 假如没有遍历过这个点的话
            this->nodes_list[t].st = true;
            rdfs(this->nodes_list[t], destination);
            this->nodes_list[t].st = false;
        }
    }
    return false;
}

template<class T>
int linkedwGragh<T>::bfs_find(string start, string destination, vector<string>& ans){
    NodeList a, b;

    int idx_a, idx_b;
    bool flag_a = false, flag_b = false;
    int flag = 0;
    for(auto item = this->nodes_list.begin();item != this->nodes_list.end();item ++){
        if(item->info == start) {
            a = *item;
            idx_a = flag;
            flag_a = true;
        }
        if(item->info == destination) {
            b = *item;
            idx_b = flag;
            flag_b = true;
        }
        flag ++;
    }
    if(!flag_a || !flag_b) return ERROR;
    
    for(auto item : this->nodes_list){
        item.st = false;  //全部初始化一下
    }

    queue<NodeList> node_queue;
    node_queue.push(a);

    a.st = true;
    int ans = 0;

    while(!node_queue.empty()){
        NodeList temp = node_queue.front();
        node_queue.pop();

        if(temp.info == b.info){
            return ans;
        }
        for(auto item = this->node_array[temp.idx].begin();item != this->node_array[temp.idx].end();item++){
            int t = this->nodes_list[t].idx;
            node_queue.push(this->nodes_list[t]);
        }
        ans ++;
    }

}


// 计算度
template<class T>
int linkedwGragh<T>::degree() const{
    return -1;
}

template<class T>
int linkedwGragh<T>::out_degree() const {
    return -1;
    }

template<class T>
int linkedwGragh<T>::in_degree() const {
    return -1;
    }
#endif