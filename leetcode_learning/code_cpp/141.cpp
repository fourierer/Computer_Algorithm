/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//使用map记录各个节点出现的次数，如果有一个节点出现两次，则有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> node_count;
        while(head!=NULL)
        {
            node_count[head]++;
            if(node_count[head]==2)
                return true;
            head = head->next;
        }
        return false;
    }
};

//快慢指针
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}




