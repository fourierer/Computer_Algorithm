class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        unsigned int len = num.size();
        vector<int> v;
        if(size>len||size==0)
            return v;
        for(unsigned int i=0;i<=len-size;i++)
        {
            int max = num[i];
            for(unsigned int j=i;j<i+size;j++)
                if(num[j]>max)
                    max = num[j];
            v.push_back(max);
        }
        return v;
    }
};

