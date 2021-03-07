//Definition for singly-linked list.
#include<iostream>
#include<vector>


struct ListNode
{     
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.size()==0)
            return nullptr;
        ListNode* L = lists[0];
        for(int i=1;i<lists.size();i++)
            L = merge2list(L, lists[i]);
        return L;
    }
private:
    ListNode* merge2list(ListNode* l1, ListNode* l2)
    {
        ListNode* fake_head = new ListNode(0);
        ListNode* cur = fake_head;
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
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return fake_head->next;
    }
};