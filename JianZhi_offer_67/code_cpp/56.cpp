
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//删除重复的元素，如1,2,3,3,4,4,5-->1,2,3,4,5
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode* p = pHead;
        while(p!=NULL&&p->next!=NULL)
        {
            if(p->val==p->next->val)
            {
                ListNode* post = p->next->next;
                p->next = post;
                p = post;
            }
            else
                p = p->next;
        }
        return pHead;
    }
};



//删除所有重复的元素，如1,2,3,3,4,4,5-->1,2,5
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode* newHead = new ListNode(-1);
        newHead->next = pHead;//创建新的头结点，防止头结点是重复的被删除
        ListNode* pre = newHead;
        ListNode* p = pHead;
        while(p!=NULL&&p->next!=NULL)
        {
            ListNode* pnext = p->next;//用于搜索重复的节点
            if(p->val==pnext->val)
            {
                //开始搜索重复的节点
                while(pnext!=NULL&&pnext->val==p->val)
                    pnext = pnext->next;
                //删除重复的节点
                pre->next = pnext;
                //删除之后，再重新从下一个不重复的节点开始
                p = pnext;
            }
            else
            {
                //继续搜索
                pre = p;
                p = p->next;
            }
        }
        return newHead->next;
    }
};



