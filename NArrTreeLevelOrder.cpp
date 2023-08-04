#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> arr;
            for(int i=0;i<n;i++)
            {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                for(int j=0;j<it->children.size();i++)
                {
                    q.push(it->children[i]);
                }

            }

            ans.push_back(arr);
        }

        return ans;


        
    }
};