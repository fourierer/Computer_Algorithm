#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right),left(left),right(right){}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        //x和y的深度
        int dx = 0;
        int dy = 0;
        int h = 0;
        //x和y的父节点
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            h++;
            int size = q.size();
            //下面必须使用一个for循环，因为要保证同一层的节点对应的h高度是一样的
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                {
                    if(tmp->left->val==x)
                    {
                        dx = h+1;
                        px = tmp;
                    }
                    else if(tmp->left->val==y)
                    {
                        dy = h+1;
                        py = tmp;
                    }
                    q.push(tmp->left);
                }

                if(tmp->right)
                {
                    if(tmp->right->val==x)
                    {
                        dx = h+1;
                        px = tmp;
                    }
                    else if(tmp->right->val==y)
                    {
                        dy = h+1;
                        py = tmp;
                    }
                    q.push(tmp->right);
                }
            }
        }
        return (dx==dy)&&(px!=py);
    }
};