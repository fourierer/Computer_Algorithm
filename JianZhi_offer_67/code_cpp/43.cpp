#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        char* str1 = new char[len];//string无法指定长度，先定义char*，再转为string
        if(len==0)
            return "";
        else
        {
            for(int i=0;i<len;i++)
            {
                if(i<n)
                    str1[len-(n-i)] = str[i];
                else
                {
                    str1[i-n] = str[i];
                }
            }
        }

        string str_return = str1; //char*转string
        return str_return;
    }
};


int main()
{
    Solution S;
    string s = "12345";
    cout<<S.LeftRotateString(s, 2);
    return 0;
}