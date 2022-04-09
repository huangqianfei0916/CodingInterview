#include <iostream>
using namespace std;
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int main(){
    TreeNode root(2);
    cout << root.val;
    cout << root.left;

    return 0;
}