class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(TreeDepth(pRoot)==-1)
            return false;
        return true;
    }
private:
    //在计算树深度的同时，判断是否为平衡二叉树；
    //平衡二叉树要求树的每个节点，左右子树节点深度差不超过1;
    //如果不是平衡二叉树，返回-1，否则返回树的深度;
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int left = TreeDepth(pRoot->left);
        if(left==-1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if(right==-1)
            return -1;
        return abs(left-right)>1?-1:max(left, right) + 1;
    }
};