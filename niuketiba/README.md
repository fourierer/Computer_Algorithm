# 牛客题霸

#### NC33.将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的，且合并后新链表依然有序。

```c++
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
```



#### NC51.合并$k$个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。 

```c++
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
```

