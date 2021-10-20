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

// 206.反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* current = head;
        ListNode* next = current->next;
        current->next = nullptr;
        while(next != nullptr){
            ListNode* temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }
        return current;  //注意返回的是current不是next
    }
};