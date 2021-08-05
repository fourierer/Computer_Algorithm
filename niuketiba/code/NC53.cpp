class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;//创建一个虚假的头结点，防止头结点被删除
        ListNode* pre = fake_head;
        ListNode* p = head;
        //让p先走n-1步
        while(n=n-1)
            p = p->next;
        //然后pre和p一起走
        while(p->next!=NULL)
        {
            p = p->next;
            pre = pre->next;
        }
        //此时p到达链表末尾，pre到达要删除节点的前一个
        ListNode* del_next = pre->next->next;//记录要删除节点的下一个的位置
        pre->next = del_next;//删除该节点
        return fake_head->next;
    }
};