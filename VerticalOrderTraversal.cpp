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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int,multiset<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x=p.second.first;
            int y= p.second.second;
            TreeNode* curr = p.first;
            node[x][y].insert(curr->val);
            if(curr->left)
            {
                q.push({curr->left, {x-1,y+1}});
            }
            if(curr->right)
            {
                q.push({curr->right, {x+1,y+1}});
            }
        }
        vector<vector<int>> res;

        for(auto p: node)
        {
            vector<int> temp;
            for(auto t: p.second)
            {
                for(auto tt: t.second)
                {
                    temp.push_back(tt);
                }
            }
            res.push_back(temp);
        }

        return res;



        
        
    }
};