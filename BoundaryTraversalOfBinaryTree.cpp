#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isleaf(TreeNode<int> *root)
{
    if(root->left)  return false;
    if(root->right)  return false;

    return true;



}

void addLeftBoudary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *node = root->left;
    while(node)
    {
        if(!isleaf(node)) res.push_back(node->data);
        if(node->left)  node= node->left;
        else    node=node->right;
    }
}

void addLeafNode(TreeNode<int>* root, vector<int>&res)
{
    if(isleaf(root))
    {
        res.push_back(root->data);
        return ;
    }

    if(root->left) addLeafNode(root->left, res);
    if(root->right) addLeafNode(root->right, res);
}

void addRightBoudaryinReversal(TreeNode<int> *root, vector<int> &res)
{
    vector<int> temp;

    TreeNode<int> *node = root->right;
    while(node)
    {
        if(!isleaf(node)) temp.push_back(node->data);
        if(node->right) node=node->right;
        else node= node->left;
    }



    for(int i=temp.size()-1;i>=0;i--)
    {
        res.push_back(temp[i]);
    }

}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if(!root)   return res;
    if(!isleaf(root))    res.push_back(root->data);
    addLeftBoudary(root, res);
    addLeafNode(root, res);
    addRightBoudaryinReversal(root, res);

    return res;


}