#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
        //创建虚拟头节点
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* pre = fake_head;
        ListNode* cur = head;
        while(cur)
        {
            if(cur->val==val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return fake_head->next;
    }
};