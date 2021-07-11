#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        sort(citations.begin(),citations.end());
        for(int i = citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=h+1)
                h++;
            else
                return h;
        }
        return h;
    }
};
