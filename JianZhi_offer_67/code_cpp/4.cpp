#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}//覆盖构造函数
    TreeNode() : val(0), left(NULL), right(NULL) {}//默认构造函数
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int length = pre.size();
        if(length==0)
        {
            return NULL;
        }
        TreeNode* head = new TreeNode;
        head->val = pre[0];
        vector<int> left_pre, left_vin, right_pre, right_vin;

        //在中序遍历中寻找根节点的位置
        int gen = 0;
        for(int i=0;i<length;i++)
        {
            if(vin[i]==pre[0])
            {
                gen = i;
                break;
            }
        }

        //确定根节点左子树的先序和中序遍历数组
        for(int i=0;i<gen;i++)
        {
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }
        
        //确定根节点左子树的先序和中序遍历数组
        for(int i=gen+1;i<length;i++)
        {
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }

        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);
        
        return head;
    }
};


int main()
{
    return 0;
}


