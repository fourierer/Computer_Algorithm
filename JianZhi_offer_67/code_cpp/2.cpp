#include<iostream>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int num = 0;//空格总数
        for(int i = 0;i < length;i++)
        {
            if(str[i]==' ')
                num++;
        }
        int nindex = length + 2*num;//替换之后的字符总长度
        for(int i = length;i >= 0;i--)
        {
            if(i == nindex)
                break;
            if(str[i]!=' ')
            {
                str[nindex] = str[i];
                nindex--;
            }   
            else
            {
                str[nindex] = '0';
                nindex--;
                str[nindex] = '2';
                nindex--;
                str[nindex] = '%';
                nindex--;
            }
        }
    }
};

int main()
{
    int length = 8;
    //char* new_str = "ad df ef";
    
    char* new_str = new char[length];
    for(int i=0;i<length;i++)
    {
        cin>>new_str[i];
    }
    
    Solution s;
    s.replaceSpace(new_str, 8);
    int new_length = strlen(new_str);
    cout<<new_length<<endl;
    return 0;
}


