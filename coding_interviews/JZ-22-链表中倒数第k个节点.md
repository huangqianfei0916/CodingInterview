<!--
 * @Author: huangqianfei
 * @Date: 2023-09-17 19:53:30
 * @LastEditTime: 2023-09-17 19:54:48
 * @Description: 
-->
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

 

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

解法：
* 时间复杂度o(n)
* 空间复杂度o(1)
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        int len = 0;
        while (p) {
            p = p->next;
            ++len;
        }

        int gap = len - k;
        while (q && gap > 0) {
            q = q->next;
            --gap;
        }
        return q;

    }
};
```