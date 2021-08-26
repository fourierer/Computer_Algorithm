#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int light = 0;
        int heavy = people.size() - 1;
        int result = 0;
        while(light<=heavy)
        {
            if(people[light]+people[heavy]<=limit)
            {
                light++;
                heavy--;
                result++;
            }
            else
            {
                heavy--;
                result++;
            }
        }
        return result;
    }
};
