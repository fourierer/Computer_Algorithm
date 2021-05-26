class Solution {
public:
    string reorganizeString(string S) {
        if(S.length()<3)
            return S;
        //记录S中字符出现的次数，初始化一个vector，长度为26，每个位置上都为0
        vector<int> count_S(26);
        //S中字符出现的最大次数
        int max_count = 0;
        for(int i=0;i<S.length();i++)
        {
            count_S[S[i]-'a']++;
            if(count_S[S[i]-'a']>max_count)
                max_count = count_S[S[i]-'a'];
        }
        //如果出现最大次数的字母次数超过(n+1)/2，则无法使得相邻的字符不同
        if(max_count>(S.length()+1)/2)
            return "";
        
        //初始化一个string，长度为S.length()，每个位置上都是空字符
        string result(S.length(), ' ');
        //维护偶数索引和奇数索引用来放置字母
        int evenindex = 0;
        int oddindex = 1;
        for(int i=0;i<26;i++)
        {
            char c = i + 'a';
            //出现次数小于等于S.length()/2的字符要先放在奇数索引上
            while(count_S[i]>0&&count_S[i]<=S.length()/2&&oddindex<S.length())
            {
                result[oddindex] = c;
                count_S[i]--;
                oddindex += 2;
            }
            while(count_S[i]>0&&evenindex<S.length())
            {
                result[evenindex] = c;
                count_S[i]--;
                evenindex += 2;
            }
        }
        return result;
    }
};
