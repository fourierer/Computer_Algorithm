#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size==0)
            return "";
        if(size==1)
            return strs[0];
        string str = strs[0];
        for(int i=1;i<size;i++)
            str = longestCommonPrefix_for_two(str, strs[i]);
        return str;
    }
private:
    string longestCommonPrefix_for_two(string str1, string str2)
    {
        int size1 = str1.size();
        int size2 = str2.size();
        int size = size1<size2?size1:size2;
        for(int i=0;i<size;i++)
        {
            if(str1[i]!=str2[i])
                return str1.substr(0, i);
        }
        return size1<size2?str1:str2;
    }
};