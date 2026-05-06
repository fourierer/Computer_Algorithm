struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > matrix;
            if(pRoot==NULL)
                return matrix;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                int cur = 0;
                int len = q.size();
                vector<int> row;
                while(cur<len)
                {
                    cur++;
                    TreeNode* p = q.front();
                    q.pop();
                    row.push_back(p->val);
                    if(p->left!=NULL)
                        q.push(p->left);
                    if(p->right!=NULL)
                        q.push(p->right);
                }
                matrix.push_back(row);
            }
            return matrix;
        }
};
