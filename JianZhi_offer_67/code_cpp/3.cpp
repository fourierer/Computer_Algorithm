#include<iostream>
#include<vector>

struct ListNode{
    int val;
    ListNode * next;
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int length = v.size();
        vector<int> v1;
        for(int i=0;i<length;i++)
        {
            v1.push_back(v[length-i-1]);
        }
        return v1;
    }
};


ListNode * create()
{
    ListNode * head = new ListNode;//表头，函数返回值
    head->val = -1;
    head->next = NULL;

    ListNode * cur = head;//当前节点


    while(1)
    {
        int data;
        cout<<"请输入当前节点的值："<<endl;
        cin>>data;
        if(data==-1)
        {
            break;
        }

        ListNode* New = new ListNode;
        New->val = data;
        New->next = NULL;
        cur->next = New;
        cur = New;
    }

    return head;
}


int main()
{
    ListNode∗ list = create();
    while(list !=NULL)
    {
        cout<<list−>val<<” ”;
        list = list−>next;
    }
    return 0;
}


