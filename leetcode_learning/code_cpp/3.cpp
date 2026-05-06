#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

//双循环，超时通过900/987
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;//返回的长度
        int size = s.size();
        for(int i=0;i<size;i++)
            for(int j=i;j<size;j++)
            {
                string tmp = s.substr(i,j-i+1);
                if(Isfit(tmp))
                    result = max(result, j-i+1);
            }
        return result;
    }
private:
    bool Isfit(string tmp)
    {
        //判断字符串tmp是否重复
        map<char, int> count;
        for(int i=0;i<tmp.size();i++)
        {
            count[tmp[i]]++;
            if(count[tmp[i]]>1)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        set<char> occ;
        int n = s.size();
        // 右指针，初始值为 0，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = 0, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk < n && !occ.count(s[rk])) {
                // 不断地移动右指针
                occ.insert(s[rk]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串，不包括rk
            ans = max(ans, rk - i);
        }
        return ans;
    }
};
