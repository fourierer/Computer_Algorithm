#include<iostream>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//用一个数组分别记录偷根节点和不偷根节点时的最大值
class Solution {
public:
    int rob(TreeNode* root) {
        int * res = doRob(root);
        return max(res[0],res[1]);
    }

    int * doRob(TreeNode * root)
    {
        int * res = new int[2];
        res[0] = 0;
        res[1] = 0;
        if(root == NULL)
            return res;
        int* left = doRob(root->left);
        int * right = doRob(root->right);
        //不偷根节点，最大值为两个子树的最大值之和
        res[0] = max(left[0],left[1])+max(right[0],right[1]);
        //偷根节点，最大值为两个子树不包含根节点的最大值加上根节点的值
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};