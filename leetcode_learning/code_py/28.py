

class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        length_dst = len(haystack)
        length_sor = len(needle)
        for i in range(length_dst):
            if haystack[i:i+length_sor]==needle:
                return i
        return -1


if __name__=='__main__':
    haystack = "sadbutsad"
    needle = "sad"
    s = Solution()
    print(s.strStr(haystack, needle))




