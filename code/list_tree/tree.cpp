/*
 * Copyright (c) 2024 by huangqianfei@tju.edu.cn All Rights Reserved. 
 * @Author: huangqianfei@tju.edu.cn
 * @Date: 2024-12-04 22:03:09
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

void test(ListNode* l) {
    ListNode* p = new ListNode(100);
    l->next = p;
}

ListNode* reverse(ListNode* head) {
    ListNode* p = head;
    head = nullptr;

    while (p) {
        ListNode* q = p;
        p = p->next;
        q->next = head;
        head = q;
    }

    return head;
}

int main() {

    ListNode* head = new ListNode(0);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;

    ListNode* res = (head);


    return 0;
}