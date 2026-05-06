//解法一，暴力双循环
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            int cnt = 0;//数组中小于当前元素的个数
            for(int j=0;j<length;j++)
            {
                if(nums[j]<nums[i])
                    cnt++;
            }
            v.push_back(cnt);
        }
        return v;
    }
};

//解法二，计数排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101,0);//题目要求值域为[0,100]
        int n = nums.size();
        for(int i=0;i<n;i++)
            cnt[nums[i]]++;//记录每个元素出现的次数
        for(int i=1;i<101;i++)
            cnt[i] += cnt[i-1];//对出现次数进行累加，每一个元素等于前面所有元素的次数和
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                v.push_back(0);
            else
                v.push_back(cnt[nums[i]-1]);
        }
        return v;
    }
};
//如果题目值域为[-m,n],其中m,n为正整数，则可以先对所有元素加上m，全部变为非负数，又可以使用计数排序
//即使用值域作为数组索引，对应的值是出现的次数
//这道题如果使用map，实际上并不好写，因为map在取值的时候，不太好联系相邻元素

