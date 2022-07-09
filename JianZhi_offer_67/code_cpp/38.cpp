#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归写法
// class Solution {
// public:
//     int TreeDepth(TreeNode* pRoot)
//     {
//         if(pRoot==NULL)
//         {
//             return 0;
//         }
//         else
//         {
//             int l = TreeDepth(pRoot->left);
//             int r = TreeDepth(pRoot->right);
//             return (l>r?l:r) + 1;
//         }
//     }
// };

//非递归写法
class Solution{
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        
        int length = 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty())
        {
            int tmp = q.size();
            length++;
            vector<TreeNode*> v = pop(q);
            for(int i = 0;i<tmp;i++)
            {
                if(v[i]->left)
                    q.push(v[i]->left);
                if(v[i]->right)
                    q.push(v[i]->right);
            }
        }
        return length;
    }
private:
    vector<TreeNode*> pop(queue<TreeNode*> &q)
    {
        vector<TreeNode*> v;
        while(!q.empty())
        {
            TreeNode* root = q.front();
            q.pop();
            v.push_back(root);
        }
        return v;
    }
};


