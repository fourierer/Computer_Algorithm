//使用一个数组来对字符串s中各个字母的个数进行计数
//这里不使用map，因为map不便于从前往后，再从后往前遍历

class Solution {
public:
    string sortString(string s) {
        if(s.length()==0)
            return s;
        vector<int> count(26);//存储对应的字符的个数
        //统计次数
        for(int i=0;i<s.length();i++)
            count[s[i]-'a']++;
        
        string result;
        while(result.length()<s.length())
        {
            for(int i=0;i<26;i++)
                if(count[i])
                {
                    result.push_back(i+'a');//string可以直接通过push_back来得到char
                    count[i]--;
                }

            for(int i=25;i>=0;i--)
                if(count[i])
                {
                    result.push_back(i+'a');
                    count[i]--;
                }
        }
        return result;
    }
};
