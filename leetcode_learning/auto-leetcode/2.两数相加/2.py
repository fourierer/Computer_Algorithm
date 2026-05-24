"""
2.两数相加
难度：中等
链接：https://leetcode.cn/problems/add-two-numbers/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        carry = 0

        # 只要还有节点或进位就继续循环
        while l1 or l2 or carry:
            # 取当前位的值，链表已遍历完则为0
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry
            carry = total // 10
            curr.next = ListNode(total % 10)
            curr = curr.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next


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
    l1 = list_to_linked([2, 4, 3])
    l2 = list_to_linked([5, 6, 4])
    assert linked_to_list(sol.addTwoNumbers(l1, l2)) == [7, 0, 8]

    l1 = list_to_linked([0])
    l2 = list_to_linked([0])
    assert linked_to_list(sol.addTwoNumbers(l1, l2)) == [0]

    l1 = list_to_linked([9, 9, 9, 9, 9, 9, 9])
    l2 = list_to_linked([9, 9, 9, 9])
    assert linked_to_list(sol.addTwoNumbers(l1, l2)) == [8, 9, 9, 9, 0, 0, 0, 1]