#include "listNode.h"
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 19.删除链表的倒数第N个结点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();  // 虚拟头节点
        dummy->next = head;
        ListNode* fast = dummy;  // 快节点
        ListNode* slow = dummy;  // 慢节点
        int count = n;
        while(n-- && fast->next != nullptr){  // 快节点先动
            fast = fast->next;
        }
        while(fast->next != nullptr){  // 一起动
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;  // 删除节点
        slow->next = temp->next;
        delete temp;
        return dummy->next;
    }
};