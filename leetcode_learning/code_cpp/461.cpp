#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming_distance = 0;
        for(int i=0;i<31;i++)
        {
            int flag = 1<<i;
            if((x&flag)!=(y&flag))
                hamming_distance++;
        }
        return hamming_distance;
    }
};

//或者
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};


