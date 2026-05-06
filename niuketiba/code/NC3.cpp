#include<iostream>
#include<map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)
            return nullptr;
        map<ListNode*, int> ListNode_map;
        while(head)
        {
            ListNode_map[head]++;
            if(ListNode_map[head]==2)
                return head;
            head = head->next;
        }
        return nullptr;
    }
};

