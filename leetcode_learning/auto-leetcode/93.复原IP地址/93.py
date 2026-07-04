"""
93.复原IP地址
难度：中等
链接：https://leetcode.cn/problems/restore-ip-addresses/
"""
from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []

        def backtrack(start: int, path: List[str]):
            # 已切 4 段
            if len(path) == 4:
                if start == n:
                    res.append('.'.join(path))
                return

            # 剪枝：剩余字符数必须够剩余段数（至少 1 个/段，至多 3 个/段）
            remaining = 4 - len(path)
            # start是切分字符串开始的索引，加上remaining分别是1个/段或者3个/段时的最终索引，需要-1
            if start + remaining - 1 > n - 1 or start + remaining * 3 - 1 < n - 1:
                return

            # 尝试切 1~3 位
            for end in range(1, 4):
                if start + end > n:
                    break
                seg = s[start:start + end]
                # 前导零：长度 > 1 且首位为 0，非法
                if len(seg) > 1 and seg[0] == '0':
                    break
                if int(seg) > 255:
                    break
                path.append(seg)
                backtrack(start + end, path)
                path.pop()

        backtrack(0, [])
        return res


if __name__ == "__main__":
    # 回溯实例演示：s = "25525511135"
    # 递归树：
    #   backtrack(0, [])
    #   ├─ 切 "2"  → backtrack(1, ["2"])
    #   │  ├─ 切 "5" → backtrack(2, ["2","5"])
    #   │  │  ├─ 切 "5"   → backtrack(3, ["2","5","5"])
    #   │  │  │  ├─ 切 "2"   → backtrack(4, ["2","5","5","2"])
    #   │  │  │  │  └─ 切 "5511135" 超过3位，剪枝
    #   │  │  │  ├─ 切 "25"  → backtrack(5, ["2","5","5","25"])
    #   │  │  │  │  └─ 切 "511135" 超过3位，剪枝
    #   │  │  │  └─ 切 "255" → backtrack(6, ["2","5","5","255"])
    #   │  │  │     └─ 剩余 "11135" 超过3位，剪枝
    #   │  │  └─ ...（继续尝试其他切法）
    #   │  ├─ 切 "55"  → backtrack(3, ["2","55"])
    #   │  ├─ 切 "552" → backtrack(4, ["2","552"])
    #   │  └─ ...
    #   ├─ 切 "25" → backtrack(2, ["25"])
    #   ├─ 切 "255" → backtrack(3, ["255"])
    #   │  ├─ 切 "2"   → backtrack(4, ["255","2"])
    #   │  │  ├─ 切 "5"  → backtrack(5, ["255","2","5"])
    #   │  │  │  ├─ 切 "5"   → backtrack(6, ["255","2","5","5"])
    #   │  │  │  │  └─ 剩余 "11135" 超过3位，剪枝
    #   │  │  │  ├─ 切 "55"  → backtrack(7, ["255","2","5","55"])
    #   │  │  │  │  └─ 剩余 "1113" 超过3位，剪枝
    #   │  │  │  └─ 切 "551" → backtrack(8, ["255","2","5","551"])
    #   │  │  │     └─ 剩余 "1135" 超过3位，剪枝
    #   │  │  └─ ...（更多尝试，均因剩余字符超长被剪枝）
    #   │  └─ ...
    #   └─ ...
    #
    # 成功路径1: backtrack(0,[]) → "255" → "255" → "111" → "35"  ✓ 255.255.111.35
    # 成功路径2: backtrack(0,[]) → "255" → "255" → "11"  → "135" ✓ 255.255.11.135
    # 大量分支被剪枝提前终止（剩余字符数不足或超过段数容量）

    sol = Solution()
    result = sol.restoreIpAddresses("25525511135")
    assert sorted(result) == sorted(["255.255.11.135", "255.255.111.35"])
    assert sol.restoreIpAddresses("0000") == ["0.0.0.0"]
    assert sorted(sol.restoreIpAddresses("101023")) == sorted(
        ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
    )
    print("ALL OK")