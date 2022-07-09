#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> vmap;
        for(int i=0;i<data.size();i++)
        {
            vmap[data[i]]++;
        }

        int count = 0;
        for(map<int, int>::iterator it=vmap.begin();it!=vmap.end();it++)
        {
            if(it->second == 1)
            {
                count++;
                if(count==1)
                    *num1 = it->first;//这里写num1 = &(it-first)通过不了，原因？？
                if(count==2)
                    *num2 = it->first;
            }
        }
    }
};


int main()
{
    Solution s;
    vector<int> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
    data.push_back(4);
    data.push_back(6);
    data.push_back(6);
    data.push_back(9);
    map<int, int> vmap;
    int* num1;
    int* num2;
    s.FindNumsAppearOnce(data, num1, num2);
    /*
    for(map<int, int>::iterator it = vmap.begin();it!=vmap.end();it++)
        cout<<it->first<<":"<<it->second<<endl;
    */
    cout<<(*num1)<<" "<<(*num2)<<endl;
    return 0;
}
