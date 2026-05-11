"""
LeetCode 24.两两交换链表中的节点
难度：中等
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
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """迭代法：虚拟头结点 + 三指针，每轮交换相邻两个节点"""
        dummy = ListNode(0, head)  # 虚拟头结点，统一处理头结点交换
        prev = dummy               # prev 始终指向待交换对的前驱

        while prev.next and prev.next.next:
            # a 是待交换对的第一个，b 是第二个
            a = prev.next
            b = a.next

            # 三步完成交换（顺序不能乱！）
            prev.next = b       # 1. 前驱指向 b
            a.next = b.next     # 2. a 指向 b 的后继（a 变成后面那个）
            b.next = a          # 3. b 指向 a（b 变成前面那个）

            # prev 前移到已交换部分的末尾（即 a 的位置）
            prev = a

        return dummy.next

    def swapPairs_recursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """递归法：交换前两个 + 递归处理剩余"""
        # 终止条件：不足两个节点，无需交换
        if not head or not head.next:
            return head

        # 交换 head 和 head.next
        new_head = head.next       # head.next 变成新的头
        head.next = self.swapPairs_recursive(new_head.next)  # head 接上递归结果
        new_head.next = head       # 新头指向原来的 head

        return new_head


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

    # 示例 1：偶数个节点
    r1 = s.swapPairs(build_list([1, 2, 3, 4]))
    assert r1.to_list() == [2, 1, 4, 3]

    # 示例 2：空链表
    r2 = s.swapPairs(build_list([]))
    assert r2 is None

    # 示例 3：奇数个节点（最后一个不交换）
    r3 = s.swapPairs(build_list([1]))
    assert r3.to_list() == [1]

    # 边界：3 个节点
    r4 = s.swapPairs(build_list([1, 2, 3]))
    assert r4.to_list() == [2, 1, 3]

    # 边界：2 个节点
    r5 = s.swapPairs(build_list([1, 2]))
    assert r5.to_list() == [2, 1]

    # 递归法同样验证
    r6 = s.swapPairs_recursive(build_list([1, 2, 3, 4]))
    assert r6.to_list() == [2, 1, 4, 3]

    r7 = s.swapPairs_recursive(build_list([1]))
    assert r7.to_list() == [1]

    print("All tests passed!")
