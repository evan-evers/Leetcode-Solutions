//Original problem: https://leetcode.com/problems/subtree-of-another-tree/

#include <iostream>
#include "mybinarytree_int.h"
using namespace std;

bool isSameTree(treenode* p, treenode* q)
{
    if (!p && !q) return true;  //base case
    if (!p || !q || p->val != q->val) return false; //if one node is nullptr and the other isn't, or if the values don't match, the structures differ

    return issametree(p->left, q->left) && issametree(p->right, q->right);  //both l&r subtrees must be the same for the tree to be the same overall
}

bool isSubTree(treenode* root, treenode* subroot) 
{
    //traverse the tree, checking it with the subtree at each node
    if (root == nullptr && subroot == nullptr) return true;     //both are nullptr; return true
    if (root == nullptr || subroot == nullptr) return false;    //only one is nullptr. the && statement above makes this an exclusive or

    //check for sameness at this node
    if (issametree(root, subroot))
        return true;

    return issubtree(root->left, subroot) || issubtree(root->right, subroot);
}
