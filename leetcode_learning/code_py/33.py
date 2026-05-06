

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left<right:
            mid = (left + right) // 2
            # 左边有序
            if nums[left]<=nums[mid]:
                if nums[left]<=target and target<=nums[mid]:
                    right = mid
                else:
                    left = mid+1
            # 右边有序
            else:
                if nums[mid+1]<=target and target<=nums[right]:
                    left = mid+1
                else:
                    right = mid
        
        if nums[left]==target:
            return left
        else:
            return -1

if __name__=='__main__':
    nums = [4,5,6,7,0,1,2]
    target = 0
    s = Solution()
    print(s.search(nums, target))
        