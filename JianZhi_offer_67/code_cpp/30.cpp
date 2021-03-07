class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int length = array.size();
        vector<int> dp(length);

        dp[0] = array[0];
        int Max = dp[0];
        for(int i=0;i<length;i++)
        {
            if(dp[i-1]+array[i]>array[i])
                dp[i] = dp[i-1]+array[i];
            else
                dp[i] = array[i];
        }
        for(int i=1;i<length;i++)
        {
            if(dp[i]>Max)
                Max = dp[i];
        }
        return Max;
    }
};