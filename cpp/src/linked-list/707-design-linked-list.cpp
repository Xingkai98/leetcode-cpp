#include <iostream>

class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr){}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummy = new LinkedNode(0);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= _size){
            return -1;
        }
        LinkedNode* node = _dummy->next;
        int count = index;
        while(count--){
            node = node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* node = _dummy->next;
        _dummy->next = new LinkedNode(val);
        _dummy->next->next = node;
        _size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* node = _dummy;
        while(node->next != nullptr){
            node = node->next;
        }
        node->next = new LinkedNode(val);
        _size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        LinkedNode* node = _dummy;
        int count = index;
        while(count--){
            node = node->next;
        }
        LinkedNode* temp = node->next;
        node->next = new LinkedNode(val);
        node->next->next = temp;
        _size += 1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= _size){
            return;
        }
        LinkedNode* node = _dummy;
        int count = index;
        while(count--){
            node = node->next;
        }
        LinkedNode* temp = node->next;
        if(temp != nullptr){
            node->next = temp->next;
        } 
        else{
            node->next = nullptr;
        }
        delete temp;
        _size -= 1;
    }

private:
    LinkedNode* _dummy;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    using namespace std;
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    int n1 = obj->get(1);
    obj->deleteAtIndex(0);
    int n2 = obj->get(0);  
}