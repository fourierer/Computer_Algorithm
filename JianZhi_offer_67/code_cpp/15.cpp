
struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p = NULL;
        ListNode* pre = NULL;
        while(pHead!=NULL)
        {
            p = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = p;
        }
        return pre;

    }
};