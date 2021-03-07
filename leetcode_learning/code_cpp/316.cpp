
class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> count_s;
        int count = 0;
        int k = 0;
        //记录每个字符出现的次数
        for(int i=0;i<s.length();i++)
            count_s[s[i]]++;
        for(map<char, int>::iterator it=count_s.begin();it!=count_s.end();it++)
            //cout<<it->first<<":"<<it->second<<endl;
            count += it->second - 1;
        //cout<<count<<endl;
        while(k<count)
        {
            for(int i=0;i<s.length();i++)
            {
                if((s[i]-'0'>s[i+1]-'0')&&(count_s[s[i]]>1))
                {
                    cout<<s[i]<<endl;
                    s.erase(i,1);//删除某个元素之后，i自动加1
                    count_s[s[i]]--;
                    cout<<count_s[s[i]]<<endl;
                    k++;
                    break;
                }
            }
        }
        return s;
    }
};



