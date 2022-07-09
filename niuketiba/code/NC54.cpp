#include<iostream>
#include<vector>

using namespace std;


//超时，无法AC
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        int size = num.size();
        if(size<3)
            return result;
        sort(num.begin(),num.end());
        for(int i=0;i<size-2;i++)
            for(int j=i+1;j<size-1;j++)
                for(int k=j+1;k<size;k++)
                {
                    if(num[i]+num[j]+num[k]==0)
                    {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[k]);
                        result.push_back(tmp);
                        //去重，查看当前进入数组的tmp是否与已有的重复
                        int r_size = result.size();
                        if(r_size>1)
                            for(int index1=0;index1<r_size-1;index1++)
                                if(equal(result[index1], tmp))
                                    result.pop_back();
                                
                    }
                }
        return result;
    }
private:
    bool equal(vector<int> x, vector<int> y)
    {
        return x[0]==y[0]&&x[1]==y[1]&&x[2]==y[2];
    }
};


//对第一个数遍历，剩下的采用双指针来遍历
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        int size = num.size();
        if(size<3)
            return result;
        sort(num.begin(),num.end());
        for(int i=0;i<size-2;i++)
        {
            int j = i+1;
            int k = size-1;
            while(j<k)
            {
                if(num[j]+num[k]<-num[i])
                    j++;
                else if(num[j]+num[k]>-num[i])
                    k--;
                else
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    result.push_back(tmp);
                    //去重，查看当前进入数组的tmp是否与已有的重复
                    int r_size = result.size();
                    if(r_size>1)
                        for(int index1=0;index1<r_size-1;index1++)
                            if(equal(result[index1], tmp))
                                result.pop_back();
                    //当前三元组进入数组之后，j和k都要更新
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
    private:
        bool equal(vector<int> x, vector<int> y)
        {
            return x[0]==y[0]&&x[1]==y[1]&&x[2]==y[2];
        }
};


