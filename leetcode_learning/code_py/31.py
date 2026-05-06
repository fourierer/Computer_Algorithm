
# 1.首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
# 2.如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 jj 满足 a[i] < a[j]。这样「较大数」即为 a[j]。
# 3.交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        index_min = -1
        index_max = -1
        # for i in reversed(range(length)): # length到0
        # 在length-1到0中找较小数
        for i in range(length-2, -1, -1):
            if nums[i]<nums[i+1]:
                index_min = i
                break
        # print(index_min)
        if index_min>=0:
            # 找到了较小数，在length-1到index_min+1中找较大数
            for j in range(length-1, index_min, -1):
                if nums[j]>nums[index_min]:
                    index_max = j
                    break
            # print(index_max)
            # 调换较小数和较大数
            tmp = nums[index_max]
            nums[index_max] = nums[index_min]
            nums[index_min] = tmp
            # 反转index_min+1到length-1中的所有数
            list_tmp = nums[index_min+1:length] # 切片的end_max不包括，所以是length，不能是lenth-1
            list_tmp.reverse()
            nums[index_min+1:length] = list_tmp
        else:
            # 没有找到较小数，说明当前数组降序排列，已经是最大数了，直接反转输出即可
            nums.reverse()



if __name__ == '__main__':
    nums = [1, 4, 6, 6, 3, 1, 0]
    s = Solution()
    s.nextPermutation(nums)
    print(nums)
