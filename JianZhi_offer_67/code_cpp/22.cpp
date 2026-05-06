/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
        vector<int> PrintFromTopToBottom(TreeNode* root) {
            vector<int> matrix;
            if(root==NULL)
                return matrix;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode* p = q.front();
                q.pop();
                matrix.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            return matrix;
        }
};

