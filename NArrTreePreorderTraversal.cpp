#include<bits/stdc++.h>
using namespace std;
#define null NULL


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

    void preorder(Node* node, vector<int> &ans)
    {
        //bc
        if(node==null)
        return;

        //rc
        ans.push_back(node->val);
        if(node->children.size()==0)    return;
        
        for(int i=0;i<node->children.size();i++)
        {
            preorder(node->children[i],ans);
        }


    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
        
    }
};