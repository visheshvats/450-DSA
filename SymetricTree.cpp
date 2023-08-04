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
    bool check(TreeNode* leftR,TreeNode* rightR){
        if(leftR==NULL && rightR==NULL){
            return true;
        }else if(leftR==NULL){
            return false;
        }else if(rightR==NULL){
            return false;
        }
        bool ans1=false,ans2=false;
        if(leftR->val==rightR->val){
            ans1=check(leftR->left,rightR->right);
        }
        if(leftR->val==rightR->val){
            ans2=check(leftR->right,rightR->left);
        }
        if(ans1 && ans2){
            return true;
        }else{
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left==NULL || root->right==NULL){
            return false;
        }
        if(root->left->val==root->right->val){
            return check(root->left,root->right);
        }
        return 0;
    }
};