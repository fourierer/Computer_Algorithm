/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //解法一：使用ListNode*数组来存储节点，再逆序构造新链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next==NULL)
            return head;
        ListNode* p = head;
        while(p)
        {
            v.push_back(p);
            p = p->next;
        }
        int length = v.size();
        for(int i=length-1;i>0;i--)
        {
            v[i]->next = v[i-1];
        }
        v[0]->next = NULL;
        return v[length-1];
    }
private:
    vector<ListNode*> v;
};

//解法二：迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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

//解法三：递归

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};