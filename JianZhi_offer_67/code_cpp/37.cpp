class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int length = data.size();
        int count = 0;
        for(int i=0;i<length;i++)
        {
            if(data[i] == k)
            {
                count++;
            }
            if((data[i]==k)&&(data[i+1]!=k))
            {
                break;
            }
        }
        return count;
    }
};