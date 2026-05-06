#include<iostream>

using namespace std;

struct ListNode
{
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};
 

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(small_than_k(head, k))
            //长度小于k的链表直接返回
            return head;
        ListNode* head_copy = head;
        int count = 0;
        while(count<k-1)
        {
            count += 1;
            head_copy = head_copy->next;
        }
        //此时head_copy刚好到达第k个节点
        ListNode* new_head = head_copy->next;
        if(new_head==nullptr)
            //如果链表长度恰好为k，则直接反转链表
            return reverseList(head);
        //否则进行递归
        else
        {
            //断开第k个节点和第k+1个节点
            head_copy->next = nullptr;
            reverseList(head);
            //此时前k个节点中头结点为head_copy,尾节点为head
            head->next = reverseKGroup(new_head, k);
            return head_copy;
        }
    }
private:
    bool small_than_k(ListNode* head, int k)
    {
        //判断一个链表长度是否小于k
        int length = 0;
        while(head)
        {
            length += 1;
            head = head->next;
        }
        return length<k;
    }
    ListNode* reverseList(ListNode* head)
    {
        //反转链表(迭代写法，还有数组写法和递归写法，见leetcode206题)
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* nextTemp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextTemp;
        }
        return pre;
    }
};