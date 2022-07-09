#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int start = 0;
        int end = s.size() - 1;
        while(start<end)
        {
            while(start<n&&!IsVower(s[start]))
                start++;
            while(end>=0&&!IsVower(s[end]))
                end--;
            if(start<end)
            {
                swap(s[start], s[end]); //交换之后，当前start和end处都是元音，所以需要start++，end--
                start++;
                end--;
            }
        }
        return s;
    }
private:
    bool IsVower(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
};

