#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string solve(string s, string t) {
        int length_s = s.length();
        int length_t = t.length();
        int L = max(length_s, length_t);
        //保证s比t长
        if(length_s<length_t)
        {
            string temp = t;
            t = s;
            s = temp;
        }
        //填充一个新的字符串t1，使得比s短的部分填充为0，其余和t一致
        string t1(s.length(), '0');
        int l = s.length() - t.length();
        //cout<<l<<endl;
        for(int i=0;i<s.length();i++)
        {
            if(i<l)
                ;
            else
                t1[i] = t[i-l];
        }
        //cout<<s<<endl;
        //cout<<t1<<endl;
        int flag = 0;//进位标志
        string result(L + 1, '0');
        for(int i = L;i>=1;i--)
        {
            int r = (s[i-1]-'0')+(t1[i-1]-'0') + flag;
            if(r>=10)
            {
                flag = 1;
                result[i] = r%10 + '0';
            }
            else
            {
                flag = 0;
                result[i] = r + '0';
            }
        }
        //cout<<result<<endl;
        //处理result第一位
        if(flag==1)
        {
            result[0] = 1 + '0';
            return result;
        }
        else
        {
            string Result(s.length(), '0');
            for(int i=0;i<s.length();i++)
                Result[i] = result[i+1];
            return Result;
        }
    }
};


int main()
{
    string s = "99236";
    string t = "23444";
    Solution S;
    string result = S.solve(s,t);
    cout<<result<<endl;
    return 0;
}