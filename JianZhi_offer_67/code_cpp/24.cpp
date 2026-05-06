class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> path;
    void find(TreeNode* root, int sum)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if((root->left==NULL)&&(root->right==NULL)&&(sum==root->val))
            res.push_back(path);
        else
        {
            if(root->left!=NULL)
                find(root->left, sum-root->val);
            if(root->right!=NULL)
                find(root->right, sum-root->val);
        }
        path.pop_back();//某个节点左右孩子都遍历完了，需要pop出路径中的当前节点
    }
};

//变形，输出树中的所有路径
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root) {
        find(root);
        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> path;
    void find(TreeNode* root)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if((root->left==NULL)&&(root->right==NULL))
            res.push_back(path);
        else
        {
            if(root->left!=NULL)
                find(root->left);
            if(root->right!=NULL)
                find(root->right);
        }
        path.pop_back();//某个节点左右孩子都遍历完了，需要pop出路径中的当前节点
    }
};
