#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int size = strs.size();
        if(size==0)
            return "";
        if(size==1)
            return strs[0];
        string result = strs[0];
        for(int i=1;i<size;i++)
        {
            result = match(result, strs[i]);
        }
        return result;
    }
private:
    string match(string s1, string s2)
    {
        int size = min(s1.size(), s2.size());
        int length;
        for(length = size;length>=0;length--)
        {
            if(s1.substr(0,length)==s2.substr(0,length))
                return s1.substr(0,length);
        }
        return "";
    }
};