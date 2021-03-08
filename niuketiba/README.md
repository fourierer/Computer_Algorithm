# 牛客题霸



#### NC1.以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string solve(string s, string t) {
        int length_s = s.length();
        int length_t = t.length();
        int L = max(length_s, length_t);
        //保证s比t长
        if(length_s<length_t)
        {
            string temp = t;
            t = s;
            s = temp;
        }
        //填充一个新的字符串t1，使得比s短的部分填充为0，其余和t一致
        string t1(s.length(), '0');
        int l = s.length() - t.length();
        //cout<<l<<endl;
        for(int i=0;i<s.length();i++)
        {
            if(i<l)
                ;
            else
                t1[i] = t[i-l];
        }
        //cout<<s<<endl;
        //cout<<t1<<endl;
        int flag = 0;//进位标志
        string result(L + 1, '0');
        for(int i = L;i>=1;i--)
        {
            int r = (s[i-1]-'0')+(t1[i-1]-'0') + flag;
            if(r>=10)
            {
                flag = 1;
                result[i] = r%10 + '0';
            }
            else
            {
                flag = 0;
                result[i] = r + '0';
            }
        }
        //cout<<result<<endl;
        //处理result第一位
        if(flag==1)
        {
            result[0] = 1 + '0';
            return result;
        }
        else
        {
            string Result(s.length(), '0');
            for(int i=0;i<s.length();i++)
                Result[i] = result[i+1];
            return Result;
        }
    }
};


int main()
{
    string s = "99236";
    string t = "23444";
    Solution S;
    string result = S.solve(s,t);
    cout<<result<<endl;
    return 0;
}
```





#### NC3.对于一个给定的链表，返回环的入口节点，如果没有环，返回null。

```c++
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
```







#### NC4.判断给定的链表中是否有环。如果有环则返回true，否则返回false。

```c++
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
```





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

