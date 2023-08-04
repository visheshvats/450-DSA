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
    int maxD(Node * node)
    {
        //bc(Base Condition)
        if(node==NULL)  return 0;

        //rc(Recursive Code)
        int ans =0;
        for(int i=0;i<node->children.size();i++)
        {
            int temp = maxD(node->children[i]);
            ans = max(temp,ans);
        }

        return ans+1;

    }
    int maxDepth(Node* root) {
        int ans = maxD(root);

        return ans;
        
    }
};