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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long int maxWid = INT_MIN;

        queue<pair<TreeNode *, long long int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            /* code */
            int si = q.size();
            long long int sta = q.front().second;
            long long int end = q.back().second;
            maxWid = max(maxWid, end - sta + 1);
            for (int i = 0; i < si; i++)
            {
                TreeNode *temp = q.front().first;
                long long int level = q.front().second;
                q.pop();
                if (temp->left)
                {
                    q.push({temp->left, (level * 2) + 1});
                }
                if (temp->right)
                {
                    q.push({temp->right, (level * 2) + 2});
                }
            }
        }

        return (int)maxWid;
    }
};