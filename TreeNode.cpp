#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        left = nullptr;
        right = nullptr;
        val = x;
    }

};

// print vector
void print_vec(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ",";
    }
    cout << endl;
}


// 先序遍历
void pre_print(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> s;
    TreeNode* p = root;

    while (!s.empty() || p != nullptr) {
        if (p != nullptr){
            s.push(p);
            vec.push_back(p->val);
            p = p->left;

        } else {
            TreeNode* temp = s.top();
            s.pop();
            p = temp->right;
        }
    }
    print_vec(vec);
}

// 中序遍历
void mid_print(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> s;
    TreeNode* p = root;

    while (!s.empty() || p != nullptr) {
        if (p != nullptr){
            s.push(p);
            p = p->left;

        } else {
            TreeNode* temp = s.top();
            s.pop();
            vec.push_back(temp->val);
            p = temp->right;
        }
    }
    print_vec(vec);
}

// 层次遍历
void top_down_print(TreeNode* root) {
    vector<vector<int> > vec;
    queue<TreeNode*> q;
    TreeNode* p = root;
    q.push(p);

    while (!q.empty()) {
        int len = q.size();
        vector<int> v;
        while (len > 0){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
            --len;

        }
        vec.push_back(v);

    }

    for (int i = 0; i < vec.size(); ++i){
        for (int j = 0; j < vec[i].size(); ++j){
            cout << vec[i][j];
        }
        cout << "-----" << endl;
    }

}


// 后序遍历
void end_print(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* p = root;
    list<int> l;
    s.push(p);
    while (!s.empty()) {
        TreeNode* temp = s.top();
        s.pop();
        l.push_front(temp->val);
        if (temp->left != nullptr) {
            s.push(temp->left);
        }
        if (temp->right != nullptr) {
            s.push(temp->right);
        }
    }

    for(list<int>::iterator it = l.begin(); it != l.end(); ++it){
        cout << *it << ",";
    }
    cout << endl;

}

// 打印排序二叉树的第k个节点
vector<int> vec;
vector<int> end_print1(TreeNode* root) {
     TreeNode* p = root;
     if (p == nullptr) {
         return vec;
     }
    
     end_print1(p->left);
     vec.push_back(p->val);
     end_print1(p->right);
     return vec;
     
 }

 void end_print2(TreeNode* root) {
     TreeNode* p = root;
     if (p == nullptr) {
         return;
     }
    
     end_print2(p->left);
     vec.push_back(p->val);
     end_print2(p->right);
     
 }

 void get_k_node(TreeNode* root, int k) {
     end_print2(root);
     print_vec(vec);
     cout << endl << vec[k - 1] << endl;
 }

// 输入二叉树，输出它的镜像
 TreeNode* mirrTree(TreeNode* root) {
     if (root == nullptr){
         return nullptr;
     }
     TreeNode* temp = root->left;
     root->left = root->right;
     root->right = temp;
     mirrTree(root->left);
     mirrTree(root->right);
     return root;
 }

//  判断二叉树是不是对称二叉树
bool dc(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr && p2 == nullptr){
        return true;
    }
    if(p1 != nullptr && p2 == nullptr) {
        return false;
    }
    if(p2 != nullptr && p1 == nullptr) {
        return false;
    }
    if (p1->val != p2->val) {
        return false;
    }
    return dc(p1->left, p2->right) && dc(p1->right, p2->left);

}

bool judge(TreeNode* root) {
    if (root == nullptr){
        return false;
    }
    bool flag = dc(root->left, root->right);
    if (flag) {
        cout << "对称" << endl;
    } else {
        cout << "不对称" << endl;
    }
    return flag;
}

// 将二叉搜索树变成双向链表，中序遍历加入链表构建
TreeNode* realHead = nullptr;
TreeNode* p = nullptr;
TreeNode* listTree(TreeNode* root) {
    if (root == nullptr) {
        return  nullptr;
    }
    listTree(root->left);
    if (p == nullptr) {
        p = root;
        realHead = root;
    } else {
        p->right = root;
        root->left = p;
        p = root;
    }

    listTree(root->right);
    return realHead;
}

