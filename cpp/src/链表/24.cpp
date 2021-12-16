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

// 24.两两交换链表中的节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* pre = dummy;  // 前节点
        pre->next = head;
        ListNode* current = head;  // 现节点
        ListNode* post = nullptr;  // 后节点
        if(head != nullptr){
            post = head->next;  // 加入判断防止head为空
        }
        while(current != nullptr && post != nullptr){
            ListNode* temp = post->next;
            pre->next = post;  // 交换位置 
            post->next = current;
            current->next = temp;
            pre = current;  // 更新节点指针
            current = pre->next;
            if(current != nullptr){
                post = current->next;
            }
            else{
                post = nullptr;
            }
        }
        return dummy->next;
    }
};