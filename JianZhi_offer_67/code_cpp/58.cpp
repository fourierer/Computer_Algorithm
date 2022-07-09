
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        else if(pRoot->left==NULL&&pRoot->right==NULL)
            return true;
        else if(pRoot->left==NULL||pRoot->right==NULL)
            return false;
        else
            return (pRoot->left->val==pRoot->right->val)&&isSymmetrical(pRoot->left)&&isSymmetrical(pRoot->right);
    }
};
*/

//递归解法
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return IsSymmetrical(pRoot->left, pRoot->right);
    }
private:
    bool IsSymmetrical(TreeNode* left, TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        else if(left==NULL||right==NULL)
            return false;
        return (left->val==right->val)&&IsSymmetrical(left->left, right->right)&&IsSymmetrical(left->right, right->left);
    }
};

//DFS深度优先遍历，使用数据结构栈stack
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        stack<TreeNode*> s;
        //成对进入栈
        s.push(pRoot->left);
        s.push(pRoot->right);
        while(!s.empty())
        {
            TreeNode* left = s.top();
            s.pop();
            TreeNode* right = s.top();
            s.pop();
            if(left==NULL&&right==NULL)
                continue;
            else if(left==NULL||right==NULL)
                return false;
            else if(left->val!=right->val)
                return false;
            //成对进入栈
            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);                
        }
        return true;
    }
};


//BFS广度优先遍历，使用数据结构队列queue
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        queue<TreeNode*> q;
        //成对进入队列
        q.push(pRoot->left);
        q.push(pRoot->right);
        while(!q.empty())
        {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if(left==NULL&&right==NULL)
                continue;
            else if(left==NULL||right==NULL)
                return false;
            else if(left->val!=right->val)
                return false;
            //成对进入队列
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};


