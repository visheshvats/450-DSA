#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool solve(TreeNode* leftnode, TreeNode* rightnode)
    {
        if(leftnode==NULL&&rightnode==NULL) return true;
        if(leftnode==NULL||rightnode==NULL||leftnode->val!=rightnode->val)  return false;
        return solve(leftnode->right, rightnode->left)&&solve(leftnode->left, rightnode->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        return solve(root->left, root->right);
        
    }
};