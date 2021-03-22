#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};


class Solution
{
public:
    vector<vector<int>> threeOrders(TreeNode* root)
    {
        vector<vector<int>> result;
        Pre(root);
        result.push_back(pre);
        Mid(root);
        result.push_back(mid);
        Post(root);
        result.push_back(post);
        return result;
    }
private:
    vector<int> pre;
    vector<int> mid;
    vector<int> post;
    void Pre(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        pre.push_back(root->val);
        Pre(root->left);
        Pre(root->right);
    }
    void Mid(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        Mid(root->left);
        mid.push_back(root->val);
        Mid(root->right);
    }
    void Post(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        Post(root->left);
        Post(root->right);
        post.push_back(root->val);
    }
};