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



#### NC7.假设你有一个数组，其中第$i$个元素是股票在第$i$天的价格。

只有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        //维护一个历史最低点，把该历史最低点当成买入点
        int max_profit = 0;
        int min_prices = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i]-min_prices);
            min_prices = min(min_prices, prices[i]);
        }
        return max_profit;
    }
};
```



#### NC16.给定一棵二叉树，判断琪是否是自身的镜像（即：是否对称）

```c++
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//以下代码有问题
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->right==nullptr&&root->left==nullptr)
            return true;
        if(root->right!=nullptr&&root->left!=nullptr)
        {
            return (root->left->val==root->right->val)&&(isSymmetric(root->left))&&(isSymmetric(root->right));
        }
        return false;
    }
};
*/

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr&&right==nullptr)
            return true;
        if(left==nullptr||right==nullptr)
            return false;
        else
            return (left->val==right->val)&&symmetric(left->left, right->right)&&symmetric(left->right, right->left);
    }
};

//非递归，采用层次遍历来验证每层是否对称
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        if((root->left==nullptr)&&(root->right==nullptr))
            return true;
        if((root->left==nullptr)||(root->right==nullptr))
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            if(size%2==1&&size!=1)
                return false;
            vector<TreeNode* > v =  pop(q);
            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = v[i];
                if(node1->left)
                    q.push(node1->left);
                if(node1->right)
                    q.push(node1->right);
                TreeNode* node2 = v[size - i - 1];
                if(!symmetric(node1, node2))
                    return false;
            }
        }
        return true;
    }
private:
    bool symmetric(TreeNode* node1, TreeNode* node2)
    {
        bool flag1, flag2;
        flag1 = (node1->left!=nullptr)&&(node2->right!=nullptr);
        flag2 = (node1->right!=nullptr)&&(node2->left!=nullptr);
        if((node1->left==nullptr)&&(node2->right==nullptr)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag1&&(node1->left->val==node2->right->val)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag2&&(node1->right->val==node2->left->val)&&(node1->left==nullptr)&&(node2->right==nullptr))
            return true;
        if(flag1&&flag2&&(node1->left->val==node2->right->val)&&(node1->right->val==node2->left->val))
            return true;
        return false;
    }

    vector<TreeNode*> pop(queue<TreeNode*> &q)
    {
        vector<TreeNode*> v;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node);
        }
        return v;
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



#### NC50.将给出的链表中的节点每\ k *k* 个一组翻转，返回翻转后的链表如果链表中的节点数不是\ k *k* 的倍数，将最后剩下的节点保持原样。你不能更改节点中的值，只能更改节点本身，要求空间复杂度 $O(1)$。

例如：给定的链表是

1→2→3→4→5→null

对于k = 2，你应该返回2→1→4→3→5→null

对于k = 3，你应该返回3→2→1→4→5→null

对于k = 5，你应该返回5→4→3→2→1→null

```c++
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



#### NC61.给出一个整数数组，请在数组中找出两个加起来等于目标值的数。

给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的。

假设给出的数组中只存在唯一解，例如：给出的数组为 {20, 70, 110, 150},目标值为90，输出 index1=1, index2=2。

```c++
#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> v_map;
        vector<int> result;
        for(int i=0;i<numbers.size();i++)
        {
            int diff = target - numbers[i];
            if(v_map.count(diff)==1)
            {
                result.push_back(v_map[diff]);
                result.push_back(i+1);
                return result;
            }
            else
                v_map[numbers[i]]=i+1;
        }
        return result;
    }
};
```

