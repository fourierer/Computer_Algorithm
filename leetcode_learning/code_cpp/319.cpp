#include<iostream>
#include<vector>

using namespace std;

//模拟关灯的过程，通过31/35，当n特别大时超出时间限制
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)
            return n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            for(int index = i;index<n;index += (i+1))
                v[index] = 1 - v[index];
        return accumulate(v.begin(), v.end(), 0);
    }
};

//1.观察每个灯泡被操作的次数，当进行到第i轮时，如果i是第j的灯泡的因子，则第j灯泡会被操作。
//所以可以遍历n个灯泡，观察哪些灯泡有奇数个因子，奇数个因子的一定被操作奇数次，最后是亮的
//2.考虑完全平方数i，i=j^2，除了平方根以外，其余因子总是成对出现，所以平方数的因子总是奇数个。
//解题思路：遍历1,2,...,n，找其中的完全平方数个数就是最后灯泡亮着的个数
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)
            return n;
        int sum = 0;
        for(int i=1;i<=n;i++)
            if(IsSquare(i))
            {
                sum++;
                //cout<<sqrt(i)<<endl;
            }
        return sum;
    }
private:
    bool IsSquare(int i)
    {
        if(i==int(sqrt(i))*int(sqrt(i)))
            return true;
        return false;
    }
};

//再次观察，发现1,2,...,n中有sqrt(n)个完全平方数，所以可以直接返回sqrt(n)
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

