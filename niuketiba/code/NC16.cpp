#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//以下代码有问题
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->right==nullptr&&root->left==nullptr)
            return true;
        if(root->right!=nullptr&&root->left!=nullptr)
        {
            return (root->left->val==root->right->val)&&(isSymmetric(root->left))&&(isSymmetric(root->right));
        }
        return false;
    }
};
*/

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr&&right==nullptr)
            return true;
        if(left==nullptr||right==nullptr)
            return false;
        else
            return (left->val==right->val)&&symmetric(left->left, right->right)&&symmetric(left->right, right->left);
    }
};

//非递归，采用层次遍历来验证每层是否对称
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        if((root->left==nullptr)&&(root->right==nullptr))
            return true;
        if((root->left==nullptr)||(root->right==nullptr))
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            if(size%2==1&&size!=1)
                return false;
            vector<TreeNode* > v =  pop(q);
            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = v[i];
                if(node1->left)
                    q.push(node1->left);
                if(node1->right)
                    q.push(node1->right);
                TreeNode* node2 = v[size - i - 1];
                if(!symmetric(node1, node2))
                    return false;
            }
        }
        return true;
    }
private:
    bool symmetric(TreeNode* node1, TreeNode* node2)
    {
        bool flag1, flag2;
        flag1 = (node1->left!=nullptr)&&(node2->right!=nullptr);
        flag2 = (node1->right!=nullptr)&&(node2->left!=nullptr);
        if((node1->left==nullptr)&&(node2->right==nullptr)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag1&&(node1->left->val==node2->right->val)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag2&&(node1->right->val==node2->left->val)&&(node1->left==nullptr)&&(node2->right==nullptr))
            return true;
        if(flag1&&flag2&&(node1->left->val==node2->right->val)&&(node1->right->val==node2->left->val))
            return true;
        return false;
    }

    vector<TreeNode*> pop(queue<TreeNode*> &q)
    {
        vector<TreeNode*> v;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node);
        }
        return v;
    }
};
