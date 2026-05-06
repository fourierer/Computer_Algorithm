# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode():
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        if head is None:
            return None
        # 定义虚假的头节点指向真正的头节点
        fake_head = ListNode(0, head)
        
        # 定义两个遍历节点
        pre = ListNode(0, fake_head)
        p = ListNode(0, head)

        # 让p节点先走n-1步
        n -= 1
        while n>0:
            n -= 1
            p = p.next
            # 如果p为空，说明链表长度比n小（如果长度为n，则p走n-1步刚好走到最后一个节点）
            if p is None:
                return None
        
        # 再让pre和p一起走，当p走到最后一个节点时，pre指向要删除节点的前一个
        while p.next:
            pre = pre.next
            p = p.next
        # 删除pre指向的节点
        del_node_next = pre.next.next
        pre.next = del_node_next
        return fake_head.next
            

        