class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > all_result;
        int start = 1;
        int end = 2;
        while(start<end)
        {
            int cur_sum = (start + end)*(end - start + 1) / 2;
            if(cur_sum<sum)
                end++;
            else if(cur_sum>sum)
                start++;
            else//cur_sum==sum
            {
                vector<int> result;
                for(int i=start;i<=end;i++)
                    result.push_back(i);
                all_result.push_back(result);
                start++;
            }
        }
        return all_result;
    }
};

