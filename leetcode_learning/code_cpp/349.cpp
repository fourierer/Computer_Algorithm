#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<iterator>

using namespace std;

//解法一，使用map
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> num_map1;
        map<int, int> num_map2;
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
            num_map1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            num_map2[nums2[i]]++;
        for(map<int,int>::iterator it=num_map1.begin();it!=num_map1.end();it++)
            if(num_map2.count(it->first))
                v.push_back(it->first);
        return v;
    }
};


//解法二，使用set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> num_set1;
        set<int> num_set2;
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
            num_set1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            num_set2.insert(nums2[i]);
        for(set<int>::iterator it=num_set1.begin();it!=num_set1.end();it++)
            //cout<<*it<<endl;
            if(num_set2.count(*it)==1)
                v.push_back(*it);
        return v;
    }
};

//解法三，排序以及双指针
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> intersection;
        while (index1 < length1 && index2 < length2)
        {
            int num1 = nums1[index1];
            int num2 = nums2[index2];
            if (num1 == num2)
            {
                // 保证加入元素的唯一性
                if (!intersection.size() || num1 != intersection.back())
                    intersection.push_back(num1);
                index1++;
                index2++;
            }
            else if (num1 < num2)
                index1++;
            else
                index2++;
        }
        return intersection;
    }
};


int main()
{
    Solution s;
    vector<int> v1(4,0);
    vector<int> v2(4,0);
    vector<int> out = s.intersection(v1,v2);
    cout<<out[0]<<endl;
    return 0;
}

