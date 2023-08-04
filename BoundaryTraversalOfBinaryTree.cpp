#include <bits/stdc++.h> 
using namespace std;

    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

    bool isLeaf(TreeNode<int>* node)
    {
        if(!node->left&&!node->right)   return true;
        return false;
    }

    void addLeftTree(TreeNode<int> * node, vector<int> &r)
    {
        TreeNode<int> * curr = node->left;
        while(curr)
        {
            r.push_back(curr->data);
            if(curr->left)  curr= curr->left;
            else curr=curr->right;
        }

    }

    void addLeaf(TreeNode<int> * node, vector<int> & r)
    {
        if(isLeaf(node))
        {
            r.push_back(node->data);
        }

        if(node->left)  addLeaf(node->left, r);
        if(node->right)  addLeaf(node->right, r);

    }

    void addRightTree(TreeNode<int> * node, vector<int> & r)
    {
        vector<int> tmp;
        TreeNode<int> * curr = node->right;
        while(curr)
        {
            tmp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;

        }

        for(int i=tmp.size()-1;i>=0;i++)
        {
            r.push_back(tmp[i]);
        }

    }


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL)  return ans;
    if(!isLeaf(root))   ans.push_back(root->data);
    addLeftTree(root, ans);
    addLeaf(root, ans);
    addRightTree(root, ans);

    return ans;


}