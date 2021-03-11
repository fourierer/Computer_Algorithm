#include<iostream>
#include<vector>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        find(root, sum);
        return result;
    }
private:
    vector<vector<int> > result;
    vector<int> path;
    void find(TreeNode* root, int sum)
    {
        if(root==nullptr)
            return;
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&root->val==sum)
            result.push_back(path);
        else
        {
            if(root->left!=nullptr)
                find(root->left, sum-root->val);
            if(root->right!=nullptr)
                find(root->right, sum-root->val);
        }
        path.pop_back();//将当前节点pop出来，维护当前路径数组
    }
};