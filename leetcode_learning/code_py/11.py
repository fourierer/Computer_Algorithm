class Solution():
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            max_area = max(max_area, (right - left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area
    
    def maxArea_simple(self, height):
        n = len(height)
        max_area = 0
        for i in range(n):
            for j in range(i+1, n):
                max_area = max(max_area, (j - i) * min(height[i], height[j]))
        return max_area


if __name__ == '__main__':
    print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))
    print(Solution().maxArea([1,1]))

