class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sum = 0
        temp = 0
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


x = 1001
s = Solution()
print(s.reverse(x))
