#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        for(auto c:s)
        {
            if(c=='A')
            {
                absent++;
                if(absent==2)
                    return false;
            }
            if(c=='L')
            {
                late++;
                if(late==3)
                    return false;
            }
            else
                late = 0;
        }
        return true;
    }
};