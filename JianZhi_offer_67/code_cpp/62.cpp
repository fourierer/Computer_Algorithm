class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k<=0)
            return NULL;
        MidOrder(pRoot);
        int length = v.size();
        if(k>length)
            return NULL;
        return v[k-1];
    }

private:
    vector<TreeNode*> v;
    void MidOrder(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return;
        MidOrder(pRoot->left);
        v.push_back(pRoot);
        MidOrder(pRoot->right);
    }
};