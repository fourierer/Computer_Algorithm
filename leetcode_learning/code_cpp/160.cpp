#include<iostream>
#include<map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

//哈希表存储节点，判断节点出现次数
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return nullptr;
        map<ListNode*, int> node;
        ListNode* curA = headA;
        while(curA)
        {
            node[curA]++;
            curA = curA->next;
        }
        
        ListNode* curB = headB;
        while(curB)
        {
            if(node.count(curB))
                return curB;
            else
                node[curB]++;
            curB = curB->next;
        }
        return nullptr;
    }
};

//双指针
//每步操作需要同时更新指针curA和curB；
//如果指针curA不为空，则将指针curA移到下一个节点；如果指针curB不为空，则将指针curB移到下一个节点。
//如果指针curA为空，则将指针curA移到链表headB的头节点；如果指针curB为空，则将指针curB移到链表headA的头节点。
//当指针curA和curB指向同一个节点或者都为空时，返回它们指向的节点或者null。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return nullptr;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA!=curB)
        {
            curA = (curA==nullptr?headB:curA->next);
            curB = (curB==nullptr?headA:curB->next);
        }
        return curA;
    }
};
