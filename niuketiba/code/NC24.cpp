class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* fake_head = new ListNode(0);//创建一个指向head的伪节点
        fake_head->next = head;
        ListNode* pre = fake_head;
        ListNode* cur = head;
        while(cur&&cur->next)
        {
            if(cur->val==cur->next->val)
            {
                //cur = cur->next;
                while(cur->next&&cur->val==cur->next->val)//先确保cur->next不为空
                    cur = cur->next;
                //此时cur->val!=cur->next->val，但是要删除所有重复的元素
                cur = cur->next;//把重复的最后一个也删掉
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return fake_head->next;
    }
};