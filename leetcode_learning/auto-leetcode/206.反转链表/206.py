"""
206.反转链表
难度：简单
链接：https://leetcode.cn/problems/reverse-linked-list/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head):
        # 解法一：迭代
        if not head or not head.next:
            return head
        pre = None
        cur = head
        while cur:
            temp_next = cur.next
            # 翻转指针，cur.next 指向前驱而非后继
            cur.next = pre
            pre = cur
            cur = temp_next
        return pre

    def reverseList_recursive(self, head):
        # 解法二：递归
        if not head or not head.next:
            return head
        # 递归反转后续链表，new_head 始终是反转后的头节点
        new_head = self.reverseList_recursive(head.next)
        # 回溯时翻转指针：后继节点指回当前节点
        head.next.next = head
        head.next = None
        return new_head


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
    assert linked_to_list(sol.reverseList(head)) == [5, 4, 3, 2, 1]

    head = list_to_linked([1, 2])
    assert linked_to_list(sol.reverseList(head)) == [2, 1]

    assert sol.reverseList(None) is None

    head = list_to_linked([1, 2, 3])
    assert linked_to_list(sol.reverseList_recursive(head)) == [3, 2, 1]