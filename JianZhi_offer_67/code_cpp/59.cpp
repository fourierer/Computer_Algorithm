
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot==NULL)
            return result;
        stack1.push(pRoot);//stack1放根节点（奇数行节点）
        while(!stack1.empty()||!stack2.empty())
        {
            vector<int> ret1,ret2;
            TreeNode* cur = NULL;
            //偶数行放stack2中
            while(!stack1.empty())
            {
                cur = stack1.top();
                if(cur->left!=NULL)
                    stack2.push(cur->left);
                if(cur->right!=NULL)
                    stack2.push(cur->right);
                ret1.push_back(cur->val);
                stack1.pop();
            }
            if(ret1.size()!=0)
                result.push_back(ret1);

            //奇数行放stack1
            while(!stack2.empty())
            {
                cur = stack2.top();
                if(cur->right!=NULL)
                    stack1.push(cur->right);
                if(cur->left!=NULL)
                    stack1.push(cur->left);
                ret2.push_back(cur->val);
                stack2.pop();
            }
            if(ret2.size()!=0)
                result.push_back(ret2);
        }
        return result;
    }
private:
    stack<TreeNode*> stack1;
    stack<TreeNode*> stack2;
};