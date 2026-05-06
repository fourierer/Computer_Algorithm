
class ListNode():
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    # 递归方法
    # def swapPairs(self, head):
    #     """
    #     :type head: Optional[ListNode]
    #     :rtype: Optional[ListNode]
    #     """
    #     if (head is None) or (head.next is None):
    #         return head
    #     new_head = head.next
    #     head.next = self.swapPairs(new_head.next)
    #     new_head.next = head
    #     return new_head

    # 遍历
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if (head is None) or (head.next is None):
            return head
        fake_head = ListNode(0, head)
        cur = fake_head
        while(cur.next and cur.next.next):
            node1 = cur.next
            node2 = cur.next.next
            cur.next = node2
            node1.next = node2.next
            node2.next = node1
            cur = node1
        return fake_head.next


        



if __name__=='__main__':
    s = Solution()

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    new_head = s.swapPairs(head)
    print(new_head.val)
    print(new_head.next.val)
    print(new_head.next.next.val)
    print(new_head.next.next.next.val)

    
        