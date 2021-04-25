#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}
};

//解法一：先中序遍历，再重建二叉树
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //中序遍历
        Mid(root);
        //根据中序遍历结果重建二叉树
        TreeNode* fake_head = new TreeNode(0);
        TreeNode* cur = fake_head;
        for(int i=0;i<v.size();i++)
        {
            TreeNode* head = new TreeNode(v[i]);
            cur->right = head;
            cur = head;
        }
        return fake_head->right;
    }
private:
    vector<int> v;
    void Mid(TreeNode* root)
    {
        if(!root)
            return;
        Mid(root->left);
        v.push_back(root->val);
        Mid(root->right);
    }
};

//解法二：中序遍历过程直接改变节点指向
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root){
        TreeNode* fake_head = new TreeNode(0);
        cur = fake_head;
        Mid(root);
        return fake_head->right;
    }
    //必须是public，因为涉及私有变量cur的更改
    void Mid(TreeNode* root)
    {
        if(!root)
            return;
        Mid(root->left);
        //更改节点指向
        cur->right = root;
        root->left = nullptr;
        cur = root;
        Mid(root->right);
    }
private:
    TreeNode* cur;
};
