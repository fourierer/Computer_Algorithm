#incldue<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int L = 10;
        if(s.size()<L)
            return result;
        map<string, int> str_count;
        for(int i=0;i<=s.size()-L;i++)
        {
            string sub = s.substr(i, L);
            str_count[sub]++;
            //只考虑出现两次的字串，防止重复计数
            if(str_count[sub]==2)
                result.push_back(sub);
        }
        return result;
    }
};
