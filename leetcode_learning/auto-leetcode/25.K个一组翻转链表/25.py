"""
25.K个一组翻转链表
难度：困难
链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # 翻转一个子链表，并且返回新的头与尾
    def reverse(self, head: ListNode, tail: ListNode):
        # prev 初始为 tail.next，这样翻转后 head（变为尾）自然指向 tail.next
        prev = tail.next
        p = head
        while prev != tail:
            nex = p.next
            p.next = prev
            prev = p
            p = nex
        return tail, head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        hair = ListNode(0)
        hair.next = head
        pre = hair

        while head:
            tail = pre
            # 查看剩余部分长度是否大于等于 k
            for i in range(k):
                tail = tail.next
                if not tail:
                    # 剩余不足 k 个，保持原序，直接返回
                    return hair.next
            nex = tail.next
            # 翻转 [head, tail]，返回新的头和尾
            head, tail = self.reverse(head, tail)
            # 把子链表重新接回原链表
            pre.next = head
            tail.next = nex
            # 移动到下一组
            pre = tail
            head = tail.next

        return hair.next


def list_to_linked(lst):
    dummy = ListNode(0)
    curr = dummy
    for val in lst:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next


def linked_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result


if __name__ == "__main__":
    sol = Solution()
    head = list_to_linked([1, 2, 3, 4, 5])
    assert linked_to_list(sol.reverseKGroup(head, 2)) == [2, 1, 4, 3, 5]

    head = list_to_linked([1, 2, 3, 4, 5])
    assert linked_to_list(sol.reverseKGroup(head, 3)) == [3, 2, 1, 4, 5]

    head = list_to_linked([1, 2, 3, 4, 5])
    assert linked_to_list(sol.reverseKGroup(head, 1)) == [1, 2, 3, 4, 5]

    head = list_to_linked([1])
    assert linked_to_list(sol.reverseKGroup(head, 1)) == [1]