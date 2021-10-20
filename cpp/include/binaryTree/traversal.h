#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include <iostream>
#include <vector>
#include "tree_node.h"

class Traversal{
    public:
        void preorder_traversal(TreeNode* cur, vector<int>& vec);
        void inorder_traversal(TreeNode* cur, vector<int>& vec);
        void postorder_traversal(TreeNode* cur, vector<int>& vec);
        void test();
};

#endif