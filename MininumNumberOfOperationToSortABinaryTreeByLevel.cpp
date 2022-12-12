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
    int minSwaps(vector<int> &arr)
    {
        vector<int> temp(arr);
        vector<pair<int,int>> t;
        int cnt=0;
        for(int i=0;i<temp.size();i++)
        {
            t.push_back({temp[i],i});
        }

        sort(begin(t), end(t));
        for(int i=0;i<t.size();i++)
        {
            if(t[i].second==i)  continue;
            else
            {
                cnt++;
                swap(t[i],t[t[i].second]);
                i--;
            }
        }

        return cnt;
    }
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;


        while(!q.empty())
        {
            vector<int> temp;
            int sz=q.size();

            for(int i=0;i<sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

            }

            cnt+=minSwaps(temp);
        }


        return cnt;
        
    }
};