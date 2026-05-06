

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        combine = []
        self.dfs(candidates, target, ans, combine, 0)
        return ans

    
    def dfs(self, candidates, target, ans, combine, idx):
        if idx==len(candidates):
            return
        if target==0:
            # 这里需要保存副本，否则由于列表是可变对象，后续递归会改变列表的值
            # ans.append(combine.copy())
            ans.append(combine[:])
            return
        # 不选当前的数
        self.dfs(candidates, target, ans, combine, idx+1)
        # 选择当前数，需要满足条件
        if target>=candidates[idx]:
            combine.append(candidates[idx])
            self.dfs(candidates, target-candidates[idx], ans, combine, idx)
            combine.pop()

if __name__=='__main__':
    candidates = [2,3,6,7]
    target = 7
    s = Solution()
    ans = s.combinationSum(candidates, target)
    print(ans)
