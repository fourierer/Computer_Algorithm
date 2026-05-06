

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word1), len(word2)
        # 初始化DP表
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        # 边界条件
        for i in range(m+1):
            dp[i][0] = i
        for j in range(n+1):
            dp[0][j] = j
        # 状态转移
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    replace = dp[i-1][j-1] + 1
                    insert = dp[i][j-1] + 1
                    delete = dp[i-1][j] + 1
                    dp[i][j] = min(replace, insert, delete)
        return dp[m][n]


# s = Solution()
# # word1 = "horse"
# # word2 = "ros"
# word1 = "intention"
# word2 = "execution"
# print(s.minDistance(word1, word2))
