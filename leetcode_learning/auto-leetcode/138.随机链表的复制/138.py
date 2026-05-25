"""
138.随机链表的复制
难度：中等
链接：https://leetcode.cn/problems/copy-list-with-random-pointer/

为什么不能用 copy.deepcopy()？
- 链表节点的 random 指针指向链表内部节点，deepcopy 会把指向的对象也完整复制
- 但如果多个节点的 random 指向同一个节点，deepcopy 会创建多个副本而非共享同一引用
- 例如 A.random 和 B.random 都指向 C，deepcopy 后 A'.random→C₁, B'.random→C₂
- 但 C₁ 和 C₂ 是两个不同对象，不符合深拷贝要求（应指向同一个新节点 C'）
- 所以必须手动维护 原节点→新节点 的映射，确保 random 指向正确的新节点
"""


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        # 解法一：哈希表映射
        old_to_new = {}
        curr = head

        # 第一遍：创建所有新节点，建立映射
        while curr:
            old_to_new[curr] = Node(curr.val)
            curr = curr.next

        # 第二遍：根据映射设置 next 和 random
        curr = head
        while curr:
            old_to_new[curr].next = old_to_new.get(curr.next)
            old_to_new[curr].random = old_to_new.get(curr.random)
            curr = curr.next

        return old_to_new.get(head)

    def copyRandomList_inplace(self, head: 'Node') -> 'Node':
        # 解法二：原地修改，O(1)空间
        if not head:
            return None

        # 第一步：在每个原节点后插入新节点
        # A -> A' -> B -> B' -> C -> C'
        curr = head
        while curr:
            new_node = Node(curr.val)
            new_node.next = curr.next
            curr.next = new_node
            curr = new_node.next

        # 第二步：设置新节点的 random 指针
        # 新节点的 random = 原节点 random 的 next
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # 第三步：拆分链表，恢复原链表并分离新链表
        dummy = Node(0)
        new_curr = dummy
        curr = head
        while curr:
            new_curr.next = curr.next
            curr.next = curr.next.next
            new_curr = new_curr.next
            curr = curr.next

        return dummy.next