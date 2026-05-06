class ListNode():
    def __init__(self, val=0, next=0):
        self.val = val
        self.next = next

class Solution(object):
    # # 遍历
    # def reverseList(self, head):
    #     """
    #     :type head: Optional[ListNode]
    #     :rtype: Optional[ListNode]
    #     """
    #     if not head or not head.next:
    #         return head
    #     pre = None
    #     cur = head
    #     while cur:
    #         temp_next = cur.next
    #         cur.next = pre
    #         pre = cur
    #         cur = temp_next
    #     return pre
    
    # 堆栈存储
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        result = []
        cur = head
        while cur:
            result.append(cur.val)
            cur = cur.next
        
        # print(result)
        # 构建链表
        fake_head = ListNode(0, None)
        cur = fake_head
        while result:
            cur.next = ListNode(result[-1], None)
            result.pop()
            cur = cur.next
        return fake_head.next


            

if __name__ == '__main__':
    s = Solution()

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    new_head = s.reverseList(head)
    print(new_head.val)
    print(new_head.next.val)
    print(new_head.next.next.val)
    print(new_head.next.next.next.val)
        

