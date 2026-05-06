#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        MidOrder(root);
        int Min = INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            Min = min(Min,abs(v[i]-v[i-1]));
        }
        return Min;
    }
private:
    vector<int> v;
    void MidOrder(TreeNode* root)
    {
        if(!root)
            return;
        MidOrder(root->left);
        v.push_back(root->val);
        MidOrder(root->right);
    }
};