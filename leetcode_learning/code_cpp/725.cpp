#include<iostream>
#include<vector>

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        //计算链表长度
        while(temp!=nullptr)
        {
            n++;
            temp = temp->next;
        }
        //计算商和余数
        //则在分隔成的k个部分中，前remainder个部分的长度各为quotient+1其余每个部分的长度各为quotient
        int quotient = n/k;
        int remainder = n%k;

        vector<ListNode*> parts(k, nullptr);
        ListNode* curr = head;
        for(int i=0;i<k&&curr!=nullptr;i++)
        {
            parts[i] = curr;
            int partSize = quotient + (i<remainder?1:0);//前remainder个部分的长度各为quotient+1其余每个部分的长度各为quotient
            for(int j=1;j<partSize;j++)
            {
                curr = curr->next;
            }
            //第i个分割的链表，断开curr和curr->next;
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return parts;
    }
};
