#include <bits/stdc++.h> 
using namespace std;
template <typename T>


    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };



vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root==NULL)  return ans;
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*,pair<int, int>>> q;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        auto it  = q.front();
        q.pop();
        BinaryTreeNode<int> * temp = it.first;
        int height=it.second.first;
        int order = it.second.second;

        
        mp[order]=temp->data;

        if(temp->left)  q.push({temp->left,{height+1,order-1}});
        if(temp->right)  q.push({temp->right,{height+1,order+1}});

    }



    for(auto it : mp)
    {
        ans.push_back(it.second);
    }



    return ans;

    
}
