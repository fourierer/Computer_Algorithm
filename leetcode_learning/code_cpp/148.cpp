//第147题的两种方法都可以AC，但是时间或者空间复杂度不满足题意，这里主要介绍官方的两种解法。
//归并排序基于分治算法。最容易想到的实现方式是自顶向下的递归实现，考虑到递归调用的栈空间，自顶向下归并排序的空间复杂度是 O(log n)；
//如果要达到 O(1) 的空间复杂度，则需要使用自底向上的实现方式。

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){};
    ListNode(int x):val(x),next(NULL);
    ListNode(int x, ListNode* next):val(x),next(next);
};


//解法一、自顶向下，采用递归，栈空间为O(log n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        return sortlist(head, tail);
    }

    ListNode* sortlist(ListNode* head, ListNode* tail) {
        if(head==tail)
            return head;
        
        if (head->next == tail)
        {
            if(head->val<=tail->val)
                return head;
            else
            {
                tail->next = head;
                head->next = NULL;
                return tail;
            }
        }

        /*
        //找链表中间节点
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        */
        
        //找链表中间节点，不需要使用尾节点
        ListNode* slow = head, *fast = head;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        

        ListNode* mid = slow;
        ListNode* mid_next = mid->next;
        mid->next = NULL;//断开两个子链表
        return merge(sortlist(head, mid), sortlist(mid_next, tail));
    }
    
    //leetcode 21题代码
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//最终返回的头节点前面一个节点
        ListNode* cur = head;//当前插入节点的位置
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
            cur = cur->next;//当前节点位置插完，cur转到下一个节点位置
        }
        //判断此时哪个子链表还没有遍历完，将cur指向未遍历完的那一个链表
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return head->next;
    }
};


//解法二、自底向上
//不会......
