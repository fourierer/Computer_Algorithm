class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode* root, int presum)
    {
        if(root==NULL)
            return 0;
        int sum = presum*10 + root->val;
        if(root->right==NULL&&root->left==NULL)
            return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};