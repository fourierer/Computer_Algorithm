#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        string s = str;
        int length = s.size();
        int sum = 0;
        for(int i = length-1;i>=0;i--)
            sum = sum*10 + (s[i]-'0');
        return sum;
    }
};

