class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sum = 0
        temp = 0
        # 必须要分开正负讨论，因为余数一定为正，比如-123%10=7，-123//10=-13
        if x>0:
            while(x!=0):
                temp = x % 10
                sum = sum*10 + temp
                x = x // 10
            if (sum > 2**31-1) or (sum < -2**31):
                return 0
            return sum
        elif x<0:
            y = x*(-1)
            while(y!=0):
                temp = y % 10
                sum = sum*10 + temp
                y = y // 10
            sum_minus = sum*(-1)
            if (sum_minus > 2**31-1) or (sum_minus < -2**31):
                return 0
            return sum_minus
        else:
            return 0

    # 未验证，仅提供思路
    def reverse_simple(self, x):
        """
        :type x: int
        :rtype: int
        """
        sum = 0
        if x >= 0:
            while x != 0:
                sum = sum * 10 + x % 10
                x = x // 10
            return  sum if sum <= 2**31 - 1 else 0
        else:
            while x != 0:
                sum = sum * 10 + x % 10
                x = x // 10
            return  -sum if -sum >= -2**31 else 0

    # 未验证，仅提供思路
    def reverse_simple(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 0:
            x = int(str(x)[::-1])
        else:
            x = -int(str(-x)[::-1])
    
        return x if x >= -2**31 and x <= 2**31 - 1 else 0


x = 1001
s = Solution()
print(s.reverse(x))
