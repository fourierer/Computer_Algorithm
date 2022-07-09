#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //从root出发DFS，记录每个结点的父结点
        findParenets(root);

        //从target出发DFS，寻找所有深度为k的结点
        findAns(target, nullptr, 0, k);

        return ans;
    }

private:
    map<int, TreeNode*> parenets;
    vector<int> ans;

    void findParenets(TreeNode* node)
    {
        if(node->left!=nullptr)
        {
            parenets[node->left->val] = node;
            findParenets(node->left);
        }
        if(node->right!=nullptr)
        {
            parenets[node->right->val] = node;
            findParenets(node->right);
        }
    }

    void findAns(TreeNode* node, TreeNode* from, int depth, int k)
    {
        //from表示当前遍历过程中节点node的上一个节点，depth表示当前节点node的深度
        if(node==nullptr)
            return;
        if(depth==k)
        {
            ans.push_back(node->val);
            return;
        }

        //防止向下遍历时又回到遍历过程中当前节点上一个节点
        if(node->left!=from)
            findAns(node->left, node, depth+1, k);
        if(node->right!=from)
            findAns(node->right, node, depth+1, k);
        
        //防止向上遍历时又回到遍历过程中当前节点上一个节点
        if(parenets[node->val]!=from)
            findAns(parenets[node->val], node, depth+1, k);
    }
};
