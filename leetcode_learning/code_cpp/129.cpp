#include<iostream>
#include<queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//解法一、深度优先遍历
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

//解法二、广度优先遍历
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        queue<TreeNode*> nodeQueue;//存储树的每个节点
        queue<int> numQueue;//存储树的每个节点上的数字之和，该数字之和是根节点到该点的数字之和
        nodeQueue.push(root);
        numQueue.push(root->val);
        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            int num = numQueue.front();
            nodeQueue.pop();
            numQueue.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left == NULL && right == NULL)
                sum += num;//当该节点是叶子节点时，求和
            else
            {
                if (left != NULL)
                {
                    nodeQueue.push(left);
                    numQueue.push(num * 10 + left->val);
                }
                if (right != NULL)
                {
                    nodeQueue.push(right);
                    numQueue.push(num * 10 + right->val);
                }
            }
        }
        return sum;
    }
};