// 和为某一值的路径
vector<vector<int> > vec_all;
vector<int> v1;
vector<vector<int> > findPath(TreeNode* root, int target) {
    if (root == nullptr) {
        return vec_all;
    }
    v1.push_back(root->val);
    target -= root->val;
    if (target == 0 && root->left == nullptr && root->right == nullptr) {
        vec_all.push_back(v1);
    }

    findPath(root->left, target);
    findPath(root->right, target);
    v1.pop_back();
    return vec_all;

}

void print_vec2(vector<vector<int> > temp_vec) {
    for (int i = 0; i < temp_vec.size(); ++i){
        for (int j = 0; j < temp_vec[i].size(); ++j) {
            cout << temp_vec[i][j] << " ";
        }
        cout << endl;
    }
}

// 二叉树的深度
int treeDeep(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = treeDeep(root->left);
    int right = treeDeep(root->right);
    return max(left, right) + 1;
}

// 判断二叉树是否为 平衡二叉树
int balanceTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = treeDeep(root->left);
    if (left == -1) {
        return -1;
    }
    int right = treeDeep(root->right);
    if (right == -1) {
        return -1;
    }
    return abs(left - right) > 1 ? -1 : max(left, right) + 1;
}

bool balanceJudge(TreeNode* root) {
    bool flag = true;
    if (root == nullptr){
        return false;
    }
    int temp = balanceTree(root);
    if (temp == -1) {
        flag = false;
    }
    cout << "是否平衡二叉树：" << flag << endl;
    return flag;
}

// 判断给定数组是否为  二叉搜索树的后序遍历序列
bool hx(vector<int> temp, int start, int end) {
    if (start <= end) {
        return true;
    }
    int root_val = vec[end];
    int index = start;

    for (int i = start; i < end; ++i){
        if (vec[i] > root_val){
            index = i;
            break;
        }
    }

    for (int i = index; i < end; ++i) {
        if (vec[i] < root_val) {
            return false;
        }
    }

    bool left = true;
    if (index > start) {
        left = hx(vec, start, index - 1);
    }

    bool right = true;
    if (index < end) {
        right = hx(vec, index, end - 1);
    }

    return left && right;

}

bool hxJudge(vector<int> vec) {
    bool flag = false;
    if (vec.size() == 0){
        return false;
    }
    flag = hx(vec, 0, vec.size() - 1);
    cout << "是否为搜索二叉树的后序序列：" << flag << endl;
    return flag;

}

// 判断一个二叉树是不是另一个二叉树的子树
bool check(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr && p2 == nullptr) {
        return true;
    }
    if (p1 == nullptr && p2 != nullptr) {
        return false;
    }
    if (p1 != nullptr && p2 == nullptr) {
        return true;
    }
    if (p1->val != p2->val) {
        return false;
    }
    return check(p1->left, p2->left) && check(p1->right, p2->right);
    
}

bool subTree(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr || p2 == nullptr) {
        return false;
    }
    bool flag = false;
    if (p1->val == p2->val){
        flag = check(p1, p2);
    }
    if (!flag) {
        flag = subTree(p1->left, p2);
    }
    if (!flag) {
        flag = subTree(p1->right, p2);
    }
    cout << "是否子树：" << flag << endl;
    return flag;

}

int main(){
    TreeNode* d = new TreeNode(3);
    TreeNode* d1 = new TreeNode(1);
    TreeNode* d2 = new TreeNode(5);
    TreeNode* d3 = new TreeNode(0);
    TreeNode* d4 = new TreeNode(2);
    TreeNode* d5 = new TreeNode(4);
    TreeNode* d6 = new TreeNode(6);
    d->left = d1;
    d->right = d2;
    d1->left = d3;
    d1->right = d4;
    d2->left = d5;
    d2->right = d6;

    // pre_print(d);
    // cout << "------------" << endl;
    mid_print(d);
    cout << "------------" << endl;
    // top_down_print(d);
    // cout << "------------" << endl;
    end_print(d);
    cout << "------------" << endl;
    // get_k_node(d, 3);
    // mirrTree(d);
    // top_down_print(d);
    // cout << "------------" << endl;
    // judge(d);
    // TreeNode* f = listTree(d);
    // findPath(d, 7);
    // print_vec2(vec_all);
    // int depth = treeDeep(d);
    // cout << depth << endl;
    // balanceJudge(d);
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(4);
    temp.push_back(6);
    temp.push_back(5);
    temp.push_back(3);

    hxJudge(temp);
    subTree(d, d);

    return 0;
}
