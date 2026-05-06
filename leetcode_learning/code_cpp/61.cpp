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

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(k==0||head==nullptr||head->next==nullptr)
            return head;
        int len = length(head);
        k = k % len;//防止重复次数过多，可以取余数
        k++;//k+1为了下面的while循环可以重复k次
        while(k=k-1)
            head = OneNode(head);
        return head;
    }
private:
    //向右移动一个节点
    ListNode* OneNode(ListNode* head)
    {
        ListNode* final_two = head;
        while(final_two->next->next)
            final_two = final_two->next;
        //此时final_two指向倒数第二个节点
        ListNode* final_one = final_two->next;
        final_two->next = nullptr;
        final_one->next = head;
        return final_one;
    }

    //计算一个链表的长度
    int length(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};


