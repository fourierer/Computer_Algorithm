#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        queue<TreeNode*> q;
        q.push({root});
        int flag = 1;//1表示该层正序遍历，0表示该层逆序遍历
        while(!q.empty())
        {
            vector<int> layer;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flag==0)
                reverse(layer.begin(), layer.end());
            flag = 1 - flag;
            result.push_back(layer);
        }
        return result;
    }
};