# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if k == 0 or not head or not head.next:
            return head

        n = 1
        cur = head
        while cur.next:
            cur = cur.next
            n += 1

        add = n - k % n
        if add == n:
            return head

        # 闭合为环
        cur.next = head
        # 从当前位置往前移动add步，找到新尾节点
        while add:
            cur = cur.next
            add -= 1

        ret = cur.next
        cur.next = None
        return ret
