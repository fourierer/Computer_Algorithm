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
    TreeNode(int x, TreeNode*left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = fun(root1);
        vector<int> leaf2 = fun(root2);
        if(leaf1.size()!=leaf2.size())
            return false;
        else
        {
            for(int i=0;i<leaf2.size();i++)
                if(leaf1[i]!=leaf2[i])
                    return false;
        }
        return true;
    }
private:
    //求一棵树的叶子节点序列(叶值序列)
    vector<int> fun(TreeNode* root)
    {
        vector<int> leaf;
        Mid(root, leaf);
        return leaf;
    }
    void Mid(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        Mid(root->left, v);
        if((root->left==nullptr)&&(root->right==nullptr))
            v.push_back(root->val);
        Mid(root->right, v);
    }
};

