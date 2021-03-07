class Solution {
public:
    void Insert(int num)
    {
        v.push_back(num);
        sort(v.begin(),v.end());
    }

    double GetMedian()
    {
        int len = v.size();
        if(len%2==1)
            return double(v[len/2]);
        else
            return double(v[len/2-1]+v[len/2])/2;
    }
private:
    vector<int> v;
};