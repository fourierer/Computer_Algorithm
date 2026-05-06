class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        result_str = ''
        n = len(s)
        # dp[i][j]表示字符串索引从i到j是否为回文字串
        dp = [[0]*n for _ in range(n)]
        # print(dp)
        # 注意：不能按照常规双循环遍历i,j，因为递推公式中会涉及i+1，此时dp[i+1][j-1]还没有赋值
        # 必须将间隔k作为第一个循环
        for k in range(n):
            for i in range(n-k):
                j = i+k
                if k==0:
                    dp[i][j] = 1
                elif k==1:
                    dp[i][j]=(s[i]==s[j])
                else:
                    # 间隔大于1，需要进行递推
                    dp[i][j] = ((s[i]==s[j]) and (dp[i+1][j-1]))
                if dp[i][j] and ((k+1)>len(result_str)):
                    result_str = s[i:j+1]
        return result_str

                    


if __name__=='__main__':
    solution = Solution()
    # s = 'babad'
    s = 'cbbd'

    print(solution.longestPalindrome(s))


