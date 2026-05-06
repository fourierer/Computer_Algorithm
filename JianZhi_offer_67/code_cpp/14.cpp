struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, int k) {
        ListNode* pre = NULL;
        ListNode* p = NULL;
        pre = pListHead;
        p = pListHead;
        int length = k;//记录k
        int count = 0;//记录节点个数，后续需要和k比较
        while(p!=NULL)
        {
            p = p->next;
            count++;
            if(k<=0)
                pre = pre->next;
            k--;
        }
        if(count<length)
            return NULL;
        return pre;
    }
};
