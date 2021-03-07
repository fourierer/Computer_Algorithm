/*
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> v;
        for(int i=0;i<length;i++)
            for(int j=i+1;j<length;j++)
                if(array[i]+array[j]==sum)
                {
                    v.push_back(array[i]);
                    v.push_back(array[j]);
                    return v;
                }
        return v;
    }
};
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> v;
        int start = 0;
        int end = length - 1;

        while(start<end)
        {
            if(array[start]+array[end]==sum)
            {
                v.push_back(array[start]);
                v.push_back(array[end]);
                return v;
            }
            else if(array[start]+array[end]<sum)
                start++;
            else
                end--;
        }
        return v;
    }
};

