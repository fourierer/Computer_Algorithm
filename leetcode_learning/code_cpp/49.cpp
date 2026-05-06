#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string str_tmp = strs[i];
            sort(str_tmp.begin(), str_tmp.end());
            m[str_tmp].push_back(strs[i]);
        }
        
        //输出map中的分组结果
        vector<vector<string>> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second);
        }
        return v;
    }
};
