#include<iostream>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i=0;i<s.size();i++)
        {
            int value = symbol_value[s[i]];
            if((i<s.size()-1)&&value<symbol_value[s[i+1]])
                result -= value;
            else
                result += value;
        }
        return result;
    }
private:
    map<char, int> symbol_value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};