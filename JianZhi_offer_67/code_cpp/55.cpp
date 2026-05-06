
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast = pHead;
        ListNode* low = pHead;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast = fast->next->next;
            low = low->next;
            if(fast==low)
                break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;//fast为NULL，则不存在环
        low = pHead;
        while(fast!=low)
        {
            fast = fast->next;
            low = low->next;
        }
        return low;
    }
};
//第一个while和if中的判断条件，fast和fast->next缺一不可

//使用数据结构map简单求解
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;
        map<ListNode*, int> node_count;
        ListNode* p = pHead;
        while(p!=NULL)
        {
            node_count[p]++;
            if(node_count[p]==2)
                return p;
            p = p->next;
        }
        return NULL;
    }
};
