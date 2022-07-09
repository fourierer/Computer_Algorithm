#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode()
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        if(!root)
            return {true,true};
        vector<bool> result;
        result.push_back(IsSearch(root));
        result.push_back(IsComplete(root));
        return result;
    }
private:
    vector<int> v;
    void MidOrder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        MidOrder(root->left);
        v.push_back(root->val);
        MidOrder(root->right);
    }
    bool IsSearch(TreeNode* root)
    {
        MidOrder(root);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>v[i+1])
                return false;
        }
        return true;
    }

    //计算“如果是完全二叉树”的节点个数
    int count_node(TreeNode* root)
    {
        int count = 0;
        vector<int> node;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            node.push_back(tmp->val);
            //遇到空树，将队列中的树节点和当前已遍历过的节点个数相加之后之后再结束遍历
            if(tmp->left)
                q.push(tmp->left);
            else
            {
                count = node.size()+q.size();
                break;
            }
            if(tmp->right)
                q.push(tmp->right);
            else
            {
                count = node.size()+q.size();
                break;
            }
        }
        return count;
    }
    bool IsComplete(TreeNode* root)
    {
        int count = count_node(root);
        if(v.size()==count)
            return true;
        return false;
    }
};