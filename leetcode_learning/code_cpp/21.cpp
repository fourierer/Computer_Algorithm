//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//最终返回的头节点前面一个节点
        ListNode* cur = head;//当前插入节点的位置
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;//当前节点位置插完，cur转到下一个节点位置
        }
        //判断此时哪个子链表还没有遍历完，将cur指向未遍历完的那一个链表
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return head->next;
    }
};