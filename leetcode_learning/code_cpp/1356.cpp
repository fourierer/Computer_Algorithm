//个人解法，暴力双循环排序
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            for(int j = i;j<arr.size();j++)
            {
                if(count_one(arr[i])>count_one(arr[j]))
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                if(count_one(arr[i])==count_one(arr[j]))
                {
                    if(arr[i]>arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        return arr;
    }
private:
    int count_one(int n)
    {
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};

//在官方解法基础上修改，更改sort函数排序规则，使用快排
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(),arr.end(),[&](int x,int y)
        {
            if (count_one(x) < count_one(y))
                return true;
            if (count_one(x) > count_one(y))
                return false;
            return x < y;
        });
        return arr;
    }
private:
    int count_one(int n)
    {
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};


