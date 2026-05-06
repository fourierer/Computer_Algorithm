//解法一、使用链表数组来存储链表，再根据索引的奇偶性重构链表，时间复杂度和空间复杂度都为O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return head;
        vector<ListNode*> node_v;
        //数组存储链表节点
        while(head!=NULL)
        {
            node_v.push_back(head);
            head = head->next;
        }

        int i = 0; //记录当前节点位置
        for(i=2;i<node_v.size();i=i+2)
            node_v[i-2]->next = node_v[i];
        i = i-2;//for循环使得最后i超出两个位置
        node_v[i]->next = node_v[1];//奇数索引的最后一个要指向偶数索引第一个
        
        for(i=3;i<node_v.size();i=i+2)
            node_v[i-2]->next = node_v[i];
        i = i-2;//for循环使得最后超出两个位置
        node_v[i]->next = NULL;//最后一个位置的节点要指向NULL，否则会出现环

        return node_v[0];
    }
};

//解法二、原地将原链表拆分为奇偶链表，再组合起来（官方源码），时间复杂度为O(N)，空间复杂度都为O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return head;
        ListNode* even_head = head->next;//偶链表的头节点
        ListNode* odd = head;
        ListNode* even = even_head;
        while(even&&even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

