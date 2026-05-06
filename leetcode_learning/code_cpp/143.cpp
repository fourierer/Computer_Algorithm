//联系876题（链表的中间节点）和206题（反转链表）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//解法一：使用一个线性数组保存链表的每一个节点，实现按下标访问
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        vector<ListNode*> v;
        ListNode* p = head;
        while(p!=NULL)
        {
            v.push_back(p);
            p = p->next;
        }
        int i = 0;
        int j = v.size() - 1;
        while(i<j)
        {
            v[i]->next = v[j];
            i++;
            if(i==j)
                break;
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = NULL;
    }
};


//解法二：先找到链表中点，再将右边链表反转，最后合并两个部分
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
