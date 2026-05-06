#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left), right(right){}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        Mid(root);
        int Sum = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=low&&v[i]<=high)
                Sum += v[i];
        }
        return Sum;
    }
private:
    vector<int> v;
    void Mid(TreeNode* root)
    {
        if(!root)
            return;
        Mid(root->left);
        v.push_back(root->val);
        Mid(root->right);
    }
};