/*
 * @Author: huangqianfei
 * @Date: 2022-10-04 16:57:06
 * @Description: 
 * Dijkstra算法首先通过广度优先遍历的方式计算出各个顶点的（父节点，距离首节点的最短路径）
 * 然后通过最后节点的父节点进行回朔，得到最终的路径
 * https://blog.csdn.net/Xing_LG/article/details/124864695
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int N = 0x7fffffff;

struct Node {
    int id;
    Node* father;
    int min_length = 0x7fffffff;
};

vector<vector<int>> matrix(6, vector<int>(6));

void init_matrix() {
    
    matrix[0] = {0, 6, 3, N, N, N};
    matrix[1] = {6, 0, 2, 5, N, N};
    matrix[2] = {3, 2, 0, 3, 4, N};
    matrix[3] = {N, 5, 3, 0, 2, 3};
    matrix[4] = {N, N, 4, 2, 0, 5};
    matrix[5] = {N, N, N, 3, 5, 0};

}

// 每个节点的最小距离（节点距离首节点的距离），
// 求出每个未计算节点的距离到已经计算节点的距离，取最小的就是下一个节点
Node* cal_min_node(list<Node*> cal_list, list<Node*> uncal_list) {
    int M = 0x7fffffff;
    Node* v = nullptr;
    
    for (auto uncal_item : uncal_list) {
        for (auto marked_item : cal_list) {
            if (matrix[marked_item->id][uncal_item->id] == N) {
                continue;
            }
            int dis = marked_item->min_length + matrix[marked_item->id][uncal_item->id];
            if (dis < uncal_item->min_length) {
                uncal_item->min_length = dis;
                uncal_item->father = marked_item;
            }
        }
        if (uncal_item->min_length < M) {
            M = uncal_item->min_length;
            v = uncal_item;
        }
    }

    return v;
}

int main() {
    init_matrix();

    // 初始化首节点
    list<Node*> cal_list;
    Node* first_node = new Node(); 
    first_node->id = 0;
    first_node->min_length = 0;
    cal_list.push_back(first_node);

    // 初始化待计算节点
    list<Node*> uncal_list;
    for (int i = 0; i < 5; ++i) {
        Node* temp = new Node();
        temp->id = i + 1;
        uncal_list.push_back(temp);
    }

    // 依次计算未计算信息的节点
    while (uncal_list.size() > 0) {
        Node* tm_node = cal_min_node(cal_list, uncal_list);
        uncal_list.remove(tm_node);
        cal_list.push_back(tm_node);
        cout << "node:" << tm_node->id << "(" << tm_node->father->id << "," << tm_node->min_length << ")" << endl;
    }

    // 回溯输出路径
    for(auto item : cal_list) {
        if (item->id == 5) {
            cout << "最短路径长度：" << item->min_length << endl;
            cout << "路径是：5";
            while (item->id != 0) {
                item = item->father;
                cout << "->" << item->id;
            }
        }
    }

    return 0;
}
