#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> B;
        for(int i=0;i<length;i++)
        {
            B.push_back(1);//每一位的初始值都为1
            for(int j=0;j<length;j++)
            {
                if(j==i)
                    continue;
                else
                {
                    B[i] *= A[j];
                }
            }
        }
        return B;
    }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    Solution s;
    vector<int> B = s.multiply(A);
    cout<<B.size()<<endl;
    cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<" "<<B[3]<<endl;
    return 0;
}




