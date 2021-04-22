#include<iostream>

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
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return dfs(root, o1, o2)->val;
    }
private:
    TreeNode* dfs(TreeNode* root, int o1, int o2)
    {
        //如果当前节点为空，或者节点值等于o1或者o2，则直接返回该节点
        if(root==nullptr||root->val==o1||root->val==o2)
            return root;
        //遍历左子树
        TreeNode* left = dfs(root->left, o1, o2);
        //遍历右子树
        TreeNode* right = dfs(root->right, o1, o2);
        //如果左右子树不为空，说明左右子树(或者左右子树下面的子节点)分别包含o1或者o2
        if(left!=nullptr&&right!=nullptr)
            return root;
        //如果左右子树均为空，则返回空
        //如果左右子树有一个不空，则返回不空的那个，不空的(或者其下面的子节点)一定包含o1或者o2，空的(及其下面的子节点)一定不包含o1或者o2
        return left!=nullptr?left:right;
    }
};