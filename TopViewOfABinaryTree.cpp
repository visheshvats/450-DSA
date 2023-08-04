#include <bits/stdc++.h> 

using namespace std;



    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


vector<int> getTopView(TreeNode<int> *root) {
    
    
    // Write your code here.
    vector<int> ans;
    if(root==NULL)  return ans;
    map<int, int> mp;
    queue<pair<TreeNode<int>*,pair<int, int>>> q;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        auto it  = q.front();
        q.pop();
        TreeNode<int> * temp = it.first;
        int height=it.second.first;
        int order = it.second.second;

        if(mp.find(order)==mp.end())
        {
            mp[order]=temp->val;
        }

        if(temp->left)  q.push({temp->left,{height+1,order-1}});
        if(temp->right)  q.push({temp->right,{height+1,order+1}});

    }



    for(auto it : mp)
    {
        ans.push_back(it.second);
    }



    return ans;



}