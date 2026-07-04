"""
394.字符串解码
难度：中等
链接：https://leetcode.cn/problems/decode-string/
"""


class Solution:
    def decodeString(self, s: str) -> str:
        # 栈处理嵌套：遇 [ 压栈当前状态，遇 ] 弹栈拼接
        #
        # 重复嵌套演示过程（以 s = "3[a2[c]]" 为例，期望输出 "accaccacc"）：
        #   字符  操作                          cur_str      cur_num  stack
        #   3    累积数字                       ''           3        []
        #   [    压栈 ('', 3), 重置             ''           0        [('', 3)]
        #   a    追加字母                       'a'          0        [('', 3)]
        #   2    累积数字                       'a'          2        [('', 3)]
        #   [    压栈 ('a', 2), 重置            ''           0        [('', 3), ('a', 2)]
        #   c    追加字母                       'c'          0        [('', 3), ('a', 2)]
        #   ]    弹栈 ('a', 2), 拼接 a+cc*2     'acc'        0        [('', 3)]
        #   ]    弹栈 ('', 3), 拼接 ''+acc*3   'accaccacc'  0        []
        #
        # 关键：内层 ] 先弹出处理（得到 'acc'=a+cc*2），外层 ] 再弹出处理
        #       （得到 'accaccacc'=''+acc*3），从内到外逐层展开
        stack = []       # 存 (上一层字符串, 重复次数)
        cur_str = ''     # 当前层正在构建的字符串
        cur_num = 0      # 当前正在读取的重复次数

        for c in s:
            if c.isdigit():
                # 数字可能多位，逐位累积
                cur_num = cur_num * 10 + int(c)
            elif c == '[':
                # 进入新嵌套层：压栈当前状态，重置
                stack.append((cur_str, cur_num))
                cur_str = ''
                cur_num = 0
            elif c == ']':
                # 嵌套层结束：弹出上一层，拼接重复后的当前串
                prev_str, num = stack.pop() # 实际上存的是之前的字符串，
                cur_str = prev_str + cur_str * num
            else:
                # 普通字母，追加到当前字符串
                cur_str += c

        return cur_str
