#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool bigger_than(int a, int b)
    /*
    ab拼接是否比ba拼接大，字符串比较方式
    */
    {
        string A=to_string(a);//int转string
        string B=to_string(b);
        //return stoi(A+B)>stoi(B+A);//string转int
        return A+B>B+A;
    }

    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string result = "";
        //根据拼接大小顺序给数组排序
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(bigger_than(numbers[i], numbers[j]))
                {
                    int tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;
                }
            }
        }
        //将数组拼成一个字符串返回
        for(int i=0;i<len;i++)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};

int main()
{
    int a = 22;
    int b = 21;
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(32);
    v.push_back(321);
    cout<<s.bigger_than(a, b)<<endl;
    cout<<s.PrintMinNumber(v);
    return 0;
}


//可以改写sort函数简化代码
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string result = "";
        //根据拼接大小顺序给数组排序
        sort(numbers.begin(), numbers.end(),[&](int x, int y)
        {
            return to_string(x)+to_string(y)<to_string(y)+to_string(x);
        });

        //将数组拼成一个字符串返回
        for(int i=0;i<len;i++)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};
