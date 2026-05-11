"""
LeetCode 21.合并两个有序链表
难度：简单
标签：递归、链表
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

    def to_list(self) -> list[int]:
        """链表转列表，方便测试"""
        result = []
        node = self
        while node:
            result.append(node.val)
            node = node.next
        return result


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """迭代法：虚拟头结点 + 尾指针，每次取较小的接上去"""
        dummy = ListNode()  # 虚拟头结点，统一处理空链表
        tail = dummy        # tail 始终指向结果链表的末尾

        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1   # 接上 list1 的头
                list1 = list1.next  # list1 前进一步
            else:
                tail.next = list2   # 接上 list2 的头
                list2 = list2.next  # list2 前进一步
            tail = tail.next        # tail 跟进

        # 剩余部分直接拼上（已经有序，无需再逐个比较）
        tail.next = list1 or list2

        return dummy.next

    def mergeTwoLists_recursive(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """递归法：取较小头节点 + 递归合并剩余部分"""
        # 递归终止：其中一个为空，直接返回另一个
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val <= list2.val:
            # list1 头更小 → list1.next = 合并(list1.next, list2)
            list1.next = self.mergeTwoLists_recursive(list1.next, list2)
            return list1
        else:
            # list2 头更小 → list2.next = 合并(list1, list2.next)
            list2.next = self.mergeTwoLists_recursive(list1, list2.next)
            return list2


def build_list(vals: list[int]) -> Optional[ListNode]:
    """从列表构建链表"""
    if not vals:
        return None
    head = ListNode(vals[0])
    cur = head
    for v in vals[1:]:
        cur.next = ListNode(v)
        cur = cur.next
    return head


if __name__ == "__main__":
    s = Solution()

    # 示例 1
    r1 = s.mergeTwoLists(build_list([1, 2, 4]), build_list([1, 3, 4]))
    assert r1.to_list() == [1, 1, 2, 3, 4, 4]

    # 示例 2：两个空链表
    r2 = s.mergeTwoLists(build_list([]), build_list([]))
    assert r2 is None

    # 示例 3：一个空链表
    r3 = s.mergeTwoLists(build_list([]), build_list([0]))
    assert r3.to_list() == [0]

    # 边界：长度不等
    r4 = s.mergeTwoLists(build_list([1, 5]), build_list([2, 3, 4, 6]))
    assert r4.to_list() == [1, 2, 3, 4, 5, 6]

    # 递归法同样验证
    r5 = s.mergeTwoLists_recursive(build_list([1, 2, 4]), build_list([1, 3, 4]))
    assert r5.to_list() == [1, 1, 2, 3, 4, 4]

    r6 = s.mergeTwoLists_recursive(build_list([]), build_list([0]))
    assert r6.to_list() == [0]

    print("All tests passed!")



