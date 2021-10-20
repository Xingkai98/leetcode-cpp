#include "listNode.h"
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 142.环形链表II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){  // 说明有环，开始找入环位置
                ListNode* intersection = slow;
                ListNode* start = head;
                while(intersection != start){
                    start = start->next;
                    intersection = intersection->next;
                }
                return start;
            }
        }
        return nullptr;
    }
};