//解法一、直接层次遍历树，输出节点个数
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<TreeNode*> v;
        if(root==NULL)
            return v.size();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            v.push_back(node);
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return v.size();
    }
};

//解法二、解法一中的时间复杂度为O(n),空间复杂度也为O(n)，可以采用原地计数的方法来节省空间
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<TreeNode*> v;
        if(root==NULL)
            return v.size();
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        while(!q.empty())
        {
            //遍历当前层所有节点
            int size = q.size();//记录当前层的节点个数，使用q.size()则会发生变化
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                v.push_back(node);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(q.empty())
                return pow(2, layer) - 1 + size;
            layer++;//遍历完一层，层数加1
        }
        return 0;//实际上不会执行，为了通过编译
    }
};
