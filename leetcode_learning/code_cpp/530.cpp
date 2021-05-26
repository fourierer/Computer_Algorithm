/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        GetMidOrder(root);
        int minval = GetMinVal(v);
        return minval;
    }

private:
    vector<int> v;
    void GetMidOrder(TreeNode* root)
    {
        if(root==NULL)
            return;
        GetMidOrder(root->left);
        v.push_back(root->val);
        GetMidOrder(root->right);
    }
    int GetMinVal(vector<int> v)
    {
        int n = v.size();
        int minval = v[1]-v[0];
        for(int i=0;i<n-1;i++)
        {
            int temp = v[i+1]-v[i]);
            if(minval>temp)
                minval = temp;
        }
        return minval;
    }
};