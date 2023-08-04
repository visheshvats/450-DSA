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
        map<int, map<int, set<int>>> s;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int first = temp.second.first;
            int second = temp.second.second;
            s[second][first].insert(temp.first->val);
            if(temp.first->left)
            {
                q.push({temp.first->left,{first+1,second-1}});
            }
            if(temp.first->right)
            {
                q.push({temp.first->right,{first+1,second+1}});
            }

        }
        vector<vector<int> > ans;

        for(auto it: s)
        {
            vector<int> temp;
            for(auto itt: it.second)
            {
                for(auto ittt: itt.second)
                {
                    temp.push_back(ittt);
                }

            }
            ans.push_back(temp);

        }
        
    }
};