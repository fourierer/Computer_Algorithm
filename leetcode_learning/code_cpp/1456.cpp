#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int Vowel_Count = 0;
        //统计前k个字符中元音字母数
        for(int i=0;i<k;i++)
            Vowel_Count += IsVowel(s[i]);
        int result = Vowel_Count;
        //滑动窗口，考虑新进的字符和出去的字符
        for(int i=k;i<s.size();i++)
        {
            Vowel_Count += IsVowel(s[i]) - IsVowel(s[i-k]);
            result = max(result, Vowel_Count);
        }
        return result;
    }
private:
    int IsVowel(char c)
    {
        return (c=='a'||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
    }
};
