#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

#endif