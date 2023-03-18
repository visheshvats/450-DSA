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
    bool isLeaf(TreeNode *root)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void solve(TreeNode *root, vector<int> &a, int &ans)
    {
        if (isLeaf(root))
        {
            a.push_back(root->val);
            
            int result = 0;
            for (auto d : a)
            {
                result = result * 10 + d;
            }
            ans+=result;
            a.pop_back();
            return;

        }
        if(root==NULL)  return;

        a.push_back(root->val);
        solve(root->left, a, ans);
        solve(root->right, a, ans);
        a.pop_back();
        return;
    }

    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        vector<int> a;
        solve(root, a, ans);
        return ans;
    }
};