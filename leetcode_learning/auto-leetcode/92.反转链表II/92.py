"""
92.反转链表II
难度：中等
链接：https://leetcode.cn/problems/reverse-linked-list-ii/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        # 设置 dummyNode 是这一类问题的一般做法，避免 left=1 时的边界处理
        dummy_node = ListNode(-1)
        dummy_node.next = head
        pre = dummy_node
        # pre 移动到反转区间的前一个节点
        for _ in range(left - 1):
            pre = pre.next

        cur = pre.next
        # 头插法：每次将 cur.next 插到 pre 后面
        for _ in range(right - left):
            next = cur.next
            # cur 跳过 next，next 插到 pre 后面
            cur.next = next.next
            next.next = pre.next
            pre.next = next
        return dummy_node.next


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
    assert linked_to_list(sol.reverseBetween(head, 2, 4)) == [1, 4, 3, 2, 5]

    head = list_to_linked([5])
    assert linked_to_list(sol.reverseBetween(head, 1, 1)) == [5]

    head = list_to_linked([1, 2, 3, 4, 5])
    assert linked_to_list(sol.reverseBetween(head, 1, 5)) == [5, 4, 3, 2, 1]