class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # return self.judge_string(x)
        return self.judge_int(x)
    
    # 判断字符串首尾是否相同
    def judge_string(self, x):
        if x<0:
            return False
        str_x = str(x)
        i = 0
        j = len(str_x) - 1
        while(i<j):
            if (str_x[i] != str_x[j]):
                return False
            i += 1
            j -=1
        return True

    # 判断整数反转后是否和原数相同
    def judge_int(self, x):
        if x<0:
            return False
        flip_x = 0
        mod = 0
        store_x = x
        while(x!=0):
            mod = x%10
            flip_x = flip_x*10 + mod
            x //= 10
        return flip_x==store_x

if __name__=='__main__':
    s = Solution()
    x = 1001
    print(s.isPalindrome(x))

