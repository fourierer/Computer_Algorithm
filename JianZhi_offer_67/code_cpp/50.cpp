#include<iostream>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int* hash = new int[length];
        for(int i=0;i<length;i++)
            hash[i] = 0;
        for(int i=0;i<length;i++)
            hash[numbers[i]]++;
        for(int i=0;i<length;i++)
        {
            if(hash[i]>1)
            {
                duplication[0] = i;
                return true;
            }
        }
        return false;
    }
};

/*
int main()
{
    Solution s;
    int numbers[5] = {2,1,3,1,4};
    int length = 5;
    int* duplication = new int[length];
    int* duplication1 = s.duplicate(numbers, length, duplication);
    for(int i=0;i<length;i++)
        cout<<duplication1[i]<<endl;
    cout<<duplication[0];
    return 0;
}
*/


