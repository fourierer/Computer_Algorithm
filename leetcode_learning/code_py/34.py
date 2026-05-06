class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        first = -1
        last = -1
        left = 0
        right = len(nums) - 1

        # 寻找第一个
        while(left<=right):
            mid = (left + right) // 2
            if nums[mid]==target:
                first = mid
                right = mid - 1 # 继续向前找
            elif nums[mid]>target:
                right = mid - 1
            else:
                left = mid + 1
        
        left = 0
        right = len(nums) - 1
        # 寻找最后一个
        while(left<=right):
            mid = (left + right) // 2
            if nums[mid]==target:
                last = mid
                left = mid + 1 # 继续向后找
            elif nums[mid]>target:
                right = mid - 1
            else:
                left = mid + 1
        
        return [first, last]
