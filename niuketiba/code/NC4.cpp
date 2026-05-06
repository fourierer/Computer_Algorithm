#include<map>


// Definition for singly-linked list. 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullpter) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
            return false;
        map<ListNode*, int> ListNode_map;
        while(head)
        {
            ListNode_map[head]++;
            if(ListNode_map[head]==2)
                return true;
            head = head->next;
        }
        return false;
    }
};

