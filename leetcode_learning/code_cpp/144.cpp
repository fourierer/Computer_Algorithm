/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        PreOrder(root);
        return v;
    }
private:
    vector<int> v;
    void PreOrder(TreeNode* root)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
};

//非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
            while(root)
            {
                v.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            if(!s.empty())
            {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return v;
    }
};


