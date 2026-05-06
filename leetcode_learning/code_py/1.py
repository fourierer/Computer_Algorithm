

# class Solution(object):
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         result = []
#         for i in range(len(nums)):
#             for j in range(i+1, len(nums)):
#                 if (nums[i]+nums[j])==target:
#                     result.append(i)
#                     result.append(j)
#         return result

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        result_maps = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in result_maps:
                result.append(result_maps[diff])
                result.append(i)
                return result
            result_maps[nums[i]] = i
        
        return result




if __name__=='__main__':
    s = Solution()

    nums = [3,2,4]
    target = 6
    print(s.twoSum(nums, target))

