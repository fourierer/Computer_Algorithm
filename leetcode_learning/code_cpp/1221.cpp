#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int length = s.size();
        int L = 0;
        int R = 0;
        int result = 0;
        for(int i=0;i<length;i++)
        {
            if(s[i]=='L')
                L++;
            if(s[i]=='R')
                R++;
            if(L==R)
                result++;
        }
        return result;
    }
};
