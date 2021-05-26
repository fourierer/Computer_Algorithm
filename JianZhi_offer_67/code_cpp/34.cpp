#include<iostream>
#include<string>
#include<map>
#include<iterator>

using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.length();
        map<char, int> str_count;//存储各个字符出现的次数
        for(int i=0;i<len;i++)
            str_count[str[i]]++;

        for(int i=0;i<len;i++)
            if(str_count[str[i]]==1)
                return i;
        return -1;
    }
};


int main()
{
    //map<char, int> str_count;
    string str = "ababdeec";
    Solution s;
    int n = s.FirstNotRepeatingChar(str);
    /*
    for(map<char, int>::iterator it=str_count.begin();it!=str_count.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    */
    cout<<n;
    return 0;
}


