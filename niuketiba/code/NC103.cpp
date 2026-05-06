#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string solve(string str) {
        // write code here
        int length = str.size();
        if(length==0)
            return str;
        int i = 0;
        int j = length - 1;
        while(i<j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i++;
            j--;
        }
        return str;
    }
};