#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here 
        ListNode* cur = pHead;
        ListNode* pre = pHead;
        k = k+1;//这样下面的while循环可以走k个节点
        while(k=k-1)
        {
            if(cur==nullptr)
                return nullptr;
            cur = cur->next;
        }
        while(cur)
        {
            pre = pre->next;
            cur = cur->next;
        }
        //此时pre指向倒数第k个节点
        return pre;
    }
};