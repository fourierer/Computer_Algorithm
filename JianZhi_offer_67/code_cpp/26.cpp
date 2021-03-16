#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return NULL;
        ConvertSub(pRootOfTree);
        return realHead;
    }

private:
    TreeNode* Head = NULL;
    TreeNode* realHead = NULL;
    void ConvertSub(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return;
        ConvertSub(pRootOfTree->left);
        if(Head==NULL)
        {
            Head = pRootOfTree;
            realHead = pRootOfTree;
        }
        else
        {
            Head->right = pRootOfTree;
            pRootOfTree->left = Head;
            Head = pRootOfTree;
        }
        ConvertSub(pRootOfTree->right);
    }
};