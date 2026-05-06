/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//解法一、使用一个数组存储链表节点，排好序之后再重构链表
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
        vector<ListNode*> v;
        //数组存储链表节点
        while(head)
        {
            v.push_back(head);
            head = head->next;
        }
        //按照节点值排序节点
        sort(v.begin(), v.end(), [&](ListNode* x, ListNode* y){
            return x->val<y->val;
        });
        //重构链表
        for(int i=0;i<v.size()-1;i++)
            v[i]->next = v[i+1];
        v[v.size()-1]->next = NULL;

        return v[0];
    }
};


//解法二、按照题意对链表进行插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* pre_cur = head;//当前节点遍历到的位置
        ListNode* cur = pre_cur->next;
        while(cur)
        {
            //如果当前节点小于其下一个节点的值，则往后遍历
            if(pre_cur->val<=cur->val)
            {
                pre_cur = cur;
                cur = cur->next;
            }
            //如果当前节点比其下一个节点大，则需要插入排序
            else
            {
                //先断开当前节点和其下一个节点的连接
                pre_cur->next = cur->next;
                //开始从头遍历到cur，将节点p插入到已经排好序的链表中
                //如果下一个节点小于头结点，则将其作为头节点
                if(cur->val<=head->val)
                {
                    cur->next = head;
                    head = cur;
                    cur = pre_cur->next;
                }
                //如果下一个节点大于头节点，则需要遍历插入
                else
                {
                    //遍历的指针设为pre和start
                    ListNode* start = head;
                    ListNode* pre = new ListNode(0);
                    //在head和pre_cur之间遍历
                    while(start!=cur)
                    {
                        if(cur->val<=start->val)
                        {
                            cur->next = start;
                            pre->next = cur;
                            cur = pre_cur->next;
                            break;//插入完毕，结束while循环
                        }
                        else
                        {
                            pre = start;
                            start = start->next;
                        }
                    }
                }
            }
        }
        return head;
    }
};



