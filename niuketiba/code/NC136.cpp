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
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        //先重建二叉树
        TreeNode* head = reconstruct(xianxu, zhongxu);
        //再输出该二叉树的右视图，即每一层最右边的节点
        vector<int> result = rightview(head);
        return result;
    }
private:
    //二叉树所有节点的值互不相同才可以用下面的函数重建
    TreeNode* reconstruct(vector<int>& pre, vector<int>& mid)
    {
        int size = pre.size();
        if(size==0)
            return nullptr;
        //创建根节点
        TreeNode* head = new TreeNode(0);
        head->val = pre[0];
        //在中序遍历中寻找根节点
        int index = 0;
        for(int i=0;i<size;i++)
        {
            if(mid[i]==pre[0])
            {
                index = i;
                break;
            }
        }
        //根据找到的根节点划分左右子树的先序和中序数组
        vector<int> l_pre, l_mid, r_pre, r_mid;
        for(int i=0;i<index;i++)
        {
            l_pre.push_back(pre[i+1]);
            l_mid.push_back(mid[i]);
        }
        for(int i=index+1;i<size;i++)
        {
            r_pre.push_back(pre[i]);
            r_mid.push_back(mid[i]);
        }
        //递归重建当前节点的左右子树
        head->left = reconstruct(l_pre,l_mid);
        head->right = reconstruct(r_pre, r_mid);
        
        return head;
    }

    vector<int> rightview(TreeNode* head)
    {
        vector<int> result;
        if(head==nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(head);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* root = q.front();
                q.pop();
                if(i==(size-1))
                    result.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return result;
    }
};