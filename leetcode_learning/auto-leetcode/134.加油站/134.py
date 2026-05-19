"""
134.加油站
难度：中等
链接：https://leetcode.cn/problems/gas-station/
"""
from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # 总油量不够，一定无解
        if sum(gas) < sum(cost):
            return -1

        start = 0  # 起始加油站
        tank = 0    # 当前剩余油量

        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            # 油量不足，i 以及之前的站点都不可能作为起点
            if tank < 0:
                start = i + 1
                tank = 0

        return start


# ====== 错误思路（反例警示）======
# 错误想法：总和>=0时，从净收益最大的站出发即可
# 反例：gas = [5,8,2,8], cost = [6,5,6,6]
#   净收益 = [-1, 3, -4, 2]，总和=0>=0
#   max(净收益)=3 在 index=1，但从 index=1 出发：tank=3 -> 3-4=-1 失败
#   正确答案是 index=3：tank=2 -> 2-1=1 -> 1+3=4 -> 4-4=0 成功
class Solution_Wrong:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        for i in range(len(gas)):
            gas[i] -= cost[i]
        if sum(gas) >= 0:
            return gas.index(max(gas))
        else:
            return -1