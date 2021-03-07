//贪心，使用两个哈希表，map1存储数组中每个元素的个数，map2存储以每个元素为序列末尾的序列个数
//在遍历数组时，如果某个元素num[i]在map1中剩余次数为0，则直接考虑num[i+1]，如果num[i]在map1中的剩余次数大于1，才进行下面的操作：
//判断是否存在以num[i]-1为结尾的序列，如果有，则将num[i]也加入该序列，
//如果没有这样的序列，则num[i]需要重新起一个序列，如果无法重新起序列，则直接返回false
//遍历完所有的元素，返回true
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> countMap;
        map<int, int> endMap;
        //记录数组中每个元素的个数
        for(int i=0;i<nums.size();i++)
            countMap[nums[i]]++;

        for (auto& x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0)
                {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                }
                //如果当前的元素的前一个元素并不是某一个序列的结尾，那只能重新起一个序列
                else
                {
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0)
                    {
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};

