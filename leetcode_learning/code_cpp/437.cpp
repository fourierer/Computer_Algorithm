#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        //遍历root，同时计算以root为起点来计算等于路径和等于targetSum的路径数
        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
private:
    //以root为起点来计算等于路径和等于targetSum的路径数
    int rootSum(TreeNode* root, int targetSum)
    {
        if(!root)
            return 0;
        
        int ret = 0;
        if(root->val==targetSum)
            ret++;
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }
};

