#include <iostream>

#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        left = nullptr;
        right = nullptr;
        val = x;
    }

};

void print_vec(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}

void pre_print(TreeNode* root){
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


int main(){
    TreeNode* d = new TreeNode(0);
    TreeNode* d1 = new TreeNode(1);
    TreeNode* d2 = new TreeNode(2);
    TreeNode* d3 = new TreeNode(3);
    TreeNode* d4 = new TreeNode(4);
    TreeNode* d5 = new TreeNode(5);
    TreeNode* d6 = new TreeNode(6);
    d->left = d1;
    d->right = d2;
    d1->left = d3;
    d1->right = d4;
    d2->left = d5;
    d2->right = d6;

    pre_print(d);

    return 0;
}
