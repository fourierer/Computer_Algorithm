#include<iostream>
#include<vector>

using namespace std;

//超时
class Solution {
public:
    int nthUglyNumber(int n) {
        int index = 1;
        int count = 0;
        while(count<n)
        {
            if(isUgly(index))
            {
                count++;
                if(count==n)
                    return index;
                index++;
            }
        }
        return 0;
    }
private:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n<=6&&n>0)
            return true;
        while(n%5==0)
            n /= 5;
        while(n%3==0)
            n /= 3;
        while(n%2==0)
            n /= 2;
        if(n==1)
            return true;
        return false;
    }
};


//动态规划：dp[i]=min{dp[p2]*2,dp[p3]*3,dp[p5]*5}
class solution{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i=2;i<=n;i++)
        {
            int num2 = dp[p2]*2;
            int num3 = dp[p3]*3;
            int num5 = dp[p5]*5;
            dp[i] = min(min(num2,num3),num5);
            if(dp[i]==num2)
                p2++;
            if(dp[i]==num3)
                p3++;
            if(dp[i]==num5)
                p5++;
        }
        return dp[n];
    }
};


