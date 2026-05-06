
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)%2==1:
            return False
        
        match_dict = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        stack = [] # python的列表为堆栈
        for per_char in s:
            if per_char in match_dict:
                # 需要判断该左括号是否可以闭合
                if len(stack)==0 or stack[-1]!=match_dict[per_char]:
                    # 如果此时堆栈为空，或者堆栈顶不能闭合该左括号
                    return False
                else:
                    # 如果可以闭合，则把栈顶删除
                    stack.pop()
            else:
                # 遇到新的右括号要添加进堆栈
                stack.append(per_char)
        
        # 如果最后栈为空，则返回True
        if len(stack)==0:
            return True
        else:
            return False


if __name__=='__main__':
    s = Solution()
    test_s = '()[]{}'
    print(s.isValid(test_s))
