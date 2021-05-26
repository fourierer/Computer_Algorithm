
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;//记录当前节点的位置

        while(pHead1!=NULL&&pHead2!=NULL)
        {
            if(pHead1->val<=pHead2->val)
            {
                ListNode* New = new ListNode(-1);
                New->val = pHead1->val;
                cur->next = New;
                cur = New;
                pHead1 = pHead1->next;
            }
            else
            {
                ListNode* New = new ListNode(-1);
                New->val = pHead2->val;
                cur->next = New;
                cur = New;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1!=NULL)
            cur->next = pHead1;
        if(pHead2!=NULL)
            cur->next = pHead2;
        return head->next;
    }
};