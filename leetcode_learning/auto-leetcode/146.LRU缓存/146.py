"""
146.LRU缓存
难度：中等
链接：https://leetcode.cn/problems/lru-cache/
"""


class DLinkedNode:
    """双向链表节点"""
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}  # key -> DLinkedNode
        self.size = 0
        self.capacity = capacity
        # 哑节点，简化边界操作
        self.head = DLinkedNode()
        self.tail = DLinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        # 命中后移到链表头部，标记为最近使用
        node = self.cache[key]
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # key 已存在：更新值，移到头部
            node = self.cache[key]
            node.value = value
            self._move_to_head(node)
        else:
            # key 不存在：新建节点，插入头部
            node = DLinkedNode(key, value)
            self.cache[key] = node
            self._add_to_head(node)
            self.size += 1
            # 超容量时淘汰尾部节点（最久未使用）
            if self.size > self.capacity:
                removed = self._pop_tail()
                del self.cache[removed.key]
                self.size -= 1

    def _add_to_head(self, node: DLinkedNode) -> None:
        """将节点插入到哑头节点之后"""
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _remove_node(self, node: DLinkedNode) -> None:
        """从链表中摘除节点"""
        node.prev.next = node.next
        node.next.prev = node.prev

    def _move_to_head(self, node: DLinkedNode) -> None:
        """摘除后重新插入头部"""
        self._remove_node(node)
        self._add_to_head(node)

    def _pop_tail(self) -> DLinkedNode:
        """摘除尾部节点（哑尾节点的前一个，即最久未使用的节点）"""
        removed = self.tail.prev
        self._remove_node(removed)
        return removed
