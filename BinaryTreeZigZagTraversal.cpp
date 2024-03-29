#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> bfs(TreeNode* root)
    {
        bool LtoR=true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp(q.size(),0);
            for(int i=0;i<q.size();i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);


            }
            if(!LtoR)
            {
                reverse(temp.begin(), temp.end());

            }
            ans.push_back(temp);
        }

        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans =bfs(root);
        return ans;

    }
};