#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// c++，java都是copy传递，都是参数地址copy一份传递，修改地址不影响原函数，但是修改地址对应的值就会影响原函数
void change(ListNode* p1) {
    ListNode* t = new ListNode(100);
    p1->next = t;
    // p1 = t;
    // p1->val = 100;
}

void test(vector<int>* vec, int d, string ss, int arr[]) {
    d = 999;
    ss = "hqf";
    // vec->push_back(222);
    vec = new vector<int>();
    vec->push_back(222);
    arr[0] = 10000; 
}

void testInt(int* a) {
    int d = 100;
    a = &d;
    *a = 12;
}

ListNode* getListNode() {
    ListNode* root = new ListNode(9);
    ListNode* root1 = new ListNode(0);
    ListNode* root2 = new ListNode(0);
    ListNode* root3 = new ListNode(0);
    root->next = root1;
    root1->next = root2;
    root2->next = root3;

    return root;
}

int main() {
    int a = 2;
    testInt(&a);
    cout << a << endl;

    ListNode* p = getListNode();
    change(p);
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }

    cout << "---------" << endl;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    int d = 2;
    string ss = "fly";
    int arr[] = {1, 2, 3};

    test(&vec, d, ss, arr);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
    cout << d << "---" << ss << endl;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        cout << arr[i] << endl;
    }



}