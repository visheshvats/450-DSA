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
    int solve(TreeNode* node, int diameter)
    {
        if(node==NULL)
            return 0;
        
        int l = solve(node->left, diameter);
        int r = solve(node->right, diameter);

        diameter = max(diameter,l+r);
        return 1+max(l,r);


    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        solve(root, diameter);
        return diameter;

        
    }
};