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

// 203.移除链表元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* current = dummy;
        while(current != nullptr){
            while(current->next!=nullptr && current->next->val == val){
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            current = current->next;
        }
        return dummy->next;
    }
};