#include <iostream>
#include <vector>
#include "traversal.h"

void Traversal::preorder_traversal(TreeNode* cur, vector<int>& vec){
    if (cur == NULL) return;
    vec.push_back(cur->val);
    preorder_traversal(cur->left, vec);
    preorder_traversal(cur->right, vec);
}
void Traversal::inorder_traversal(TreeNode* cur, vector<int>& vec){
    if (cur == NULL) return;
    inorder_traversal(cur->left, vec);
    vec.push_back(cur->val);
    inorder_traversal(cur->right, vec);
}
void Traversal::postorder_traversal(TreeNode* cur, vector<int>& vec){
    if (cur == NULL) return;
    postorder_traversal(cur->left, vec);
    postorder_traversal(cur->right, vec);
    vec.push_back(cur->val);
}
void Traversal::test(){
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(2);
    t->right = new TreeNode(7);
    t->left->left = new TreeNode(1);
    t->left->right = new TreeNode(3);
    t->right->left = new TreeNode(6);
    t->right->right = new TreeNode(9);
    vector<int> vec;
    Traversal tra;

    tra.preorder_traversal(t, vec);
    cout << "Preorder traversal  : ";
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    vec.clear();

    tra.inorder_traversal(t, vec);
    cout << "Inorder traversal   : ";
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    vec.clear();

    tra.postorder_traversal(t, vec);
    cout << "Postorder traversal  : ";
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    vec.clear();
}