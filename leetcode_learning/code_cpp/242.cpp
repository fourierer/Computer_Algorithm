class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map_s;
        map<char, int> map_t;
        for(int i=0;i<s.length();i++)
            map_s[s[i]]++;
        for(int i=0;i<t.length();i++)
            map_t[t[i]]++;
        
        if(map_s.size()!=map_t.size())
            return false;
        for(map<char, int>::iterator it = map_s.begin();it!=map_s.end();it++)
            if(map_t.count(it->first)&&map_t[it->first]==it->second)
                continue;
            else
                return false;
        return true;
    }
};