#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while(s[index]==' ')
            index--;
        int result = 0;
        while(index>=0&&s[index]!=' ')
        {
            index--;
            result++;
        }
        return result;
    }
};
