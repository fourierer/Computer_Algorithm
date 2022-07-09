
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //首先判断是否为空
        if(pNode==NULL)
            return NULL;
        
        //其次考虑是否有右孩子，因为中序遍历下一个节点在右孩子一侧，右孩子的最左孩子
        if(pNode->right!=NULL)
        {
            pNode = pNode->right;
            while(pNode->left!=NULL)
                pNode = pNode->left;
            return pNode;
        }

        //如果没有右孩子，中序遍历要考虑父节点，所以需要先判断是否为根节点，如果是根节点直接返回NULL
        if(pNode->next==NULL)
            return NULL;
        
        //不是根节点，即该节点有父节点，需要一直寻找父节点，直到某个父节点也是它的父节点的左孩子时，返回该父节点的父节点
        //如果没找到，说明一直是父节点的右孩子，则直接返回NULL
        while(pNode->next!=NULL)
        {
            if(pNode==pNode->next->left)
                return pNode->next;
            pNode = pNode->next;
        }
        return NULL;
    }
};