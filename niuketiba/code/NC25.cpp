class Solution {
public:
    /**
     * 
     * @param head ListNodeš▒╗ 
     * @return ListNodeš▒╗
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==nullptr) return head;
        ListNode* q = head;
        while(q->next){
            if(q->next->val==q->val) q->next=q->next->next;
            else q=q->next;
        }
        return head;
    }
};