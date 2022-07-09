//未完成
class Solution {
public:
    //复制原始链表的任一节点N并创建新节点N'，再把N'链接到N的后边
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=new RandomListNode(0);
            pCloned->label=pNode->label;
            pCloned->next=pNode->next;
            pCloned->random=NULL;
              
            pNode->next=pCloned;
              
            pNode=pCloned->next;
        }
    }
    //如果原始链表上的节点N的random指向S，则对应的复制节点N'的random指向S的下一个节点S'
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=pNode->next;
            if(pNode->random!=NULL)
                pCloned->random=pNode->random->next;
            pNode=pCloned->next;
        }
    }
    //把得到的链表拆成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
    RandomListNode* ReConnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
          
        //初始化
        if(pNode!=NULL)
        {
            pClonedHead=pClonedNode=pNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
              
        }
        //循环
        while(pNode!=NULL)
        {
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
        }
          
        return pClonedHead;
          
    }
    //三步合一
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReConnectNodes(pHead);
    }
};