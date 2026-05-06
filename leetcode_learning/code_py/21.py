class ListNode():
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        fake_head = ListNode(0, None)
        cur = fake_head # 利用cur来对fake_head进行操作,由于类是可变对象，所以相当于对fake_head进行操作
        while(list1 and list2):
            if list1.val < list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next # 当前节点的下一个节点插完，就把cur移到下一个节点，和fake_head一样的原理

        if list1:
            cur.next = list1
        else:
            cur.next = list2
        
        return fake_head.next

        



if __name__=='__main__':
    # 参数测试，x赋值，x是指向对象的引用，可以视为特殊的“指针”，当执行y=x，y是指向相同对象的引用
    # 如果指向的对象是列表、字典、类等等可变对象，那么修改y会直接修改引用对象的值，x也会发生变化
    # 如果指向的对象是数字、字符串、元组等不可变对象，那么修改y会创建一个新的对象，不影响x指向的对象
    x = ListNode(0, None)
    y = x
    z = ListNode(1, None)
    y.next = z
    print(y.next) # <__main__.ListNode object at 0x000001D25AD51C70>
    print(x.next) # <__main__.ListNode object at 0x000001D25AD51C70>

    x = {}
    y = x
    y['A'] = 1
    print(y) # {'A': 1}
    print(x) # {'A': 1}

    x = 1
    y = x
    y = 3
    print(y) # 3
    print(x) # 1






