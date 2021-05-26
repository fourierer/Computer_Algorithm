# leetcode_learning

#### 1.两数之和

给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

解法一：双循环暴力搜索

```c++
#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> v;
        int m = nums.size();
        for(int i = 0; i<m; i++)
        {
            for(int j = i + 1; j<m; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;
    }
};


int main()
{
    Solution s;
    vector<int> nums;
    vector<int> v;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    v = s.twoSum(nums, 9);
    cout<<v[0]<<' '<<v[1]<<endl;
    return 0;
}
```




解法二：借助c++中的hash数据结构map，在遍历数组的过程中，判断目标值target和当前数组值的差值是否在map当中；如果在则直接返回两个索引序号，如果不在则记录数组值和对应的索引，分别存储为key-value到map当中，代码如下：

```c++
#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> vmap;
        vector<int> v;
        int length = nums.size();
        for(int i = 0; i<length; i++)
        {
            int diff = target - nums[i];
            //if(vmap.find(diff)!=vmap.end())//判断map里面是否有某个key，find函数如果找到就返回对应的迭代器，找不到就返回末尾的迭代器
            if(vmap.count(diff)==1)//判断map里面是否有某个key，由于map中的key不允许重复，因此如果key存在就返回1，不存在就返回0
            {
                //cout<<nums[i]<<endl;
                v.push_back(vmap[diff]);
                v.push_back(i);
                return v;
            }

            vmap[nums[i]] = i;
        }
        return v;
    }

};


int main()
{
    Solution s;
    vector<int> nums;
    vector<int> v;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    v = s.twoSum(nums, 9);
    cout<<v[0]<<' '<<v[1]<<endl;
    /*
    for(map<int, int>::iterator it=vmap.begin();it!=vmap.end();it++)
        cout<<it->first<<":"<<it->second<<endl;
    */
    return 0;
}
```



#### 5.最长回文子串

给你一个字符串 `s`，找到 `s` 中最长的回文子串。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans = "";
        //k = j-i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = 1;
                else if(k==1)
                    dp[i][j] = (s[i]==s[j]);
                else
                    dp[i][j] = ((s[i]==s[j])&&dp[i+1][j-1]);
                if(dp[i][j]&&k+1>ans.size())
                    ans = s.substr(i,k+1);
            }
        return ans;
    }
};

int main()
{
    string s = "abcdefg";
    string sub_str = s.substr(0,3);
    cout<<sub_str<<endl;
    return 0;
}
```



#### 7.整数反转

给出一个 32 位(int型)的有符号整数，你需要将这个整数中每位上的数字进行反转。

注意：int整数刚好是32位的，所以可以使用一个long型整数来存储反转后的值，然后再判断该long型整数和INT_MAX以及INT_MIN的大小，即可判断是否溢出int型的范围。

```c++
class Solution {
public:
    int reverse(int x) {
        long temp = 0, sum = 0;
        while (x != 0) {
            temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
        }
        if (sum >= INT_MAX || sum <= INT_MIN)
            sum = 0;
        return sum;
    }
};
```



#### 9.回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

```c++
//解法一、判断反转后的数和原数是否相同
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        long flip = 0;
        long temp = 0;
        int store_x = x;
        while(x!=0)
        {
            temp = x%10;
            flip = 10*flip + temp;
            x = x/10;
        }
        return flip==store_x;
    }
};

//解法二、使用字符串，判断首尾是否相同
class Solution{
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        string s = to_string(x);
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
```



#### 12.整数转罗马数字

罗马数字包含以下七种字符: `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。

```
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如， 罗马数字 2 写做 `II` ，即为两个并列的 1。12 写做 `XII` ，即为 `X` + `II` 。 27 写做 `XXVII`, 即为 `XX` + `V` + `II` 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：

- `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。
- `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。 
- `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

```c++
#include<iostream>
#include<string>
#include<map>

using namespace std;

//模拟编码
//写出所有编码情况，按照从大到小依次对num进行编码
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        while(num>=1000)
        {
            result += value_symbol[1000];
            num -= 1000;
        }

        while(num>=900)
        {
            result += value_symbol[900];
            num -= 900;
        }

        while(num>=500)
        {
            result += value_symbol[500];
            num -= 500;
        }

        while(num>=400)
        {
            result += value_symbol[400];
            num -= 400;
        }
        
        while(num>=100)
        {
            result += value_symbol[100];
            num -= 100;
        }

        while(num>=90)
        {
            result += value_symbol[90];
            num -= 90;
        }

        while(num>=50)
        {
            result += value_symbol[50];
            num -= 50;
        }

        while(num>=40)
        {
            result += value_symbol[40];
            num -= 40;
        }

        while(num>=10)
        {
            result += value_symbol[10];
            num -= 10;
        }
        
        while(num>=9)
        {
            result += value_symbol[9];
            num -= 9;
        }

        while(num>=5)
        {
            result += value_symbol[5];
            num -= 5;
        }

        while(num>=4)
        {
            result += value_symbol[4];
            num -= 4;
        }
        
        while(num>=1)
        {
            result += value_symbol[1];
            num -= 1;
        }
        return result;
    }
private:
    map<int, string> value_symbol = {
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"},
        //增加额外编码
        {4, "IV"},
        {9, "IX"},
        {40, "XL"},
        {90, "XC"},
        {400, "CD"},
        {900, "CM"}
    };
};
```



#### 13.罗马数字转整数


罗马数字包含以下七种字符: `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。

```
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如， 罗马数字 2 写做 `II` ，即为两个并列的 1。12 写做 `XII` ，即为 `X` + `II` 。 27 写做 `XXVII`, 即为 `XX` + `V` + `II` 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：

- `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。
- `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。 
- `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

```c++
#include<iostream>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i=0;i<s.size();i++)
        {
            int value = symbol_value[s[i]];
            if((i<s.size()-1)&&value<symbol_value[s[i+1]])
                result -= value;
            else
                result += value;
        }
        return result;
    }
private:
    map<char, int> symbol_value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};
```



#### 19.删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

```c++
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;//创建一个虚假的头结点，防止头结点被删除
        ListNode* pre = fake_head;
        ListNode* p = head;
        //让p先走n-1步
        while(n=n-1)
            p = p->next;
        //然后pre和p一起走
        while(p->next!=NULL)
        {
            p = p->next;
            pre = pre->next;
        }
        //此时p到达链表末尾，pre到达要删除节点的前一个
        ListNode* del_next = pre->next->next;//记录要删除节点的下一个的位置
        pre->next = del_next;//删除该节点
        return fake_head->next;
    }
};
```



#### 21.合并两个有序链表

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

```c++
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//最终返回的头节点指向的下一个节点
        ListNode* cur = head;//当前插入节点的位置
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;//当前节点位置插完，cur转到下一个节点位置
        }
        //判断此时哪个子链表还没有遍历完，将cur指向未遍历完的那一个链表
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return head->next;
    }
};
```



#### 24.两两交换链表中的节点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//递归，时间和空间复杂度都是O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* newhead = head->next;
        head->next = swapPairs(newhead->next);
        newhead->next = head;
        return newhead;
    }
};


//迭代，时间复杂度是O(n)，空间复杂度是O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* temp = fake_head;
        while(temp->next!=NULL&&temp->next->next!=NULL)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return fake_head->next;
    }
};
```



#### 26.删除有序数组中的重复项

给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

思路：

数组完成排序后，我们可以放置两个指针 $i$ 和 $j$，其中 $i$ 是慢指针，而 $j$ 是快指针。只要 $nums[i] = nums[j]$，我们就增加 $j$ 以跳过重复项。当我们遇到 $nums[j] \neq nums[i]$ 时，跳过重复项的运行已经结束，因此我们必须把它（$nums[j]$）的值复制到 $nums[i + 1]$。然后递增 $i$，接着我们将再次重复相同的过程，直到 $j$ 到达数组的末尾为止。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return 0;
        int i = 0;
        for(int j=1;j<size;j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
        
        //如果要求返回前i个元素的数组，可以添加下面的代码
        // for(int index = i+1;index<size;index++)
        // {
        //     nums.pop_back();
        // }
        // return nums;
    }
};
```



#### 27.移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        //如果数组只有一个元素
        if(j==0)
        {
            if(nums[0]==val)
                return 0;
            else
                return j+1;
        }
        while(i<=j)
        {
            //从后往前，寻找第一个不等于val的元素
            while(j>=0&&nums[j]==val)
                j--;
            //需要再判断一次
            if(i>j)
                return j+1;
            if(nums[i]==val)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            else
                i++;
        }
        //此时j所在的位置是最后一个不等于val的值，而i是j的后一位
        return j+1;
        //return i;
    }
};
```



#### 28.实现strStr()

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        for(int i=0;i<haystack.size();i++)
        {
            if(haystack.substr(i, needle.size())==needle)
                return i;
        }
        return -1;
    }
};
```





#### 31.下一个排列

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。必须原地修改，只允许使用额外常数空间。以下是一些例子，输入位于左侧列，其相应输出位于右侧列。

$$
1,2,3 => 1,3,2\\
3,2,1 => 1,2,3\\
1,1,5 => 1,5,1
$$

```c++
//个人的写法，只注意到从后往前寻找第一个大于它左边的数（无法AC）
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //从最右边开始寻找第一个数大于它左边的数
        bool flag = false;
        for(int i=nums.size()-1;i>0;i--)
            if(nums[i]>nums[i-1])
            {
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                flag = true;
                break;
            }
        //判断是否有这样的数，如果没有则反转数组
        if(!flag)
        {
            int i = 0;
            int j = nums.size() - 1;
            while(i<j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
    }
};

//官方写法
//1.首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
//2.如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i] < a[j]。这样「较大数」即为 a[j]。
//3.交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + 1 + i, nums.end());
    }
};
//reverse(nums.begin() + i + 1, nums.end()) //这行代码必须先加1再加i，否则i等于-1时begin()-i将产生异常
```



#### 33.搜索旋转排序数组

整数数组 nums 按升序排列，数组中的值 互不相同 。在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的索引，否则返回 -1 。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return -1;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            //左边有序
            if(nums[mid]>nums[left])
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return left;
        else
            return -1;
    }
};
```



#### 34.在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 [-1, -1]。

```c++
class Solution { 
public:
    int binarySearchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    int binarySearchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int leftIdx = binarySearchLeft(nums, target);
        //cout<<leftIdx<<endl;
        int rightIdx = binarySearchRight(nums, target)-1;
        //cout<<rightIdx<<endl;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
            return vector<int>{leftIdx, rightIdx};
        return vector<int>{-1, -1};
    }
};
```



#### 40.组合总和II

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。

```c++
#include<iostream>
#include<vector>

using namespace std;


//使用leetcode90题的方法，先求子集，再求所有子集中和等于target的子集
//超时，通过23/174
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        //先将数组排序
        sort(nums.begin(),nums.end());
        //mask<(1<<nums.size())，假设nums.size()为4，则mask从0000到1111
        for(int mask=0;mask<(1<<nums.size());mask++)
        {
            vector<int> tmp;
            bool flag = true;
            for(int i=0;i<nums.size();i++)
            {
                //根据mask来确定哪些数添加进当前数组
                if(mask&(1<<i))
                {
                    //如果当前mask中第i位为1,第i-1位为0，并且nums[i]=nums[i-1]，则当前mask确定的数组舍弃
                    if(i>0&&(mask>>(i-1) & 1)==0 && nums[i]==nums[i-1])
                    {
                        flag = false;
                        break;
                    }
                    tmp.push_back(nums[i]);
                }
            }
            if(flag&&EqualTarget(tmp, target))
                result.push_back(tmp);
        }
        return result;
    }
private:
    bool EqualTarget(vector<int> v, int target)
    {
        return accumulate(v.begin(), v.end(), 0)==target;
    }
};
```



#### 42.接雨水

给定 *n* 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = accumulate(height.begin(), height.end(), 0);//对height数组求和，0是和初始值
        int volume = 0;//总体积
        int high = 1;//当前高度

        //双指针
        int left = 0;
        int right = height.size() - 1;
        while(left<=right)
        {
            while(left<=right&&height[left]<high)
                left++;
            while(left<=right&&height[right]<high)
                right--;
            volume += right - left + 1;
            high++;
        }
        return volume - sum;
    }
};
```



#### 46.全排列

给定一个 **没有重复** 数字的序列，返回其所有可能的全排列。

```c++
//解法一、使用第31题的方法，依次获取下一个排列组成全排列
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        int size = fun(nums.size());
        for(int i=0;i<size-1;i++)
            result.push_back(nextPermutation(nums));
        return result;
    }
private:
    //寻找下一个全排列的数组
    vector<int> nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + 1 + i, nums.end());
        return nums;
    }

    int fun(int n)
    {
        if(n<=1)
            return 1;
        return n*fun(n-1);
    }
};


//解法二、官方解法（贼难懂，可以看对应的解释去理解）
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
```



#### 48.旋转图像

给定一个$n×n$的二维矩阵表示一个图像。将图像顺时针旋转90度。必须在原地旋转图像，这意味着需要直接修改输入的二维矩阵，请不要使用另一个矩阵来旋转图像，即不能开内存。

(1)顺时针旋转90度，需要先转置，再根据竖直中心线对称；
(2)逆时针旋转90度，需要先转置，再根据水平中心线对称；
(3)旋转180度，则直接根据对应关系互换即可，a[i][j]=a[n-i][n-j]。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //转置
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int tem=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=tem;
            }
        }
        //对称
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                int tem=matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j]=matrix[i][j];
                matrix[i][j]=tem;
            }
        }   
    }
};

int main()
{
    vector<vector<int> > v;
    vector<vector<int> > v1;
    vector<int> row1,row2,row3,row4;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    v.push_back(row1);

    row2.push_back(5);
    row2.push_back(6);
    row2.push_back(7);
    row2.push_back(8);
    v.push_back(row2);
    
    row3.push_back(9);
    row3.push_back(10);
    row3.push_back(11);
    row3.push_back(12);
    v.push_back(row3);
    
    row4.push_back(13);
    row4.push_back(14);
    row4.push_back(15);
    row4.push_back(16);
    v.push_back(row4);
    
    Solution s;
    s.rotate(v);
    for(int i=0;i<v.size();i++)    
    {
        for(int j=0;j<v[0].size();j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
```



#### 54.螺旋矩阵

给你一个 `m` 行 `n` 列的矩阵 `matrix` ，请按照 **顺时针螺旋顺序** ，返回矩阵中的所有元素。（剑指offer19题顺时针打印矩阵）

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(1)
        {
            //遍历最上面一层
            for(int col = left;col<=right;col++)
                result.push_back(matrix[up][col]);
            up++;
            if(up>down)
                break;
            
            //遍历最右边一层
            for(int row=up;row<=down;row++)
                result.push_back(matrix[row][right]);
            right--;
            if(left>right)
                break;
            
            //遍历最下面一层
            for(int col=right;col>=left;col--)
                result.push_back(matrix[down][col]);
            down--;
            if(up>down)
                break;
            
            //遍历最左边一层
            for(int row=down;row>=up;row--)
                result.push_back(matrix[row][left]);
            left++;
            if(left>right)
                break;
        }
        return result;
    }
};
```





#### 57.插入区间

给出一个*无重叠的 ，*按照区间起始端点排序的区间列表。在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例一：

```
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
```

示例二：

```
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
```

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int> > ans;
        bool flag = false;//记录新区间是否已经被插入
        for(int i=0;i<intervals.size();i++)
        {
            vector<int> tmp_v = intervals[i];
            //如果新区间在当前区间的右侧，直接插入当前区间
            if(tmp_v[1]<left)
                ans.push_back(tmp_v);
            //如果新区间在当前区间左侧，需要先判断新区间是否已经插入了，如果不判断，会导致新区间重复插入
            //如果没插入，则插入新区间，且将flag置为true，再插入当前区间即可
            //如果已经插入，直接插入当前区间即可
            else if(tmp_v[0]>right)
            {
                if(!flag)
                {
                    ans.push_back({left,right});
                    flag = true;
                }
                ans.push_back(tmp_v);
            }
            //如果新区间和当前区间有交集，则将新区间更新为和当前区间的并集
            else
            {
                left = min(left,tmp_v[0]);
                right = max(right, tmp_v[1]);
            }
        }
        //最后再判断新区间是否已经插入了，如果还没有插入，则将新区间插到最后一个位置
        if(!flag)
            ans.push_back({left,right});
        return ans;
    }
};
```



#### 61.旋转链表

给你一个链表的头节点 `head` ，旋转链表，将链表每个节点向右移动 `k` 个位置。

```c++
#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(k==0||head==nullptr||head->next==nullptr)
            return head;
        int len = length(head);
        k = k % len;//防止重复次数过多，可以取余数
        k++;//k+1为了下面的while循环可以重复k次
        while(k=k-1)
            head = OneNode(head);
        return head;
    }
private:
    //向右移动一个节点
    ListNode* OneNode(ListNode* head)
    {
        ListNode* final_two = head;
        while(final_two->next->next)
            final_two = final_two->next;
        //此时final_two指向倒数第二个节点
        ListNode* final_one = final_two->next;
        final_two->next = nullptr;
        final_one->next = head;
        return final_one;
    }

    //计算一个链表的长度
    int length(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};
```



#### 72.编辑距离

给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。你可以对一个单词进行如下三种操作：

(1)插入一个字符
(2)删除一个字符
(3)替换一个字符

```c++
//思路
//1.动态规划：dp[i][j]表示str1的前i个字符编辑成str2的前j个字符需要的最小代价
//2.初始状态：dp[i][0] = i*dc，i次删除；dp[0][i] = i*ic，i次插入
//3.状态转移方程：
//当str[i]==str[j]时：dp[i][j] = dp[i-1][j-1]，不需要额外操作
//当str[i]!=str[j]时：dp[i][j] = min(insert, delete, replace)
//int insert = dp[i][j-1] + ic; i个编辑成j-1个字符，再插入一个j
//int delete = dp[i-1][j] + dc; i-1个编辑成j个字母，再删除一个i
//int replace = dp[i-1][j-1] + rc; i-1个编辑成j-1个字母，再将i替换成j

class Solution {
public:
    int minDistance(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            dp[i][0] = i;
        for(int j=1;j<=n;j++)
            dp[0][j] = j;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int Insert = dp[i][j-1] + 1;
                    int Delete = dp[i-1][j] + 1;
                    int Replace = dp[i-1][j-1] + 1;
                    dp[i][j] = min(min(Insert, Delete),Replace);
                }
            }
        return dp[m][n];
    }
};
```



#### 73.矩阵置0

给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？

```c++
#include<iostream>
#include<vector>

using namespace std;

//使用O(mn)的空间
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(matrix[i][j]==0)
                    index.push_back({i,j});

        for(int i=0;i<index.size();i++)
        {
            vector<int> in = index[i];
            //横排置零
            for(int tmp=0;tmp<col;tmp++)
                matrix[in[0]][tmp] = 0;
            //竖列置零
            for(int tmp=0;tmp<row;tmp++)
                matrix[tmp][in[1]] = 0;
        }
    }
private:
    vector<vector<int>> index;
};


//给出官方一种空间为O(1)的解法，使用第一行和第一列来记录某个元素是否为0;
//这样第一行和第一列的元素会被修改，所以需要再使用两个变量来记录第一行和第一列是否包含0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
```



#### 74.搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==1&&n==1)
            return matrix[0][0]==target;
        for(int i=m-1,j=0;i>=0&&j<n;)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
            {
                i--;
                continue;
            }
            else
            {
                j++;
                continue;
            }
        }
        return false;
    }
};
```





#### 75.颜色分类

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

解法一：使用map记录各个颜色出现的次数，重新赋值数组

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> count_map;
        int length = nums.size();
        if(length==0)
            return;
        //统计红色0，白色1，蓝色2的个数
        int count_red = 0;
        int count_white = 0;
        int count_blue = 0;

        for(int i=0;i<length;i++)
            count_map[nums[i]]++;
        if(count_map.count(0))
            count_red = count_map[0];
        if(count_map.count(1))
            count_white = count_map[1];
        if(count_map.count(2))
            count_blue = count_map[2];
        
        if(count_red!=0)
            for(int j=0;j<count_red;j++)
                nums[j] = 0;
        if(count_white!=0)
            for(int j=count_red;j<count_red+count_white;j++)
                nums[j] = 1;
        if(count_blue!=0)
            for(int j=count_red+count_white;j<count_red+count_white+count_blue;j++)
                nums[j] = 2;
    }
};
```



解法二：使用单指针遍历两遍数组，第一遍将0全部放到头部，第二次将1全部放到中部

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};
```



#### 78.子集

给你一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的子集（幂集）。解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        //mask<(1<<nums.size())，假设nums.size()为4，则mask从0000到1111
        for(int mask=0;mask<(1<<nums.size());mask++)
        {
            vector<int> tmp;
            for(int i=0;i<nums.size();i++)
            {
                //根据mask来确定哪些数添加进当前数组
                if(mask&(1<<i))
                    tmp.push_back(nums[i]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
```



#### 80.删除有序数组中的重复项II

给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

思路：和26题思路一致，不过判断条件改成nums[i-1]!=nums[j]。

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size<=2)
            return size;
        int i=1;
        for(int j=2;j<size;j++)
        {
            if(nums[i-1]!=nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
```



#### 81.搜索旋转排序数组II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

```c++
#include<iostream>
#include<vector>

using namespace std;

//通过174/279
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return false;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            //左边有序，包括等于的情况，这里判断有序的条件少了，比如[1,0,1,1,1]
            if(nums[mid]>=nums[left])
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return true;
        else
            return false;
    }
};

//在上面的基础之上添加判断左边有序的函数
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return false;
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            //左边有序
            bool flag = IsOrder(nums, left, mid);
            //cout<<flag;
            if(flag)
            {
                if(nums[left]<=target&&target<=nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(nums[mid+1]<=target&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(nums[left]==target)
            return true;
        else
            return false;
    }
private:
    bool IsOrder(vector<int>& nums, int start, int end)
    {
        for(int i=start;i<end;i++)
            if(nums[i+1]<nums[i])
                return false;
        return true;
    }
};
```



#### 82.删除排序链表中的重复元素II

存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。返回同样按升序排列的结果链表。

```c++
#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* fake_head = new ListNode(0, head);//创建一个指向head的伪节点
        ListNode* pre = fake_head;
        ListNode* cur = head;
        while(cur&&cur->next)
        {
            if(cur->val==cur->next->val)
            {
                //cur = cur->next;
                while(cur->next&&cur->val==cur->next->val)//先确保cur->next不为空
                    cur = cur->next;
                //此时cur->val!=cur->next->val，但是要删除所有重复的元素
                cur = cur->next;//把重复的最后一个也删掉
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return fake_head->next;
    }
};
```



#### 83.删除链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

```c++
#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* fake_head = new ListNode(0, head);//创建一个指向head的伪节点
        ListNode* pre = fake_head;
        ListNode* cur = head;
        while(cur&&cur->next)
        {
            if(cur->val==cur->next->val)
            {
                cur = cur->next;
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return fake_head->next;
    }
};
```



#### 88.合并两个有序数组

给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        int index = m+n-1;
        int i = m-1;
        int j = n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
                nums1[index--] = nums1[i--];
            else
                nums1[index--] = nums2[j--];
        }
        //考虑nums2中是否还有多的元素
        while(j>=0)
        {
            nums1[index--] = nums2[j--];
        }
    }
};
```



#### 90.子集II

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        //先将数组排序
        sort(nums.begin(),nums.end());
        //mask<(1<<nums.size())，假设nums.size()为4，则mask从0000到1111
        for(int mask=0;mask<(1<<nums.size());mask++)
        {
            vector<int> tmp;
            bool flag = true;
            for(int i=0;i<nums.size();i++)
            {
                //根据mask来确定哪些数添加进当前数组
                if(mask&(1<<i))
                {
                    //如果当前mask中第i位为1,第i-1位为0，并且nums[i]=nums[i-1]，则当前mask确定的数组舍弃
                    if(i>0&&(mask>>(i-1) & 1)==0 && nums[i]==nums[i-1])
                    {
                        flag = false;
                        break;
                    }
                    tmp.push_back(nums[i]);
                }
            }
            if(flag)
                result.push_back(tmp);
        }
        return result;
    }
};
```



#### 91.解码方法

一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。题目数据保证答案肯定是一个 32 位 的整数。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//思路：
//动态规划：dp[i]表示前i个字符能解码的数量
//(1)当s[i-1]!='0'时，dp[i] += dp[i-1]
//(2)当i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10 + (s[i-1]-'0')<=26时，dp[i] += dp[i-2]
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            if(i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10+s[i-1]-'0'<=26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
```



#### 116.填充每个节点的下一个右侧节点指针

解题思路采用层次遍历，在层次遍历代码的基础上增加一个for循环，在该for循环里面进行连接

```c++
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) 
            return root;
        
        // 初始化队列同时将第一层节点加入队列中，即根节点
        queue<Node*> q;
        q.push(root);
        
        // 外层的 while 循环迭代的是层数
        while (!q.empty()) 
        {
            // 记录当前队列大小
            int size = q.size();
            
            // 遍历这一层的所有节点
            for(int i = 0; i < size; i++) 
            {
                // 从队首取出元素
                Node* node = q.front();
                q.pop();

                // 连接
                if (i < size - 1) {
                    node->next = q.front();
                }
                
                // 拓展下一层节点
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }
        // 返回根节点
        return root;
    }
};
```



#### 118.杨辉三角

给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)
            return result;

        result.push_back({1});
        if(numRows==1)
            return result;
        
        result.push_back({1,1});
        if(numRows==2)
            return result;
        else
        {
            for(int i=3;i<=numRows;i++)
            {
                vector<int> v(i);
                v[0] = 1;
                v[i-1] = 1;
                for(int j=1;j<i-1;j++)
                    v[j] = result[i-2][j-1] + result[i-2][j];
                result.push_back(v);
            }
        }
        return result;
    }
};

//或者
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)
            return result;

        result.push_back({1});
        if(numRows==1)
            return result;
        
        result.push_back({1,1});
        if(numRows==2)
            return result;
        else
        {
            for(int i=3;i<=numRows;i++)
            {
                vector<int> v(i);
                result.push_back(v);
                result[i-1][0] = 1;
                result[i-1][i-1] = 1;
                for(int j=1;j<i-1;j++)
                    result[i-1][j] = result[i-2][j-1] + result[i-2][j];
            }
        }
        return result;
    }
};
```



#### 121.买卖股票的最佳时机

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

```c++
#include<iostream>
#include<vector>
#include<math>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0;
        int min_prices = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i]-min_prices);
            min_prices = min(min_prices, prices[i]);
        }
        return max_profit;
    }
};
```





#### 122.买卖股票的最佳时机ii

解法一、贪心

假设某次操作为从$i$天买入，第$j$天卖出，则利润为$a[j]-a[i]$，又因为$a[j]-a[i]=a[i]-a[j-1]+a[j-1]-...-a[i+1]+a[i+1]-a[i]$，相当于很多个第一天买，第二天卖出去，由贪心规则使得利润最大，则需要使得第二天股票价格比第一天高，就进行买入卖出的操作。

解法二、动态规划

考虑到「不能同时参与多笔交易」，因此每天交易结束后只可能存在手里有一支股票或者没有股票的状态。定义状态$dp[i][0]$表示第$i$天交易完后手里没有股票的最大利润，$dp[i][1]$表示第i天交易完后手里持有一支股票的最大利润（$i$从$0$开始）。

考虑$dp[i][0]$的转移方程，如果这一天交易完后手里没有股票，那么可能的转移状态为前一天已经没有股票，即$dp[i-1][0]$，或者前一天结束的时候手里持有一支股票，即$dp[i-1][0]$，这时候我们要将其卖出，并获得$prices[i]$的收益。因此为了收益最大化，我们列出如下的转移方程：


$$
dp[i][0]=max\{dp[i−1][0],dp[i−1][1]+prices[i]\}
$$
再来考虑$dp[i][1]$，按照同样的方式考虑转移状态，那么可能的转移状态为前一天已经持有一支股票，即$dp[i−1][1]$，或者前一天结束时还没有股票，即$dp[i−1][0]$，这时候我们要将其买入，并减少$prices[i]$的收益。可以列出如下的转移方程：


$$
dp[i][1]=max\{dp[i−1][1],dp[i−1][0]−prices[i]\}
$$
对于初始状态，根据状态定义我们可以知道第 00 天交易结束的时候$dp[0][0]=0$，$dp[0][1]=−prices[0]$。

因此，我们只要从前往后依次计算状态即可。由于全部交易结束后，持有股票的收益一定低于不持有股票的收益，因此这时候$dp[n−1][0]$的收益必然是大于$dp[n−1][1]$的，最后的答案即为$dp[n−1][0]$。

```c++
//解法一、贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            ans += max(0,prices[i+1]-prices[i]);
        }
        return ans;
    }
};

//解法二、动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
```



#### 123.买卖股票的最佳时机III

```c++
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

//动态规划
//dp[k][i]表示在第天结束后，经过k次交易(买入且卖出算一次交易)的收益

//超时，通过202/214个测试用例
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 2;//交易的次数，有普适性
        int size = prices.size();
        vector<vector<int>> dp(count+1, vector<int>(size,0));//初始化(k+1)*size的全0数组
        //对交易次数遍历
        for(int k=1;k<=count;k++)
        {
            //对天数遍历
            for(int i=1;i<size;i++)
            {
                //假设第k次交易是在第j天买入，第i天卖出，找最大利润
                int max_profit = prices[i]-prices[0];//初始化最大利润是第一天买入，这里是在i循环的里面初始化的
                for(int j=1;j<=i;j++)
                    max_profit = max(max_profit,prices[i]-prices[j]+dp[k-1][j-1]);
                dp[k][i] = max(dp[k][i-1], max_profit);
            }
        }
        return dp[count][size-1];
    }
};

//优化减少一个循环，在上面代码中要求第i天之前的可以获得最大利润的第j天
//这里转换下思路，求最大利润相当于求最小成本，即prices[i]-prices[j]+dp[k-1][j-1]=prices[i]-(prices[j]-dp[k-1][j-1])
//在对i循环时，就可以维护一个最小成本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 2;//交易的次数，有普适性
        int size = prices.size();
        vector<vector<int>> dp(count+1, vector<int>(size,0));//初始化(k+1)*size的全0数组
        //对交易次数遍历
        for(int k=1;k<=count;k++)
        {
            //对天数遍历
            int min_cost = prices[0];//初始化最小成本是第一天价格，这里是在i循环的外面初始化的
            for(int i=1;i<size;i++)
            {
                //假设第k次交易是在第j天买入，第i天卖出，找最大利润
                min_cost = min(min_cost,prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-min_cost);
            }
        }
        return dp[count][size-1];
    }
};
```



#### 129.求根到叶子节点数字之和

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。计算从根到叶子节点生成的所有数字之和。可以联系剑指offer24题（二叉树中和为某一值的路径）。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//解法一、深度优先遍历
class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode* root, int presum)
    {
        if(root==NULL)
            return 0;
        int sum = presum*10 + root->val;
        if(root->right==NULL&&root->left==NULL)
            return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};

//解法二、广度优先遍历
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        queue<TreeNode*> nodeQueue;
        queue<int> numQueue;
        nodeQueue.push(root);
        numQueue.push(root->val);
        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            int num = numQueue.front();
            nodeQueue.pop();
            numQueue.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left == NULL && right == NULL)
                sum += num;
            else
            {
                if (left != NULL)
                {
                    nodeQueue.push(left);
                    numQueue.push(num * 10 + left->val);
                }
                if (right != NULL)
                {
                    nodeQueue.push(right);
                    numQueue.push(num * 10 + right->val);
                }
            }
        }
        return sum;
    }
};
```



#### 134.加油站

在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。从其中的一个加油站出发，开始时油箱为空。如果可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

```c++
//解法一、暴力双循环，依次尝试每个起始位置，看能否走完全程
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            int cur = i;
            int rest = gas[cur] - cost[cur];
            while(rest>=0)
            {
                cur = cur + 1;
                if(cur==gas.size())
                    cur = 0;
                //这两步可以简化为cur = (cur+1)%gas.size();
                if(cur==i)
                    return i;
                rest += gas[cur] - cost[cur];
            }
        }
        return -1;
    }
};


//解法二、官方解法，需要一点数学证明：如果从x出发无法到达y的下一站，则从x,y之间任意一站(包括x,y)出发，都无法到达下一站
//技术路线：首先检查第0个加油站，并试图判断能否环绕一周；如果不能，就从第一个无法到达的加油站开始继续检查；如果检查到第n个加油站还没有找到符合的，就返回-1。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        while (i < gas.size())
        {
            int rest = 0;
            int cnt = 0;//当前起点能够持续走的加油站个数
            while(cnt < gas.size())
            {
                int j = (i + cnt) % gas.size();
                rest += gas[j] - cost[j];
                if (rest<0)
                    break;
                cnt++;
            }
            if (cnt == gas.size())
                return i;
            else
                i = i + cnt + 1;
        }
        return -1;
    }
};
```



#### 136.只出现一次的数字

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

```c++
#include<iostream>
#include<vector>

using namespace std;

//位运算
//任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
//任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
//异或运算满足交换律和结合律，即a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};
```



#### 137.只出现一次的数字II

给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。

```c++
#include<iostream>
#include<vector>

using namespace std;

//首先想到用哈希表，时间、空间复杂度都为O(n)
//可以先对数组排序，随后三个一组进行遍历，出现一次的数，一定是三个数的第一个
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i=i+3)
        {
            if((i==nums.size()-1)||(nums[i]<nums[i+1]))
                return nums[i];
        }
        return 0;
    }
};
```





#### 141.环形链表

给定一个链表，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。

解法一：使用map或者unordered_set

解法二：快慢指针

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//使用map记录各个节点出现的次数，如果有一个节点出现两次，则有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> node_count;
        while(head!=NULL)
        {
            node_count[head]++;
            if(node_count[head]==2)
                return true;
            head = head->next;
        }
        return false;
    }
};

//快慢指针
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
```



#### 143.重排链表

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

```c++
//联系876题（链表的中间节点）和206题（反转链表）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//解法一：使用一个线性数组保存链表的每一个节点，实现按下标访问
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        vector<ListNode*> v;
        ListNode* p = head;
        while(p!=NULL)
        {
            v.push_back(p);
            p = p->next;
        }
        int i = 0;
        int j = v.size() - 1;
        while(i<j)
        {
            v[i]->next = v[j];
            i++;
            if(i==j)
                break;
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = NULL;
    }
};


//解法二：先找到链表中点，再将右边链表反转，最后合并两个部分
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
```



#### 144.二叉树的前序遍历，

给定一个二叉树，返回它的前序遍历

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        PreOrder(root);
        return v;
    }
private:
    vector<int> v;
    void PreOrder(TreeNode* root)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
};

//非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
            while(root)
            {
                v.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            if(!s.empty())
            {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return v;
    }
};
```



#### 147.对链表进行插入排序

给定一个链表，要求在原地对链表实现插入排序。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//解法一、使用一个数组存储链表节点，排好序之后再重构链表
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
        vector<ListNode*> v;
        //数组存储链表节点
        while(head)
        {
            v.push_back(head);
            head = head->next;
        }
        //按照节点值排序节点
        sort(v.begin(), v.end(), [&](ListNode* x, ListNode* y){
            return x->val<y->val;
        });
        //重构链表
        for(int i=0;i<v.size()-1;i++)
            v[i]->next = v[i+1];
        v[v.size()-1]->next = NULL;

        return v[0];
    }
};


//解法二、按照题意对链表进行插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* pre_cur = head;//当前节点遍历到的位置
        ListNode* cur = pre_cur->next;
        while(cur)
        {
            //如果当前节点小于其下一个节点的值，则往后遍历
            if(pre_cur->val<=cur->val)
            {
                pre_cur = cur;
                cur = cur->next;
            }
            //如果当前节点比其下一个节点大，则需要插入排序
            else
            {
                //先断开当前节点和其下一个节点的连接
                pre_cur->next = cur->next;
                //开始从头遍历到cur，将节点p插入到已经排好序的链表中
                //如果下一个节点小于头结点，则将其作为头节点
                if(cur->val<=head->val)
                {
                    cur->next = head;
                    head = cur;
                    cur = pre_cur->next;
                }
                //如果下一个节点大于头节点，则需要遍历插入
                else
                {
                    //遍历的指针设为pre和start
                    ListNode* start = head;
                    ListNode* pre = new ListNode(0);
                    //在head和pre_cur之间遍历
                    while(start!=cur)
                    {
                        if(cur->val<=start->val)
                        {
                            cur->next = start;
                            pre->next = cur;
                            cur = pre_cur->next;
                            break;//插入完毕，结束while循环
                        }
                        else
                        {
                            pre = start;
                            start = start->next;
                        }
                    }
                }
            }
        }
        return head;
    }
};
```



#### 148.排序链表

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。进阶：可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

```c++
//第147题的两种方法都可以AC，但是时间或者空间复杂度不满足题意，这里主要介绍官方的两种解法。
//归并排序基于分治算法。最容易想到的实现方式是自顶向下的递归实现，考虑到递归调用的栈空间，自顶向下归并排序的空间复杂度是 O(log n)；
//如果要达到 O(1) 的空间复杂度，则需要使用自底向上的实现方式。

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){};
    ListNode(int x):val(x),next(NULL);
    ListNode(int x, ListNode* next):val(x),next(next);
};


//解法一、自顶向下，采用递归，栈空间为O(log n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        return sortlist(head, tail);
    }

    ListNode* sortlist(ListNode* head, ListNode* tail) {
        if(head==tail)
            return head;
        
        if (head->next == tail)
        {
            if(head->val<=tail->val)
                return head;
            else
            {
                tail->next = head;
                head->next = NULL;
                return tail;
            }
        }

        /*
        //找链表中间节点
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        */
        
        //找链表中间节点，不需要使用尾节点
        ListNode* slow = head, *fast = head;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        

        ListNode* mid = slow;
        ListNode* mid_next = mid->next;
        mid->next = NULL;//断开两个子链表
        return merge(sortlist(head, mid), sortlist(mid_next, tail));
    }
    
    //leetcode 21题代码
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//最终返回的头节点前面一个节点
        ListNode* cur = head;//当前插入节点的位置
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;//当前节点位置插完，cur转到下一个节点位置
        }
        //判断此时哪个子链表还没有遍历完，将cur指向未遍历完的那一个链表
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return head->next;
    }
};


//解法二、自底向上
//不会......

```



#### 150.逆波兰表达式求值

根据[ 逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437)，求表达式的值。有效的算符包括 `+`、`-`、`*`、`/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

思路：遍历序列，遇到数字则进栈，遇到运算符需要将栈最上面两个数进行该运算符对应的运算，将结果推入栈中，再继续遍历序列。

```c++
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        for(int i=0;i<size;i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
                s.push(stoi(tokens[i]));
            else
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(tokens[i]=="+")
                    s.push(num2 + num1);
                else if(tokens[i]=="-")
                    s.push(num2 - num1);
                else if(tokens[i]=="*")
                    s.push(num2 * num1);
                else if(tokens[i]=="/")
                    s.push(num2 / num1);
            }
        }
        return s.top();
    }
private:
    stack<int> s;
};
```



#### 153.寻找旋转排序数组中的最小值

已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
            return nums[0];
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            //寻找无序的部分，注意这里判断无序的条件不能写成if(nums[mid]>nums[left]),反例[4,5,6,7,0,1,2]
            if(nums[mid]>nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
```



#### 154.寻找旋转排序数组中的最小值II

已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid;
        while(left<right)
        {
            int mid = (left+right)/2;
            
            if(nums[mid]>nums[right])
                left = mid  + 1;
            else if(nums[mid]<nums[right])
                right = mid;
            else
                right--;
        }
        return nums[left];
    }
};
```





#### 164.最大间距

给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。如果数组元素个数小于 2，则返回 0。

```c++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        sort(nums.begin(), nums.end());
        int max_gap = nums[1] - nums[0];
        for(int i=0;i<nums.size()-1;i++)
            if(max_gap<nums[i+1]-nums[i])
                max_gap = nums[i+1]-nums[i];
        return max_gap;
    }
};
```



#### 179.最大数

给定一组非负整数 `nums`，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。**注意：**输出结果可能非常大，所以你需要返回一个字符串而不是整数。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(int& x, int& y)
{
    return to_string(x)+to_string(y)>to_string(y)+to_string(x);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result = "";
        int flag = 0;
        for(int i=0;i<nums.size();i++)
        {
            //下面两个if语句是为了防止出现[0,0]或者[1,0,0]等情况
            if(nums[i]!=0)
                flag = 1;
            if(flag==0&&i!=nums.size()-1)
                continue;
            result += to_string(nums[i]);
        }
        return result;
    }
};
```



#### 188.买卖股票的最佳时机IV

```c++
class Solution {
public:
    int maxProfit(int count, vector<int>& prices) {
        int size = prices.size();
        if(size==0)
            return 0;
        vector<vector<int>> dp(count+1, vector<int>(size,0));//初始化(k+1)*size的全0数组
        //对交易次数遍历
        for(int k=1;k<=count;k++)
        {
            //对天数遍历
            int min_cost = prices[0];//初始化最小成本是第一天价格，这里是在i循环的外面初始化的
            for(int i=1;i<size;i++)
            {
                //假设第k次交易是在第j天买入，第i天卖出，找最大利润
                min_cost = min(min_cost,prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-min_cost);
            }
        }
        //找各个交易次数的利润最大值
        int result = dp[0][size-1];
        for(int k=0;k<=count;k++)
        {
            //cout<<dp[k][size-1]<<endl;
            result = max(result,dp[k][size-1]);
        }
        return result;
    }
};
```



#### 189.旋转数组

给定一个数组，将数组中的元素向右移动 `k` 个位置，其中 `k` 是非负数。

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。你可以使用空间复杂度为 O(1) 的 **原地** 算法解决这个问题吗？

```c++
#include<iostream>
#include<vector>

using namespace std;

//下面这种写法有bug，比如[-1,-100,3,99],k=2，此时只有-1和3会调换位置，其余的值不变
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        int index = 0;//当前要移动的索引
        int pre = nums[index];
        index = (index + k) % nums.size();
        while(index)
        {
            int cur = nums[index];
            nums[index] = pre;
            pre = cur;
            index = (index + k) % nums.size();     
        }
        //当index回到0时，此时还有一个数pre没有移动到0
        nums[index] = pre;
    }
};

//改进之后发现还是有bug，反例[1,2,3,4,5,6],k=4
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        if(nums.size()%k!=0)
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k) % nums.size();     
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
    }
};

//考虑所有情况
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;

        if(nums.size()%k==0)//如果nums.size()是k的倍数，则需要重复k次跳跃遍历过程
        {
            for(int i=0;i<k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
        else if(nums.size()%(nums.size()-k)==0)//如果nums.size()是(nums.size()-k)的倍数，则需要重复(nums.size()-k)次跳跃遍历过程
        {
            for(int i=0;i<nums.size()-k;i++)
            {
                int index = i;//当前要移动的索引
                int pre = nums[index];
                index = (index + k) % nums.size();
                while(index!=i)
                {
                    int cur = nums[index];
                    nums[index] = pre;
                    pre = cur;
                    index = (index + k) % nums.size();     
                }
                //当index回到0时，此时还有一个数pre没有移动到0
                nums[index] = pre;
            }
        }
        else
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
    }
};

//前面已经注意到：如果k可以整除n，则环形遍历之后会有元素没有遍历到
//改进思路如下：
//(1)如果k不能整除n，则环形遍历可以遍历完所有元素；
//(2)如果k能整除n，可以将k分解为1和k-1，由于分解两个数一定可以遍历完所有元素，所以分两次移动数组即可
//(3)这种思路也有问题，如6个数，移动3个位置，需要分解为2和1，环形遍历2时，同样有遍历不到的元素，这里直接分解为1+1+1

//直接分解为k个1，提示超时，通过34/37
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        
        for(int i=0;i<k;i++)
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + 1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + 1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
    }
};

//直接分解为k-1和1，解答错误，通过33/37
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==k||k==0)
            return;
        //如果可以整除，将k拆成k-1和1
        if(nums.size()%k==0)
        {
            //移动k-1
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k-1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k-1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;

            //移动1
            index = 0;//当前要移动的索引
            pre = nums[index];
            index = (index + 1) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + 1) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
        //如果不能整除
        else
        {
            int index = 0;//当前要移动的索引
            int pre = nums[index];
            index = (index + k) % nums.size();
            while(index)
            {
                int cur = nums[index];
                nums[index] = pre;
                pre = cur;
                index = (index + k) % nums.size();
            }
            //当index回到0时，此时还有一个数pre没有移动到0
            nums[index] = pre;
        }
    }
};


//综上只有考虑因子的解法可以完成该题
```



#### 190.颠倒二进制位

颠倒给定的 32 位无符号整数的二进制位。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32&&n>0;i++)
        {
            uint32_t tmp = n & 1;//获取n最右边一位
            result = result | tmp<<(31 - i);//将最后一位左移31-i位，即移到反装的位置，随后和result做或运算
            n >>= 1;//n右移一位
        }
        return result;
    }
};
```



#### 191.位1的个数

编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为[汉明重量](https://baike.baidu.com/item/汉明重量)）

```c++
//解法一、遍历int型数32位每一位，看是否为1
class Solution{
public:
    int hammingWeight(int x){
        int cnt = 0;
        for(int i=0;i<32;i++)
            //判断第i位是否为1
            if(x&(1<<i))
            cnt++
        return cnt;
    }
};


//解法二、官方解法
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);//消除n最后一位1
            count++;
        }
        return count;
    }
};


//解法三、将32位数分为8组，每组4位，每组的数从0000-1111，即0到15，对每组和15进行与运算，结果可以使用查表法
class Solution{
public:
    int hammingWeight(int x){
        int count = 0;
        for(int i=0;i<8;i++)
        {
            count += arr_cnt[(x>>(i*4)) & 0xf]//count += arr_cnt[(x>>(i*4)) & 15]
        }
    }
private:
    int arr_cnt[16] = {
    0,1,1,2,
    1,2,2,3,
    1,2,2,3,
    2,3,3,4
}
};
```



#### 198.打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = max(0,nums[0]);
        dp[1] = max(dp[0], nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
```



#### 200.岛屿问题

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。此外，你可以假设该网格的四条边均被水包围。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//递归写法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(grid, i, j, grid.size(), grid[0].size());
                    count++;
                }
            }
            return count;
    }
private:
    int DFS(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0')
            return 0;
        grid[i][j] = '0';//把'1'置'0'
        DFS(grid, i-1, j, m, n);
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j-1, m, n);
        DFS(grid, i, j+1, m, n);
        return 0;
    }
};


//非递归写法，在leetcode中通过39/48个案例，提示超时
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                    count++;
                    zero(grid, q);
                }
            }
        return count;
    }
private:
    int zero(vector<vector<char>>& grid, queue<vector<int>>& q)
    {
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty())
        {
            vector<int> index = q.front();
            q.pop();
            int i = index[0];
            int j = index[1];
            grid[i][j] = '0';
            if(!fit(i-1,j,m,n,grid))
                q.push({i-1,j});
            if(!fit(i+1,j,m,n,grid))
                q.push({i+1,j});
            if(!fit(i,j-1,m,n,grid))
                q.push({i,j-1});
            if(!fit(i,j+1,m,n,grid))
                q.push({i,j+1});
        }
        return 0;
    }
    bool fit(int i, int j, int m, int n, vector<vector<char>> grid)
    {
        return i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0';
    }
};
```





#### 204.计数质数

统计所有小于非负整数 *`n`* 的质数的数量。

```c++
class Solution {
public:
    bool isPrime(int x)
    {
        for(int i=2;i*i<=x;i++)
            if(x%i==0)
                return false;
        return true;
    }
    int countPrimes(int n) {
        int count = 0;
        for(int i=2;i<n;i++)
            if(isPrime(i))
                count++;
        return count;
    }
};
```



#### 206.反转链表

反转一个单链表。

```
示例：
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//解法一：使用ListNode*数组来存储节点，再逆序构造新链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next==NULL)
            return head;
        ListNode* p = head;
        while(p)
        {
            v.push_back(p);
            p = p->next;
        }
        int length = v.size();
        for(int i=length-1;i>0;i--)
        {
            v[i]->next = v[i-1];
        }
        v[0]->next = NULL;
        return v[length-1];
    }
private:
    vector<ListNode*> v;
};

//解法二：迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* nextTemp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextTemp;
        }
        return pre;
    }
};

//解法三：递归

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```



#### 208.实现Trie(前缀树)

**[
Trie](https://baike.baidu.com/item/字典树/9825209?fr=aladdin)**（发音类似 "try"）或者说 **前缀树** 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

- `Trie()` 初始化前缀树对象。
- `void insert(String word)` 向前缀树中插入字符串 `word` 。
- `boolean search(String word)` 如果字符串 `word` 在前缀树中，返回 `true`（即，在检索之前已经插入）；否则，返回 `false` 。
- `boolean startsWith(String prefix)` 如果之前已经插入的字符串 `word` 的前缀之一为 `prefix` ，返回 `true` ；否则，返回 `false` 。

```
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```

```c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//数组解法
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        v.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        for(int i=0;i<v.size();i++)
            if(v[i]==word)
                return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(int i=0;i<v.size();i++)
            if(v[i].substr(0, prefix.size())==prefix)
                return true;
        return false;
    }

private:
    vector<string> v;
};



//构建前缀树
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
```

关于前缀树的介绍（参考：https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/）

前缀树是多叉树，即每个节点的分支数量可以为多个。

一般的多叉树定义：

```c++
struct TreeNode{
    VALUETYPE value;//节点值
    TreeNode* children[NUM];//指向孩子节点
};
```

Trie的定义：

```c++
struct TrieNode{
    bool isEnd;//该节点是否是一个串的结束
    TrieNode* next[26];//字母映射表
};
```

包含单词"sea,sells,she"的Trie如下：

![208_1](G:\Documents\Computer_Algorithm\img\leetcode\208_1.png)

![208_2](G:\Documents\Computer_Algorithm\img\leetcode\208_2.png)

定义类Trie：

```c++
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    //方法将在下文实现...
};
```

插入一个单词word:

这个操作和构建链表很像。首先从根结点的子结点开始与 word 第一个字符进行匹配，一直匹配到前缀链上没有对应的字符，这时开始不断开辟新的结点，直到插入完 word 的最后一个字符，同时还要将最后一个结点isEnd = true;，表示它是一个单词的末尾。

```c++
void insert(string word) {
    Trie* node = this;
    for (char c : word) {
        if (node->next[c-'a'] == NULL) {
            node->next[c-'a'] = new Trie();
        }
        node = node->next[c-'a'];
    }
    node->isEnd = true;
}
```

查找单词word：

从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回 `false`，如果匹配到了最后一个字符，那我们只需判断 `node->isEnd`即可。

```c++
bool search(string word) {
    Trie* node = this;
    for (char c : word) {
        node = node->next[c - 'a'];
        if (node == NULL) {
            return false;
        }
    }
    return node->isEnd;
}
```

前缀匹配：

和 search 操作类似，只是不需要判断最后一个字符结点的`isEnd`，因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。

```c++
bool startsWith(string prefix) {
    Trie* node = this;
    for (char c : prefix) {
        node = node->next[c-'a'];
        if (node == NULL) {
            return false;
        }
    }
    return true;
}
```

完整代码：

```c++
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
        }
        return true;
    }
};
```





#### 213.打家劫舍II

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int k = nums.size();
        if (k == 0)
        {
            return 0;
        }
        if (k==1)
        {
            return nums[0];
        }
        if(k==2)
            return max(nums[0], nums[1]);
        vector<int> v1(nums.begin(),nums.begin() + k-1);
        vector<int> v2(nums.begin()+1,nums.begin() + k);
        int vv1 = robp(v1);
        int vv2 = robp(v2);
        return max(vv1,vv2);
    }
private:
    int robp(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = max(0,nums[0]);
        dp[1] = max(dp[0], nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
```



#### 222.完全二叉树的节点个数

给出一个**完全二叉树**，求出该树的节点个数。完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 $h$ 层，则该层包含 $1-2^h$ 个节点。

```c++
//解法一、直接层次遍历树，输出节点个数
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<TreeNode*> v;
        if(root==NULL)
            return v.size();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            v.push_back(node);
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return v.size();
    }
};

//解法二、解法一中的时间复杂度为O(n),空间复杂度也为O(n)，可以采用原地计数的方法来节省空间
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<TreeNode*> v;
        if(root==NULL)
            return v.size();
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        while(!q.empty())
        {
            //遍历当前层所有节点
            int size = q.size();//记录当前层的节点个数，使用q.size()则会发生变化
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                v.push_back(node);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(q.empty())
                return pow(2, layer) - 1 + size;
            layer++;//遍历完一层，层数加1
        }
        return 0;//实际上不会执行，为了通过编译
    }
};
```



#### 227.基本计算器II

给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。整数除法仅保留整数部分。

示例 1：输入：s = "3+2*2"
输出：7
示例 2：输入：s = " 3/2 "
输出：1
示例 3：输入：s = " 3+5 / 2 "
输出：5

```c++
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int length = s.size();
        int nums = 0;
        for(int i=0;i<length;i++)
        {
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!=' ')//防止字符串中有空格
            {
                nums = nums*10 + int(s[i]-'0');//计算连续数字表示的数
            }
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i==length-1)//这里一定要添加i==n-1判断条件，因为遍历到最后一个数也需要计算结果
            {
                if(cur_operator=='+')
                    stk.push(nums);
                else if(cur_operator=='-')
                    stk.push(-nums);
                else if(cur_operator=='*')
                    stk.top() *= nums;
                else if(cur_operator=='/')
                    stk.top() /= nums;
                cur_operator = s[i];
                nums = 0;
            }
        }
        //cout<<cur_operator<<endl;
        int result = 0;
        while(!stk.empty())
        {
            //cout<<stk.top()<<endl;
            result += stk.top();
            stk.pop();
        }
        return result;
    }

private:
    char cur_operator = '+';//初始运算符为+号
    stack<int> stk;
};

int main()
{
    string s = "3/2";
    bool flag = s[1]=='/';
    cout<<flag<<endl;
    return 0;
}
```





#### 242.有效的字母移位词

给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的字母异位词。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map_s;
        map<char, int> map_t;
        for(int i=0;i<s.length();i++)
            map_s[s[i]]++;
        for(int i=0;i<t.length();i++)
            map_t[t[i]]++;
        
        if(map_s.size()!=map_t.size())
            return false;
        for(map<char, int>::iterator it = map_s.begin();it!=map_s.end();it++)
            if(map_t.count(it->first)&&map_t[it->first]==it->second)
                continue;
            else
                return false;
        return true;
    }
};
```



#### 260.只出现一次的数字III

给定一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 **任意顺序** 返回答案。

```c++
#include<iostream>
#include<vector>

using namespace std;

//假设出现一次的两个数分别为a,b
//首先将所有数字进行异或运算，得到a^b的结果x
//在x中二进制遍历，找出现1的那一位，表示a和b的二进制在这一位不一样
//随后根据这一位进行分类，为0的为一组，为1的为一组，则a,b必被分到不同组，并且相同数会被分到同一组
//两组分别异或，得到a,b
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //获取两个出现一次的数的异或结果
        int x = 0;
        for(int i=0;i<nums.size();i++)
            x ^= nums[i];
        //找异或结果中为1的那一位，从低位找起
        int flag = 1;
        while((flag&x)==0)
            flag<<=1;
        int a = 0;
        int b = 0;
        //根据flag进行分组
        for(int i=0;i<nums.size();i++)
        {
            if(flag&nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return vector<int>{a,b};
    }
};
```



#### 263.丑数

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。丑数 就是只包含质因数 2、3 和/或 5 的正整数。

```c++
//根据丑数的定义，丑数n一定可以写成因式分解的形式n=2^a*3^b*5^c
//只需要不断除以因子2,3,5即可
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n<=6&&n>0)
            return true;
        while(n%5==0)
            n /= 5;
        while(n%3==0)
            n /= 3;
        while(n%2==0)
            n /= 2;
        if(n==1)
            return true;
        return false;
    }
};
```



#### 264.丑数II

给你一个整数 `n` ，请你找出并返回第 `n` 个 **丑数** 。**丑数** 就是只包含质因数 `2`、`3` 和/或 `5` 的正整数。

```c++
#include<iostream>
#include<vector>

using namespace std;

//超时
class Solution {
public:
    int nthUglyNumber(int n) {
        int index = 1;
        int count = 0;
        while(count<n)
        {
            if(isUgly(index))
            {
                count++;
                if(count==n)
                    return index;
                index++;
            }
        }
        return 0;
    }
private:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n<=6&&n>0)
            return true;
        while(n%5==0)
            n /= 5;
        while(n%3==0)
            n /= 3;
        while(n%2==0)
            n /= 2;
        if(n==1)
            return true;
        return false;
    }
};


//动态规划：dp[i]=min{dp[p2]*2,dp[p3]*3,dp[p5]*5}
class solution{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i=2;i<=n;i++)
        {
            int num2 = dp[p2]*2;
            int num3 = dp[p3]*3;
            int num5 = dp[p5]*5;
            dp[i] = min(min(num2,num3),num5);
            if(dp[i]==num2)
                p2++;
            if(dp[i]==num3)
                p3++;
            if(dp[i]==num5)
                p5++;
        }
        return dp[n];
    }
};
```



#### 283.移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

```c++
//解法一、记录0的个数，重建数组(需要较大内存)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count = 0;
        vector<int> v;
        //记录0出现的次数
        for(int i=0;i<nums.size();i++)
            zero_count++;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0)
                v.push_back(nums[i]);
        
        if(zero_count!=0)
            for(int i=0;i<zero_count;i++)
                v.push_back(0);
        
        //将v中的元素赋值回nums
        for(int i=0;i<nums.size();i++)
            nums[i] = v[i];
    }
};

//解法二、记录0的个数，在最后末尾补0，实际上erase这个函数可能会浪费内存
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(vector<int>::iterator it = nums.begin();it!=nums.end();)
            if(*it==0)
            {
                count++;
                nums.erase(it);//删除该元素之后，it自动加1
            }
            else
                it++;
        for(int i=0;i<count;i++)
            nums.push_back(0);
    }
};


//解法三、双指针（官方解法）
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
```



#### 300.最长递增子序列

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        //dp[i]表示以nums[i]为结尾的最长递增子序列
        vector<int> dp(size,1);
        //最长递增子序列的长度
        int M = 1;
        for(int i=0;i<size;i++)
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    M = max(dp[i], M);
                }
            }
        return M;
    }
};
```





#### 319.灯泡开关

初始时有 n 个灯泡处于关闭状态。对某个灯泡切换开关意味着：如果灯泡状态为关闭，那该灯泡就会被开启；而灯泡状态为开启，那该灯泡就会被关闭。

第 1 轮，每个灯泡切换一次开关。即，打开所有的灯泡。

第 2 轮，每两个灯泡切换一次开关。 即，每两个灯泡关闭一个。

第 3 轮，每三个灯泡切换一次开关。

第 i 轮，每 i 个灯泡切换一次开关。 而第 n 轮，你只切换最后一个灯泡的开关。

找出 n 轮后有多少个亮着的灯泡。

```c++
#include<iostream>
#include<vector>

using namespace std;

//模拟关灯的过程，通过31/35，当n特别大时超出时间限制
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)
            return n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            for(int index = i;index<n;index += (i+1))
                v[index] = 1 - v[index];
        return accumulate(v.begin(), v.end(), 0);
    }
};

//1.观察每个灯泡被操作的次数，当进行到第i轮时，如果i是第j的灯泡的因子，则第j灯泡会被操作。
//所以可以遍历n个灯泡，观察哪些灯泡有奇数个因子，奇数个因子的一定被操作奇数次，最后是亮的
//2.考虑完全平方数i，i=j^2，除了平方根以外，其余因子总是成对出现，所以平方数的因子总是奇数个。
//解题思路：遍历1,2,...,n，找其中的完全平方数个数就是最后灯泡亮着的个数
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)
            return n;
        int sum = 0;
        for(int i=1;i<=n;i++)
            if(IsSquare(i))
            {
                sum++;
                //cout<<sqrt(i)<<endl;
            }
        return sum;
    }
private:
    bool IsSquare(int i)
    {
        if(i==int(sqrt(i))*int(sqrt(i)))
            return true;
        return false;
    }
};

//再次观察，发现1,2,...,n中有sqrt(n)个完全平方数，所以可以直接返回sqrt(n)
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```



#### 322.兑换零钱

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。你可以认为每种硬币的数量是无限的。

```c++
#include<iostream>
#include<vector>

using namespace std;

//思路：dp[i]表示金额为i所需要的最少硬币数
//dp[i] = min{dp[i],dp[i-coins[i]]+1},i=0,1,2,...,n-1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);//后续有dp[i-coins[j]]+1操作，INT_MAX+1不能用int表示，会报错
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i>=coins[j])
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]>=0&&dp[amount]<=amount)
            return dp[amount];
        return -1;
    }
};
```



#### 327.区间和的个数

给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，索引位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

```c++
//解法一、暴力双循环
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        for(int i = 0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++)
            {
                int sum = 0;
                for(int index = i;index<=j;index++)
                    sum += nums[index];
                if(sum>=lower&&sum<=upper)
                    count ++;
            }
        return count;
    }
};


//解法二、动态规划（实际上还是暴力双循环，但减少了每一次i,j之间元素相加的次数，即用dp记录之前的和）
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        long dp = 0;
        for(int i = 0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++)
            {
                if(i==j)
                    dp = nums[i];
                else
                    dp += nums[j];
                if(dp>=lower&&dp<=upper)
                    count ++;
            }
        return count;
    }
};

//前两种方法都AC不了，超过时间限制
//解法三、归并排序
class Solution {
public:
    int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left == right)
            return 0;
        else
        {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量（和显著逆序数一样，需要先进行计数，实质上也是一种显著逆序数的计算）
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums) {
            s += v;
            sum.push_back(s);
        }
        //sum第一个元素为0，后面为前面元素相加的和
        //如输入数组为[-2,5,-1]，则sum为[0,-2,3,2]
        //这里相加之后，后续计算i,j之间的和时，只需要计算sum[j+1]-sum[i]即可，便于使用归并排序
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
};


//解法四、还是归并排序，不过将归并的过程用一个单独的函数表示，
//并且将工具数组tool_v移到归并函数里面，不用一开始就定义工具数组
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums)
        {
            s += v;
            sum.push_back(s);
        }
        int count = solve(sum, 0, sum.size()-1, lower, upper);
        return count;
    }
private:
    int solve(vector<long>& a, int left, int right, int lower, int upper)
    {
        long cnt = 0;
        int mid = (left+right)/2;
        if(right>left)
        {
            cnt += solve(a, left, mid, lower, upper);
            cnt += solve(a, mid+1, right, lower, upper);
            cnt += merge(a, left, mid, right, lower, upper);
        }
        return cnt;
    }
    
    int merge(vector<long>& a, int left, int mid, int right, int lower, int upper)
    {
        /*
        //开始计数，这段计算代码无法AC，因为无法保证j2要比j1大
        //实际
        int i = left;
        int j1 = mid+1;
        int j2 = right;
        long merge_count = 0;
        while(i<=mid)
        {
            while(a[j1]-a[i]<lower&&j1<=right)
                j1++;
            while(a[j2]-a[i]>upper&&j2>=mid+1)
                j2--;
            merge_count += j2-j1+1;
            i++;
        }
        */
        
        //官方计数代码
        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        long merge_count = 0;
        while (i <= mid)
        {
            while (l <= right && a[l] - a[i] < lower) l++;
            while (r <= right && a[r] - a[i] <= upper) r++;
            merge_count += (r - l);
            i++;
        }
        

        //计数完成再归并排序
        i = left;
        int j = mid+1;
        int k = 0;
        vector<long> tool_a(right-left+1);
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                tool_a[k++] = a[i++];
            else
                tool_a[k++] = a[j++];
        }
        while(i<=mid)
            tool_a[k++] = a[i++];
        while(j<=right)
            tool_a[k++] = a[j++];
        for(int i = 0;i<k;i++)
            a[left+i] = tool_a[i];
        
        return merge_count;    
    }
};
```



#### 328.奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

```c++
//解法一、使用链表数组来存储链表，再根据索引的奇偶性重构链表，时间复杂度和空间复杂度都为O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return head;
        vector<ListNode*> node_v;
        //数组存储链表节点
        while(head!=NULL)
        {
            node_v.push_back(head);
            head = head->next;
        }

        int i = 0; //记录当前节点位置
        for(i=2;i<node_v.size();i=i+2)
            node_v[i-2]->next = node_v[i];
        i = i-2;//for循环使得最后i超出两个位置
        node_v[i]->next = node_v[1];//奇数索引的最后一个要指向偶数索引第一个
        
        for(i=3;i<node_v.size();i=i+2)
            node_v[i-2]->next = node_v[i];
        i = i-2;//for循环使得最后超出两个位置
        node_v[i]->next = NULL;//最后一个位置的节点要指向NULL，否则会出现环

        return node_v[0];
    }
};

//解法二、原地将原链表拆分为奇偶链表，再组合起来（官方源码），时间复杂度为O(N)，空间复杂度都为O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return head;
        ListNode* even_head = head->next;//偶链表的头节点
        ListNode* odd = head;
        ListNode* even = even_head;
        while(even&&even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
```



#### 337.打家劫舍III


在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

```c++
#include<iostream>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//用一个数组分别记录偷根节点和不偷根节点时的最大值
class Solution {
public:
    int rob(TreeNode* root) {
        int * res = doRob(root);
        return max(res[0],res[1]);
    }

    int * doRob(TreeNode * root)
    {
        int * res = new int[2];
        res[0] = 0;
        res[1] = 0;
        if(root == NULL)
            return res;
        int* left = doRob(root->left);
        int * right = doRob(root->right);
        //不偷根节点，最大值为两个子树的最大值之和
        res[0] = max(left[0],left[1])+max(right[0],right[1]);
        //偷根节点，最大值为两个子树不包含根节点的最大值加上根节点的值
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};
```



#### 344.反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

使用双指针：while或者for循环均可

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        if(length==0)
            return;
        int i=0;
        int j = length - 1;
        while(i<j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};
```

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }
};
```



#### 349.两个数组的交集

给定两个数组，编写一个函数来计算它们的交集。

```c++
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<iterator>
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
```



#### 363.矩形区域不超过K的最大值和

给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。题目数据保证总会存在一个数值和不超过 k 的矩形区域。

```c++
#include<iostream>
#include<vector>

using namespace std;


//超出时间限制，通过26/27个测试用例，官方解法看不太懂
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int result = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        //枚举上边界
        for(int i=0;i<m;i++)
        {
            //上下界对应的列和数组
            vector<int> sum(n);
            //枚举下边界
            for(int j=i;j<m;j++)
            {
                for(int c=0;c<n;c++)
                    sum[c] += matrix[j][c];//更新每列的元素和
                //计算当前上下边界对应的列和数组中满足条件的result
                for(int start = 0;start<n;start++)
                    for(int end = start;end<n;end++)
                    {
                        int S = accumulate(sum.begin()+start, sum.begin()+end+1, 0);//从索引start开始一直加到end，必须要加1才会包含end
                        if(S<=k)
                            result = max(S,result);
                    }
            }
        }
        return result;
    }
};
```



#### 368.最大整除子集

给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

思路：求最大的整除子集和最长递增子序列是一样的动态规划

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        //第一步：动态规划找出最大子集的长度以及最大子集中的最大数
        //dp[i]表示以nums[i]为结尾的最长整除子序列的长度
        vector<int> dp(size,1);
        int M = 1;
        int M_val = nums[0];
        for(int i=0;i<size;i++)
            for(int j=0;j<i;j++)
                if(nums[i]%nums[j]==0)
                {
                    dp[i] = max(dp[j]+1, dp[i]);
                    if(M<dp[i])
                    {
                        M = dp[i];
                        M_val = nums[i];
                    }
                }
        
        //第二步：根据获取的最大长度和最大值回溯子集
        vector<int> result;
        if(M==1)
        {
            result.push_back(nums[0]);
            return result;
        }

        for(int i = size-1;i>=0&&M>0;i--)
        {
            if(dp[i]==M&&M_val%nums[i]==0)
            {
                result.push_back(nums[i]);
                M_val = nums[i];
                M--;
            }
        }
        return result;
    }
};
```



#### 402. 移掉K位数字

给定一个以字符串表示的非负整数 *num*，移除这个数中的 *k* 位数字，使得剩下的数字最小。

```c++
//基本思路：给定一个长度为n的数字序列[D_0D_1D_2D_3...D_{n-1}][D0D1D2D3…Dn−1]，
//从左往右找到第一个位置i（i>0）使得 D_i>D_{i+1}，并删去 D_i，
//如果不存在，说明整个数字序列单调不降，删去最后一个数字即可，
//思路较简单，但实现起来需要考虑较多的情况，下面的代码较冗杂。
class Solution {
public:
    string removeKdigits(string num, int k) {
        int count = 0;
        //按照基本思路先删除k个数字
        while(count<k)
        {
            int flag = 0;//记录此次遍历是否已经删除了数字
            for(int i=0;i<num.length();i++)
            {
                if((num[i]-'0'>num[i+1]-'0'))
                {
                    num.erase(i,1);
                    count++;
                    flag = 1;
                    break;
                }
            }
            //如果此次遍历还没有删除数字，即整体单调不减，则删除最后一个数字
            if(flag==0)
            {
                num.erase(num.length());
                flag = 1;
            }
        }
        
        //先排除前面的数字为0的情况，如果都为0，则删除之后变为空串
        for(int i=0;i<num.length();)
        {
            //删除到第一个不为0的元素时，返回字符
            if(num[i]!='0')
                break;
            else if(num[i]=='0')
                num.erase(i,1);//删除当前元素之后，i自动加1
        }

        //如果是空串，则返回0
        if(num=="")
            return "0";
        return num;
    }
};


//通用解法，联系316,321,1081

```



#### 406.根据身高重建队列

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对 (h, k) 表示，其中 h 是这个人的身高，k 是应该排在这个人前面且身高大于或等于 h 的人数。 例如：[5,2] 表示前面应该有 2 个身高大于等于 5 的人，而 [5,0] 表示前面不应该存在身高大于等于 5 的人。

编写一个算法，根据每个人的身高 h 重建这个队列，使之满足每个整数对 (h, k) 中对人数 k 的要求。

```c++
/*
输入: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
1.先进行排序：首先按照第一个元素从高到低排序，当第一个元素相等时，按照第二个从小到大排序：[[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]；
2.按照排好序的结果再次进行插入排序，按照第二个元素进行插入排序，如第二个元素为2，则插入到索引为2的位置。
输出:
[[7, 0]]
[[7, 0], [7, 1]]
[[7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int> x, vector<int> y){
            return x[0]>y[0]||(x[0]==y[0]&&x[1]<y[1]);
        });
        vector<vector<int>> result;
        for(int i=0;i<people.size();i++)
        {
            result.insert(result.begin() + people[i][1],people[i]);
        }
        return result;
    }
};
```



#### 452.用最少数量的箭引爆气球

在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 $x$ 处射出一支箭，若有一个气球的直径的开始和结束坐标为 $x_{start}$，$x_{end}$， 且满足  $x_{start} ≤ x ≤ x_{end}$，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给一个数组 points ，其中 $points [i] = [x_{start},x_{end}]$ ，返回引爆所有气球所必须射出的最小弓箭数。

```c++
//排序+贪心算法
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        //按照所有气球的右侧位置进行排序
        sort(points.begin(),points.end(),[&](vector<int> x, vector<int> y){
            return x[1]<y[1];
        });
        int count = 1;
        int arrow_position = points[0][1];//弓箭初始位置在第一个气球的右侧位置，保证可以引爆第一个气球
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]>arrow_position)
            {
                arrow_position = points[i][1];
                count++;
            }
        }
        return count;
    }
};

```



#### 454.四数相加II

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 $2^{31}-1$ 。

```c++
//解法一、暴力四循环，时间复杂度O(n^4)无法AC
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    for(int l=0;l<n;l++)
                        if(A[i]+B[j]+C[k]+D[l]==0)
                            count++;
        return count;
    }
};


//解法二、将AB分为一组存储元素加和的值以及出现的次数，再对CD进行双循环遍历，看是否有负的结果
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        map<int, int> count_AB;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                count_AB[-A[i]-B[j]]++;
        
        int result = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(count_AB.count(C[i]+D[j]))
                    result += count_AB[C[i]+D[j]];
        return result;
    }
};
```



#### 493.翻转对

给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。你需要返回给定数组中的重要翻转对的数量。

解题思路：实际上就是计算数组中的“显著逆序数”。

```c++
class Solution {
public:
    int reversePairs(vector<int>& v) {
        int count = solve(v,0,v.size()-1);
        return count;
    }
private:
    int solve(vector<int>& a, int left, int right)
    {
        int cnt = 0;
        if(right>left)
        {
            int mid = (right+left)/2;
            cnt += solve(a, left, mid);
            cnt += solve(a, mid+1, right);
            cnt += merge(a, left, mid, right);
        }
        return cnt;
    }
    int merge(vector<int>& a,int left, int mid, int right)
    {
        int i = mid;
        int j = right;
        int merge_count = 0;
        while(i>=left&&j>=mid+1)
        {
            if(long(a[i])>2*long(a[j]))//此处是计算显著逆序数，具有一般性
            {
                merge_count += j-mid;
                i--;
            }
            else
            {
                j--;
            }
        }
        //计数完成，需要归并排序
        i = mid;
        j = right;
        int k=0;
        vector<int> b(right-left+1);
        while(i>=left&&j>=mid+1)
        {
            if(a[i]>a[j])
                b[k++] = a[i--];
            else
                b[k++] = a[j--];
        }
        while(i>=left)
            b[k++] = a[i--];
        while(j>=mid+1)
            b[k++] = a[j--];
        for(int i=0;i<k;i++)
            a[right-i] = b[i];
        
        return merge_count;
    }
};
```





#### 509.斐波那契数列

斐波那契数，通常用$F(n)$表示，形成的序列称为斐波那契数列。该数列由0和1开始，后面的每一项数字都是前面两项数字的和。也就是：
$$
F(0) = 0,   F(1) = 1\\
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
$$

给定$N$，计算$F(N)$。

```c++
class Solution {
public:
    int fib(int N) {
        if(N<2)
            return N;
        int pre = 0;
        int cur = 1;
        int sum = 0;
        for(int i=1;i<N;i++)
        {
            sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return sum;
    }
};
```



#### 518.零钱兑换II

给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

```c++
#include<iostream>
#include<vector>

using namespace std;

//动态规划
//dp[i]表示组成金额i的组合数
//dp[i] = sum{dp[i-coin[j]]},j=0,1,...,n-1
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;//组成金额0的只有一种
        for(int j=0;j<coins.size();j++)
        {
            for(int i=1;i<=amount;i++)
            {
                if(i>=coins[j])
                    dp[i] += dp[i-coins[j]];
            }
        }
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<endl;
        return dp[amount];
    }
};
```



#### 530.二叉搜索树的最小绝对差

给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

二叉搜索树的中序遍历就是该二叉树节点升序的结果，直接遍历该数组，找出相邻元素的最小间隔返回即可。

```c++
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        GetMidOrder(root);
        int minval = GetMinVal(v);
        return minval;
    }

private:
    vector<int> v;
    void GetMidOrder(TreeNode* root)
    {
        if(root==NULL)
            return;
        GetMidOrder(root->left);
        v.push_back(root->val);
        GetMidOrder(root->right);
    }
    int GetMinVal(vector<int> v)
    {
        int n = v.size();
        int minval = v[1]-v[0];
        for(int i=0;i<n-1;i++)
        {
            int temp = v[i+1]-v[i]);
            if(minval>temp)
                minval = temp;
        }
        return minval;
    }
};
```



#### 633.平方数之和

给定一个非负整数 `c` ，你要判断是否存在两个整数 `a` 和 `b`，使得 `a2 + b2 = c` 。

```c++
#include<iostream>
#include<math.h>

using namespace std;

//枚举
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a=0;a<=sqrt(c);a++)
        {
            double b = sqrt(c-a*a);
            if(b==int(b))
                return true;
        }
        return false;
    }
};

//费马平方和定理
//一个非负整数 c 如果能够表示为两个整数的平方和，当且仅当 c 的所有形如 4k + 3 的质因子的幂均为偶数。
class Solution
{
public:
    bool judgeSquareSum(int c){
        for(int base=3;base<=c;base++)
        {
            //判断当前base是否为因子
            if(c%base!=0)
                continue;
            
            //如果是因子，求该因子的幂
            int exp = 0;
            while(c%base==0)
            {
                c /= base;
                exp++;
            }

            //费马平方和定理证明
            if((base%4==3)&&(exp%2!=0))
                return false;
        }
        return true;
    }
};
```



#### 659.分割数组为连续子序列

给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个长度为 3 的子序列，其中每个子序列都由连续整数组成。如果可以完成上述分割，则返回 true ；否则，返回 false 。

```c++
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
```



#### 669.修建二叉搜索树

给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

```c++
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        if(root->val<low)
            return trimBST(root->right, low, high);
        if(root->val>high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```





#### 690.员工的重要性

给定一个保存员工信息的数据结构，它包含了员工 唯一的 id ，重要度 和 直系下属的 id 。

比如，员工 1 是员工 2 的领导，员工 2 是员工 3 的领导。他们相应的重要度为 15 , 10 , 5 。那么员工 1 的数据结构是 [1, 15, [2]] ，员工 2的 数据结构是 [2, 10, [3]] ，员工 3 的数据结构是 [3, 5, []] 。注意虽然员工 3 也是员工 1 的一个下属，但是由于 并不是直系 下属，因此没有体现在员工 1 的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工 id ，返回这个员工和他所有下属的重要度之和。

```c++
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

//深度优先遍历，递归
class Solution {
public:
    int getImportance(vector<Employee> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee employee = employees[i];
            id_map[employee.id] = employee;
        }
        return dfs(id_map, id);
    }
private:
    int result;
    map<int, Employee> id_map;
    int dfs(map<int, Employee> id_map, int id)
    {
        int size = id_map[id].subordinates.size();
        if(size==0)
            return id_map[id].importance;
        for(int i=0;i<size;i++)
            result += dfs(id_map, id_map[id].subordinates[i]);
        return result;
    }
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee* employee = employees[i];
            id_map[employee->id] = employee;
        }
        return dfs(id_map, id);
    }
private:
    map<int, Employee*> id_map;
    int dfs(map<int, Employee*> id_map, int id)
    {
        int size = id_map[id]->subordinates.size();
        if(size==0)
            return id_map[id]->importance;
        int result = id_map[id]->importance;
        for(int i=0;i<size;i++)
            result += dfs(id_map, id_map[id]->subordinates[i]);
        return result;
    }
};


//广度优先遍历，非递归
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee* employee = employees[i];
            id_map[employee->id] = employee;
        }
        return bfs(id_map, id);
    }
private:
    map<int, Employee*> id_map;
    int bfs(map<int, Employee*> id_map, int id)
    {
        int size = id_map[id]->subordinates.size();
        if(size==0)
            return id_map[id]->importance;
        int result = 0;
        queue<int> q;
        q.push(id);
        while(!q.empty())
        {
            int id_cur = q.front();
            q.pop();
            result += id_map[id_cur]->importance;
            int sub_size = id_map[id_cur]->subordinates.size();
            for(int i=0;i<sub_size;i++)
            {
                q.push(id_map[id_cur]->subordinates[i]);
            }
        }
        return result;
    }
};
```



#### 692.前K个高频单词

给一非空的单词列表，返回前 *k* 个出现次数最多的单词。返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

```c++
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>

using namespace std;

//先用一个map记录各个单词出现的频次，然后使用一个数组result记录共出现了哪些单词，
//在该数组result的基础上，按照字符串从小到大，map中出现频次从大到小排序，
//最后删除result中k个元素之后的那些元素即可。
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> str_count;
        for(int i=0;i<words.size();i++)
            str_count[words[i]]++;
        //result中包含words中出现过的单词
        vector<string> result;
        for(map<string, int>::iterator it = str_count.begin();it!=str_count.end();it++)
            result.push_back(it->first);
        sort(result.begin(), result.end(), [&](string x, string y){
            return str_count[x]==str_count[y]?x<y:str_count[x]>str_count[y];
        });
        //删除result中k个元素以后的元素
        result.erase(result.begin()+k, result.end());
        return result;
    }
};
```



#### 767.重构字符串

给定一个字符串`S`，检查是否能重新排布其中的字母，使得两相邻的字符不同。若可行，输出任意可行的结果。若不可行，返回空字符串。

注意：这里的代码将奇数偶数情况放在一起写了，不用分别考虑。

```c++
class Solution {
public:
    string reorganizeString(string S) {
        if(S.length()<3)
            return S;
        //记录S中字符出现的次数，初始化一个vector，长度为26，每个位置上都为0
        vector<int> count_S(26);
        //S中字符出现的最大次数
        int max_count = 0;
        for(int i=0;i<S.length();i++)
        {
            count_S[S[i]-'a']++;
            if(count_S[S[i]-'a']>max_count)
                max_count = count_S[S[i]-'a'];
        }
        //如果出现最大次数的字母次数超过(n+1)/2，则无法使得相邻的字符不同
        if(max_count>(S.length()+1)/2)
            return "";
        
        //初始化一个string，长度为S.length()，每个位置上都是空字符
        string result(S.length(), ' ');
        //维护偶数索引和奇数索引用来放置字母
        int evenindex = 0;
        int oddindex = 1;
        for(int i=0;i<26;i++)
        {
            char c = i + 'a';
            //出现次数小于等于S.length()/2的字符要先放在奇数索引上
            while(count_S[i]>0&&count_S[i]<=S.length()/2&&oddindex<S.length())
            {
                result[oddindex] = c;
                count_S[i]--;
                oddindex += 2;
            }
            while(count_S[i]>0&&evenindex<S.length())
            {
                result[evenindex] = c;
                count_S[i]--;
                evenindex += 2;
            }
        }
        return result;
    }
};
```



#### 781.森林中的兔子

森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。返回森林中兔子的最少数量。

```
示例:
输入: answers = [1, 1, 2]
输出: 5
解释:
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。

输入: answers = [10, 10, 10]
输出: 11

输入: answers = []
输出: 0
```

使用贪心策略：

两只相同颜色的兔子看到的其他同色兔子数必然是相同的。反之，若两只兔子看到的其他同色兔子数不同，那么这两只兔子颜色也不同。

因此，将 answers 中值相同的元素分为一组，对于每一组，计算出兔子的最少数量，然后将所有组的计算结果累加，就是最终的答案。

例如，现在有 13 只兔子回答 5。假设其中有一只红色的兔子，那么森林中必然有 6 只红兔子。再假设其中还有一只蓝色的兔子，同样的道理森林中必然有 6 只蓝兔子。为了最小化可能的兔子数量，我们假设这 12 只兔子都在这 13 只兔子中。那么还有一只额外的兔子回答 5，这只兔子只能是其他的颜色，这一颜色的兔子也有 6 只。因此这种情况下最少会有 18 只兔子。

一般地，如果有 x 只兔子都回答 y，则至少有$floor(x/(y+1))$种不同的颜色，且每种颜色有 y+1 只兔子，因此兔子数至少为$floor(x/(y+1))*(y+1)$。先用一个哈希结构存储相同数字兔子的个数，再遍历该哈希表，依次计算每种颜色的数量。

```c++
#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> count_map;
        for(int i=0;i<answers.size();i++)
        {
            count_map[answers[i]]++;
        }
        int total_sum = 0;
        for(map<int, int>::iterator it = count_map.begin();it!=count_map.end();it++)
        {
            int x = it->second;//多少只兔子说相同的数字
            int y = it->first;//相同的数字
            total_sum += floor(x,y+1) * (y+1);
        }
        return total_sum;
    }
private:
    int floor(int x, int y)
    {
        //返回x/y向上取整的数
        //加上y-1就可以实现向上取整
        return (x+y-1)/y;
    }
};
```



#### 781.二叉搜索树节点最小距离

给你一个二叉搜索树的根节点 `root` ，返回 **树中任意两不同节点值之间的最小差值** 。

```c++
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        MidOrder(root);
        int Min = INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            Min = min(Min,abs(v[i]-v[i-1]));
        }
        return Min;
    }
private:
    vector<int> v;
    void MidOrder(TreeNode* root)
    {
        if(!root)
            return;
        MidOrder(root->left);
        v.push_back(root->val);
        MidOrder(root->right);
    }
};
```



#### 861.翻转矩阵后的得分

有一个二维矩阵 A 其中每个元素的值为 0 或 1 。移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。返回尽可能高的分数。

```c++
//使用贪心算法
//注意到一个事实，对应相邻的两次翻转（行行，列列，行列或者列行），更改翻转顺序，结果不变
//所以先进行行翻转，再进行列翻转。
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        //行变换，将每一行第一个元素不是1的行进行翻转
        for(int i = 0;i<A.size();i++)
        {
            if(A[i][0]==0)
            {
                for(int j=0;j<A[i].size();j++)
                    A[i][j] = 1 - A[i][j];
            }
            else
                continue;
        }

        //列变换，如果某一列的0比1多，则进行列翻转
        for(int j = 0;j<A[0].size();j++)
        {
            int count0 = 0;
            int count1 = 0;
            for(int i = 0;i<A.size();i++)
            {
                if(A[i][j]==0)
                    count0++;
                else
                    count1++;
            }
            if(count0>count1)
            {
                for(int i=0;i<A.size();i++)
                    A[i][j] = 1 - A[i][j];           
            }
            else
                continue;
        }

        //计算分数
        int sum = 0;
        for(int i = 0;i<A.size();i++)
        {
            sum += cal_binary(A[i]);
        }
        return sum;
    }
private:
    int cal_binary(vector<int> v)
    {
        int sum = 0;
        for(int i = 0;i<v.size();i++)
        {
            sum += v[i]*pow(2,v.size()-1-i);
        }
        return sum;
    }
};
```



#### 872.叶子相似的树

请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 *叶值序列* 。如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

```c++
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode*left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = fun(root1);
        vector<int> leaf2 = fun(root2);
        if(leaf1.size()!=leaf2.size())
            return false;
        else
        {
            for(int i=0;i<leaf2.size();i++)
                if(leaf1[i]!=leaf2[i])
                    return false;
        }
        return true;
    }
private:
    //求一棵树的叶子节点序列(叶值序列)
    vector<int> fun(TreeNode* root)
    {
        vector<int> leaf;
        Mid(root, leaf);
        return leaf;
    }
    void Mid(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        Mid(root->left, v);
        if((root->left==nullptr)&&(root->right==nullptr))
            v.push_back(root->val);
        Mid(root->right, v);
    }
};
```



#### 876.链表的中间结点

给定一个带有头结点 `head` 的非空单链表，返回链表的中间结点；如果有两个中间结点，则返回第二个中间结点。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //解法一：快慢指针
 //慢指针和快指针同时从head开始走，慢指针一次走一步，快指针一次走两步，当快指针到末尾时，慢指针到达第二个中间节点
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


//解法二：单指针遍历两次，第一次计数，第二次按照数量取中间节点
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }
        int k = 0;
        cur = head;
        while (k < n / 2) {
            ++k;
            cur = cur->next;
        }
        return cur;
    }
};
```



#### 905.按奇偶排序数组

给定一个非负整数数组 A，返回一个数组，在该数组中， A的所有偶数元素之后跟着所有奇数元素。可以返回满足此条件的任何数组作为答案。

```c++
//解法一、暴力冒泡，两个for循环，遇到相邻的奇偶就互换位置,O(n^2)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0;i<A.size();i++)
            for(int j=i;j<A.size();j++)
                if(A[i]%2==1&&A[j]%2==0)
                    swap(A[i], A[j]);
        return A;
    }
};


//解法二、重新改写排序规则，新的排序规则：奇数“大于”偶数,O(nlogn)
bool compare(int& x, int& y)
{
    if(x%2==0&&y%2==1)
        return true;
    return false;
}
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        sort(A.begin(), A.end(), compare);
        return A;
    }
};

//解法三、双指针遍历
class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        //遍历一遍数组，记录偶数个数
        int flag = 0;
        for(int i=0;i<A.size();i++)
            if(A[i]%2==0)
                flag++;
        int i = 0;
        int j = flag;
        //while循环一定要有j<A.size()，否则里面循环的j会出界，以及当数组全为偶数时，也能返回正确答案
        while(i<flag&&j<A.size())
        {
            if(A[i]%2==0&&A[j]%2==1)
            {
                i++;
                j++;
            }
            else if(A[i]%2==0&&A[j]%2==0)
                i++;
            else if(A[i]%2==1&&A[j]%2==1)
                j++;
            else
            {
                swap(A[i],A[j]);
                i++;
                j++;
            }
        }
        return A;
    }
};
```



#### 922.按奇偶排序数组II

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。可以返回任何满足上述条件的数组作为答案。

```c++
//使用双指针i,j分别指向偶数索引位置和奇数索引位置
//如果A[i]为奇，A[j]为偶，则互换位置，i,j同时加2；
//如果A[i]为奇，A[j]为奇，则i不动（需要等待j出现偶数），j加2；
//如果A[i]为偶，A[j]为偶，则j不动（需要等待i出现奇数），i加2；
//如果A[i]为偶，A[j]为奇，则满足条件，j,j同时加2；
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0;
        int j = 1;
        while(i<A.size()&&j<A.size())
        {
            if(A[i]%2==1&&A[j]%2==0)
            {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            }
            else if(A[i]%2==1&&A[j]%2==1)
                j += 2;
            else if(A[i]%2==0&&A[j]%2==0)
                i += 2;
            else
            {
                i += 2;
                j += 2;
            }
        }
        return A;
    }
};
```



#### 938.二叉搜索树的范围和

给定二叉搜索树的根结点 `root`，返回值位于范围 *`[low, high]`* 之间的所有结点的值的和。

```c++
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left), right(right){}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        Mid(root);
        int Sum = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=low&&v[i]<=high)
                Sum += v[i];
        }
        return Sum;
    }
private:
    vector<int> v;
    void Mid(TreeNode* root)
    {
        if(!root)
            return;
        Mid(root->left);
        v.push_back(root->val);
        Mid(root->right);
    }
};
```



#### 941.有效的山脉数组

给定一个整数数组 `A`，如果它是有效的山脉数组就返回 `true`，否则返回 `false`。

如果 A 满足下述条件，那么它是一个山脉数组：

```
A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
```

```c++
//解法一
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int length = A.size();
        int i = 0;

        // 递增扫描
        while (i + 1 < length && A[i] < A[i + 1])
            i++;
        // 最高点不能是数组的第一个位置或最后一个位置
        if (i == 0 || i == length - 1)
            return false;

        // 递减扫描
        while (i + 1 < length && A[i] > A[i + 1])
            i++;
        return i == length - 1;
    }
};

//解法二
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int length = A.size();
        int i = 0;
        int count = 0;
        // 递增扫描
        for(int i=0;i<length-1;i++)
            if(A[i]<A[i+1])
                count++;
        //数组不能是递增或者递减
        if (count == 0 || count == length - 1)
            return false;
        // 递减扫描
        for(int i=count;i<length-1;i++)
            if(A[i]>A[i+1])
                count++;
        return count==length-1;
    }
};
```



#### 973.最接近原点的K个点

有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。（这里，平面上两点之间的距离是欧几里德距离。）可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

```c++
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
//解法一、改变sort函数的判断机制，即改写sort函数（注意，如果使用数学公式pow来计算欧式距离会超出时间限制）
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > ans;
        //按照数组点与原点的欧式距离进行排序
        sort(points.begin(), points.end(), [&](vector<int> x, vector<int> y)
        {
            return (x[0]*x[0]+x[1]*x[1])<(y[0]*y[0]+y[1]*y[1]);
        });

        /*
        for(int i=0;i<points.size();i++)
            cout<<"["<<points[i][0]<<","<<points[i][1]<<"]"<<endl;
        */

        for(int i=0;i<K;i++)
            ans.push_back(points[i]);

        return ans;
    }
};

//或者这样改写sort函数
bool compare(vector<int>& a,vector<int>& b)
{
    int distance1=a[0]*a[0]+a[1]*a[1];
    int distance2=b[0]*b[0]+b[1]*b[1];
    return distance1<distance2;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(),points.end(),compare);
        for(int i=0;i<K;++i)
        {
            res.push_back(points[i]);
        }
        return res;
    }
};


//解法二、快速排序
//只需依次寻找最近的K个点即可（超出时间限制，因为有一些很nt的例子）
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(points.size()==K)
            return points;
        vector<vector<int>> result;
        for(int i=0;i<K;i++)
        {
            int index = points.size() - i;
            vector<int> ith_min = find_max_k(points, index);
            result.push_back(ith_min);
        }
        return result;
    }
private:
    vector<int> find_max_k(vector<vector<int>> v, int k)
    {
        vector<int> result = solve(v, 0, v.size()-1, k);
        return result;
    }

    vector<int> solve(vector<vector<int>>& a, int start, int end, int k)
    {
        int mid = divide(a, start, end);
        int length_of_right = end - mid + 1;
        if(length_of_right==k)
            return a[mid];
        else if(length_of_right>k)
            return solve(a, mid+1, end, k);
        else
            return solve(a, start, mid-1, k-length_of_right);
    }

    int divide(vector<vector<int>>& a, int start, int end)
    {
        if(start>=end)
            return start;

        int i = start;
        int j = end;
        int pivot = a[start][0]*a[start][0]+a[start][1]*a[start][1];

        while(i<j)
        {
            while(a[j][0]*a[j][0]+a[j][1]*a[j][1]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);//c++自带更换两个vector的函数
            while(a[i][0]*a[i][0]+a[i][1]*a[i][1]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        return i;//此时i==j
    }
};
```



#### 976.三角形的最大周长

给定由一些正数（代表长度）组成的数组 `A`，返回由其中三个长度组成的、**面积不为零**的三角形的最大周长。如果不能形成任何面积不为零的三角形，返回 `0`。

思路：贪心+排序

可以先对数组从小到大进行排序，然后从后往前遍历。以大数为最长边，并往后再考虑两个数作为三角形的三条边长，如果两个小数之和大于大数，则可以组成周长最长的三角形；如果组不成三角形，则再往前取任何两个数都组不成三角形。

```c++
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int size = A.size();
        if(size<3)
            return 0;
        sort(A.begin(),A.end());
        for(int i=size-1;i-2>=0;i--)
            if(A[i]<A[i-1]+A[i-2])
                return A[i] + A[i-1] + A[i-2];
        return 0;
    }
};
```



#### 993.二叉树的堂兄弟节点

在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。

```c++
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right),left(left),right(right){}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        //x和y的深度
        int dx = 0;
        int dy = 0;
        int h = 0;
        //x和y的父节点
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            h++;
            int size = q.size();
            //下面必须使用一个for循环，因为要保证同一层的节点对应的h高度是一样的
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                {
                    if(tmp->left->val==x)
                    {
                        dx = h+1;
                        px = tmp;
                    }
                    else if(tmp->left->val==y)
                    {
                        dy = h+1;
                        py = tmp;
                    }
                    q.push(tmp->left);
                }

                if(tmp->right)
                {
                    if(tmp->right->val==x)
                    {
                        dx = h+1;
                        px = tmp;
                    }
                    else if(tmp->right->val==y)
                    {
                        dy = h+1;
                        py = tmp;
                    }
                    q.push(tmp->right);
                }
            }
        }
        return (dx==dy)&&(px!=py);
    }
};
```



#### 1002.查找常用字符

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。

例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。可以按任意顺序返回答案。

解题思路：该题求解需要一个局部字典，来记录当前字符串中每个字符出现的次数；一个全局字典来记录字符串数组中所有字符的最小次数。最后根据这个全局字典来构造返回的字符数组。

注意：

（1）全局字典在初始化时，26个字母全部初始化为最大值；局部字典在初始化时，全部初始化为0；

（2）每遍历一个字符串，都要利用当前局部字典来更新全局字典中每个字母出现的最小次数；

（3）c++中字符char转为字符串string的方法：

```c++
char a = 'd';
string s(1,a);//1代表字符的长度
cout<<s<<endl;//"d"
```

最后给出完整代码：（包括主函数测试的部分）

```c++
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int length = A.size();
        if(length==0)
            return v;
        map<char, int> char_global_min_count;
        map<char, int> char_local_min_count;
        //初始化字母全局最少次数字典，均赋值为INT_MAX
        char_global_min_count = global_min();

        //遍历字符数组A，计算每个字符的局部最少次数，同时更新全局最少次数
        for(int i=0;i<length;i++)
        {
            //初始化字母局部最少次数字典均为0
            char_local_min_count = local_min();

            int len = A[i].length();
            //计算当前字符每个字母出现的最少次数
            for(int j=0;j<len;j++)
            {
                char_local_min_count[A[i][j]]++;
            }

            //更新字母全局最少次数字典
            for(int s = 0; s<26; s++)
            {
                char_global_min_count['a'+s] = min(char_global_min_count['a'+s], char_local_min_count['a'+s]);
            }
        }
        /*
        //测试字母全局最少次数字典
        for(map<char, int>::iterator it=char_global_min_count.begin();it!=char_global_min_count.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        */

        //根据字母全局最少次数字典来返回字符数组
        for(int s = 0; s<26; s++)
        {
            if(char_global_min_count[char('a' + s)]>0)
            {
                string s1(1, char('a' + s));
                for(int k=0;k<char_global_min_count[char('a' + s)];k++)
                    v.push_back(s1);
            }         
        }
        return v;
    }

private:
    vector<string> v;
    map<char, int> local_min()
    {
        map<char, int> char_local_min_count;
        for(int s = 0; s<26; s++)
        {
            //cout<<char('a' + s)<<endl; //依次输出26个字母
            char temp = 'a' + s;
            //初始化字母局部最少次数字典，均赋值为0
            char_local_min_count[temp] = 0;
        }
        return char_local_min_count;
    }

    map<char, int> global_min()
    {
        map<char, int> char_global_min_count;
        for(int s = 0; s<26; s++)
        {
            //cout<<char('a' + s)<<endl; //依次输出26个字母
            char temp = 'a' + s;
            //初始化字母全局最少次数字典，均赋值为最大数
            char_global_min_count[temp] = INT_MAX;
        }
        return char_global_min_count;
    }
};


int main()
{
    map<char, int> char_global_min_count;
    map<char, int> char_local_min_count;
    /*
    for(int i = 0; i<26; i++)
    {
        //cout<<char('a' + i)<<endl; //依次输出26个字母
        char temp = 'a' + i;
        //初始化字母全局最少次数以及字母局部最少次数，均赋值为最大数
        char_global_min_count[temp] = INT_MAX;
        char_local_min_count[temp] = INI_MAX;
    }
    */
    string s1 = "cool";
    string s2 = "lock";
    string s3 = "cook";
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    Solution s;
    vector<string> v_ = s.commonChars(v);
    cout<<v_.size();
    for(int i=0;i<v_.size();i++)
        cout<<v_[i]<<endl;

    /*
    for(map<char, int>::iterator it=char_global_min_count.begin();it!=char_global_min_count.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    */
    return 0;
}
```



#### 1006.笨阶乘

通常，正整数 n 的阶乘是所有小于或等于 n 的正整数的乘积。例如，factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1。

相反，我们设计了一个笨阶乘 clumsy：在整数的递减序列中，我们以一个固定顺序的操作符序列来依次替换原有的乘法操作符：乘法(*)，除法(/)，加法(+)和减法(-)。

例如，clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1。然而，这些运算仍然使用通常的算术运算顺序：我们在任何加、减步骤之前执行所有的乘法和除法步骤，并且按从左到右处理乘法和除法步骤。

另外，我们使用的除法是地板除法（floor division），所以 10 * 9 / 8 等于 11。这保证结果是一个整数。

实现上面定义的笨函数：给定一个整数 N，它返回 N 的笨阶乘。

```c++
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        s.push(N);
        N--;
        int index = 0;
        
        while(N>0)
        {
            if(index%4==0)
                s.top() *= N;
            else if(index%4==1)
                s.top() /= N;
            else if(index%4==2)
                s.push(N);
            else
                s.push(-N);
            index++;
            N--;
        }
        
        //对栈中元素求和
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
}
private:
    stack<int> s;
};
```



#### 1011.在D天内送达包裹的能力

传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

```c++
#include<iostream>
#include<vector>

using namespace std;

//超出时间限制，77/84个通过测试用例
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int start = Max(weights);//下限是数组中最大元素，假设每个货物都要花一天搬运
        int end = Sum(weights);//上限是数组中元素的和，假设所有货物一天之内搬完
        //遍历查找下限到上限之间承重重量
        for(int i = start;i<=end;i++)
            if(Day(weights, i)<=D)
                return i;
        return end;
    }
private:
    int Max(vector<int> v)
    {
        int result = INT_MIN;
        for(int i=0;i<v.size();i++)
            result = max(result, v[i]);
        return result;
    }
    int Sum(vector<int> v)
    {
        int result = 0;
        for(int i=0;i<v.size();i++)
            result += v[i];
        return result;
    }
    //判断船承重I时，最少需要多少天搬运完
    int Day(vector<int> v, int I)
    {
        int cur = 0;
        int day = 0;
        for(int i=0;i<v.size();i++)
        {
            if(cur+v[i]<=I)
                cur = cur+v[i];
            else
            {
                cur = v[i];//重新开始新的一天
                day++;
            }
        }
        return day+1;
    }
};

//使用二分法查找符合条件的船承重
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int start = Max(weights);//下限是数组中最大元素，假设每个货物都要花一天搬运
        int end = Sum(weights);//上限是数组中元素的和，假设所有货物一天之内搬完
        //二分查找下限到上限之间承重重量
        while(start<end)
        {
            int mid = (start+end)/2;
            if(Day(weights, mid)<=D)
                end = mid;
            else
                start = mid + 1;
        }
        return end;
    }
private:
    int Max(vector<int> v)
    {
        int result = INT_MIN;
        for(int i=0;i<v.size();i++)
            result = max(result, v[i]);
        return result;
    }
    int Sum(vector<int> v)
    {
        int result = 0;
        for(int i=0;i<v.size();i++)
            result += v[i];
        return result;
    }
    //判断船承重I时，最少需要多少天搬运完
    int Day(vector<int> v, int I)
    {
        int cur = 0;
        int day = 0;
        for(int i=0;i<v.size();i++)
        {
            if(cur+v[i]<=I)
                cur = cur+v[i];
            else
            {
                cur = v[i];//重新开始新的一天
                day++;
            }
        }
        return day+1;
    }
};
```



#### 1030.距离顺序排列矩阵单元格

给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。另外，在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。（可以按任何满足此条件的顺序返回答案。）

```c++
//注意vector<int>的几种初始化方法;
//(1)vector<int> v(n);//v中有n个元素，默认为0；
//(2)vector<int> v(n,1);//v中有n个元素，全为1；
//(3)vector<int> v{2};//v中有一个元素，为2；
//(4)vector<vector<int>> v;
//v.push_back({i,j});//一次性进一个vector数组{i,j}；
//(5)vector<vector<int>> v(n);//v中有n个二维数组，不过没有赋值，可以使用push_back进行赋值

#include<iostream>
#include<vector>

using namespace std;

//解法一、改写sort函数直接排序
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                vector<int> tmp_v;
                tmp_v.push_back(i);
                tmp_v.push_back(j);
                result.push_back(tmp_v);
            }
        sort(result.begin(), result.end(), [&](vector<int> x,vector<int> y){
            return abs(x[0]-r0)+abs(x[1]-c0)<abs(y[0]-r0)+abs(y[1]-c0);
        });
        return result;
    }
};


//解法二、桶排序，根据距离分桶
class Solution {
public:
    int dist(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<vector<int>>> bucket(maxDist + 1);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int d = dist(i, j, r0, c0);
                vector<int> tmp = {i, j};
                bucket[d].push_back(tmp);
            }
        }
        vector<vector<int>> ret;
        for (int i = 0; i <= maxDist; i++) {
            for (auto &it : bucket[i]) {
                ret.push_back(it);
            }
        }
        return ret;
    }
};




int main()
{
    int n = 4;
    vector<int> v(n);
    vector<vector<int>> v2(n);
    v.push_back(3);
    v2[0].push_back(9);
    for(int i=0;i<v2.size();i++)
        cout<<v2[i].size()<<endl;
    return 0;
}
```



#### 1035.不相交的线

在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足： nums1[i] == nums2[j]，且绘制的直线不与任何其他连线（非水平线）相交。请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。以这种方法绘制线条，并返回可以绘制的最大连线数。

```c++
#include<iostream>
#include<vector>

using namespace std;

//最长公共子序列长度的解法
//dp[i][j]表示nums1[0]~nums1[i-1]与nums2[0]~nums[j-1]之间不相交的连线个数
//状态转移方程和最长公共子序列一样
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};
```





#### 1122.数组的相对排序

给你两个数组，arr1 和 arr2：

（1）arr2 中的元素各不相同；
（2）arr2 中的每个元素都出现在 arr1 中；
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

```c++
//修改sort函数，使用一个map记录arr2中各元素以及对应的索引
//根据这个索引来排序，不在这个map中的，按照值进行升序排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> arr2_map;
        for(int i=0;i<arr2.size();i++)
            arr2_map[arr2[i]] = i;
        sort(arr1.begin(),arr1.end(),[&](int x, int y){
            if(arr2_map.count(x))
                return arr2_map.count(y)?arr2_map[x]<arr2_map[y]:true;
            else
                return arr2_map.count(y)?false:x<y;
        });
        return arr1;
    }
};
```



#### 1143.最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

```c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};
```



#### 1190.反转每对括号间的子串

给出一个字符串 s（仅含有小写英文字母和括号）。请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。注意，您的结果中 不应 包含任何括号。

```c++
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int size = s.size();
        stack<char> stk;
        for(int i=0;i<size;i++)
        {
            if(s[i]!=')')
                stk.push(s[i]);
            else
            {
                string tmp = "";
                while(stk.top()!='(')
                {
                    tmp += stk.top();
                    stk.pop();
                }
                stk.pop();//删除'('
                //此时tmp已经是反转后的结果，不需要再使用reverse
                //reverse(tmp.begin(), tmp.end());
                for(int j=0;j<tmp.size();j++)
                    stk.push(tmp[j]);
            }
        }
        string result = "";
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```



#### 1207.独一无二的出现次数

给你一个整数数组 `arr`，请你帮忙统计数组中每个数的出现次数。如果每个数的出现次数都是独一无二的，就返回 `true`；否则返回 `false`。

```c++
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<set>

using namespace std;

//使用标记数组vector<int> flag来记录次数是否重复
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int length = arr.size();
        vector<int> flag(length,0);//记录每个数出现的次数是否重复
        map<int, int> count_map;
        //遍历原数组，记录每个元素出现的次数
        for(int i=0;i<length;i++)
            count_map[arr[i]]++;
        //遍历次数map，查找是否有数出现的次数相同
        for(map<int,int>::iterator it = count_map.begin();it!=count_map.end();it++)
        {
            if(flag[it->second]==0)
                flag[it->second] = 1;
            else
                return false;
        }
        return true;
    }
};


//使用set来记录次数，再比较set和map的长度，如果相同，说明没有重复
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int length = arr.size();
        map<int, int> count_map;
        set<int> times;
        //遍历原数组，记录每个元素出现的次数
        for(int i=0;i<length;i++)
            count_map[arr[i]]++;
        //遍历次数map，查找是否有数出现的次数相同
        for(map<int,int>::iterator it = count_map.begin();it!=count_map.end();it++)
            times.insert(it->second);
        //如果map和set的长度相同，说明没有重复的元素
        if(times.size()==count_map.size())
            return true;
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    bool flag = s.uniqueOccurrences(v);
    cout<<endl<<flag<<endl;
    return 0;
}
```



#### 1269.停在原地的方案数

有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

```c++
#include<iostream>
#include<vector>

using namespace std;

//动态规划
//dp[i][j]表示i步后，指针在位置j的方案数，则0<=i<=step,0<=j<=min(arrLen-1,step),因为step后j最多到step位置
//根据题意有动态转移方程：dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]
//边界条件：dp[0][0] = 1,dp[0][j] = 0,j=1,...,min(arrLen-1,step)
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int column = min(arrLen-1, steps);
        vector<vector<int>> dp(steps+1, vector<int>(column+1));
        dp[0][0] = 1;
        for(int i=1;i<=steps;i++)
            for(int j=0;j<=column;j++)
            {
                //dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];//直接相加可能会出现j-1,j+1出界的情况，需要条件判断
                dp[i][j] = dp[i-1][j];
                if(j-1>=0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % 1000000007;
                if(j+1<=column)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % 1000000007;
            }
        return dp[steps][0];
    }
};

//考虑到动态转移方程只涉及其中两行，可以优化内存空间
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int column = min(arrLen-1, steps);
        vector<int> dp(column+1);
        dp[0] = 1;
        for(int i=1;i<=steps;i++)
        {
            vector<int> dp_next(column+1);
            for(int j=0;j<=column;j++)
            {
                dp_next[j] = dp[j];
                if(j-1>=0)
                    dp_next[j] = (dp_next[j] + dp[j-1]) % 1000000007;
                if(j+1<=column)
                    dp_next[j] = (dp_next[j] + dp[j+1]) % 1000000007;
            }
            dp = dp_next;//vector<int>之间可以直接赋值
        }
        return dp[0];
    }
};


```



#### 1310.子数组异或查询

有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。并返回一个包含给定查询 queries 所有结果的数组。

```c++
#include<iostream>
#include<vector>

using namespace std;

//模拟题意,41/42个通过测试用例，超时
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int tmp = 0;
            for(int j = start;j<=end;j++)
                tmp ^= arr[j];
            result.push_back(tmp);
        }
        return result;
    }
};

//Q(left,right)=arr[left]⊕…⊕arr[right]
//=(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[left−1])⊕(arr[left]⊕…⊕arr[right])
//=(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[right])
//=xors[left]⊕xors[right+1]
//只需计算数组xors即可，其中xors[0]=0;xors[i]=arr[0]⊕arr[1]⊕...⊕arr[i-1]
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //构建xors数组
        vector<int> xors(arr.size()+1);
        xors[0] = 0;
        for(int i=1;i<=arr.size();i++)
            xors[i] = xors[i-1]^arr[i-1];
        
        //计算查询结果
        vector<int> result;
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            result.push_back(xors[start]^xors[end+1]);
        }
        return result;
    }
};
```



#### 1356.根据数字二进制下1的数目排序

给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。请返回排序后的数组。

```c++
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
```



#### 1365.有多少小于当前数字的数字

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。以数组形式返回答案。

```c++
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
```



#### 1370.上升下降字符串

给你一个字符串 s ，请你根据下面的算法重新构造字符串：

```
1.从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
2.从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
3.重复步骤 2 ，直到你没法从 s 中选择字符。
4.从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
5.从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
6.重复步骤 5 ，直到你没法从 s 中选择字符。
重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
```

请返回将 s 中字符重新排序后的结果字符串。

```c++
//使用一个数组来对字符串s中各个字母的个数进行计数
//这里不使用map，因为map不便于从前往后，再从后往前遍历

class Solution {
public:
    string sortString(string s) {
        if(s.length()==0)
            return s;
        vector<int> count(26);//存储对应的字符的个数
        //统计次数
        for(int i=0;i<s.length();i++)
            count[s[i]-'a']++;
        
        string result;
        while(result.length()<s.length())
        {
            for(int i=0;i<26;i++)
                if(count[i])
                {
                    result.push_back(i+'a');//string可以直接通过push_back来得到char
                    count[i]--;
                }

            for(int i=25;i>=0;i--)
                if(count[i])
                {
                    result.push_back(i+'a');
                    count[i]--;
                }
        }
        return result;
    }
};
```



#### 1411.[给 N x 3 网格图涂色的方案数](https://leetcode-cn.com/problems/number-of-ways-to-paint-n-3-grid/)

你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。给你网格图的行数 n 。请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。

递归公式推导：

我们把满足要求的type都写出来，一共有 1212 种：

010, 012, 020, 021, 101, 102, 120, 121, 201, 202, 210, 212
我们可以把它们分成两类：

ABC 类：三个颜色互不相同，一共有 66 种：012, 021, 102, 120, 201, 210；

ABA 类：左右两侧的颜色相同，也有 66 种：010, 020, 101, 121, 202, 212。

这样我们就可以把 1212 种type浓缩成了 22 种，尝试写出这两类之间的递推式。我们用 f[i][0]f[i][0] 表示 ABC 类，f[i][1]f[i][1] 表示 ABA 类。在计算时，我们可以将任意一种满足要求的涂色方法带入第 i - 1 行，并检查第 i 行的方案数，这是因为同一类的涂色方法都是等价的：

第 i - 1 行是 ABC 类，第 i 行是 ABC 类：以 012 为例，那么第 i 行只能是120 或 201，方案数为 22；

第 i - 1 行是 ABC 类，第 i 行是 ABA 类：以 012 为例，那么第 i 行只能是 101 或 121，方案数为 22；

第 i - 1 行是 ABA 类，第 i 行是 ABC 类：以 010 为例，那么第 i 行只能是 102 或 201，方案数为 2；

第 i - 1 行是 ABA 类，第 i 行是 ABA 类：以 010 为例，那么第 i 行只能是 101，121 或 202，方案数为 3。

因此我们就可以写出递推式：
$$
\begin{cases} f[i][0] = 2 * f[i - 1][0] + 2 * f[i - 1][1] \\ f[i][1] = 2 * f[i - 1][0] + 3 * f[i - 1][1] \end{cases}
$$

```c++
#include<iostream>
#include<math.h>


class Solution
{
public:
    int numOfWays(int n) {
        long fi0 = 6;
        long fi1 = 6;
        for(int i=2;i<=n;i++)
        {
            long new_fi0 = (2*fi0 + 2*fi1) % mod;//这里必须是long，当n很大时，int无法表示
            long new_fi1 = (2*fi0 + 3*fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }
        return (fi0+fi1) % mod;   
    }
private:
    int mod = pow(10,9) + 7;
};
```



#### 1442.形成两个异或相等数组的三元组数目

给你一个整数数组 arr 。

现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。

a 和 b 定义如下：

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。

请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//考虑前缀和数组XOR
//XOR[0]=0;XOR[i]=arr[0]⊕arr[1]⊕...⊕arr[i-1]
//XOR[j]=arr[0]⊕arr[1]⊕...⊕arr[j-1]
//XOR[k+1]=arr[0]⊕arr[1]⊕...⊕arr[k]
//a=arr[i]⊕...⊕arr[j-1]=XOR[i]⊕XOR[j]
//b=arr[j]⊕...⊕arr[k]=XOR[j]⊕XOR[k+1]
//若a=b，即XOR[i]⊕XOR[j]=XOR[j]⊕XOR[k+1]，即XOR[i]=XOR[k+1]，当该式成立时，[i+1,k]的范围内的任意j都是符合要求的，对应的三元组个数为k-i


//双循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        vector<int> XOR(size+1);
        for(int i=0;i<size;i++)
            XOR[i+1]=XOR[i]^arr[i];
        int count = 0;
        for(int i=0;i<size;i++)
            for(int k=i+1;k<size;k++)
            {
                if(XOR[i]==XOR[k+1])
                    count += k-i;
            }
        return count;
    }
};

//一次for循环，对于下标k，若下标i=i1,i2,...,im（均小于k）时，都有XOR[i]=XOR[k+1]，
//根据上面的分析，这些二元组对答案的贡献为(k-i1)+(k-i2)+...+(k-im)=m*k - (i1+i2+...+im)
//在遍历下标k时，需要知道下标小于k的XOR中满足XOR[i]=XOR[k+1]的下标i的出现次数以及下标i之和
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] ^ arr[i];
        }
        map<int, int> cnt, total;
        
        int ans = 0;
        //记录s[k]出现的次数和下标之和，由于i一定小于k，所以可以一次for循环，在遍历k时查找cnt中是否有s[k+1]即可
        for (int k = 0; k < n; ++k)
        {
            //if语句要写在下面cnt和total计算之前，因为当k=0时，不会有满足题意的i，所以这时一定不能计数
            if (cnt.count(s[k + 1]))
            {
                ans += cnt[s[k + 1]] * k - total[s[k + 1]];
            }
            cnt[s[k]]++;
            total[s[k]] += k;
        }          
        return ans;
    }
};
```



#### 1486.数组异或操作

给你两个整数，n 和 start 。数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。请返回 nums 中所有元素按位异或（XOR）后得到的结果。

```c++
#include<iostream>

using namespace std;

//模拟思路
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for(int i=0;i<n;i++)
        {
            result ^= start + 2*i;
        }
        return result;
    }
};

//数学(官方题解)

```



#### 1603.设计停车系统

请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。

请你实现 ParkingSystem 类：ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem 类，三个参数分别对应每种停车位的数目。
bool addCar(int carType) 检查是否有 carType 对应的停车位。 carType 有三种类型：大，中，小，分别用数字 1， 2 和 3 表示。一辆车只能停在  carType 对应尺寸的停车位中。如果没有空车位，请返回 false ，否则将该车停入车位并返回 true 。

```c++
#include<iostream>

using namespace std;

class ParkingSystem
{
public:
    // int b = 0;
    // int m = 0;
    // int s = 0;
    ParkingSystem(int big, int medium, int small)
    {
        b = big;
        m = medium;
        s = small;
    }

    bool addCar(int catType)
    {
        if(catType==1)
            if(b>0)
            {
                b--;
                return true;
            }
            else
                return false;
        else if(catType==2)
            if(m>0)
            {
                m--;
                return true;
            }
            else
                return false;
        else
            if(s>0)
            {
                s--;
                return true;
            }
            else
                return false;
    }
private:
    int b = 0;
    int m = 0;
    int s = 0;
};

int main()
{
    ParkingSystem P(1, 1, 0);
    cout<<P.addCar(1)<<endl;
    return 0;
}
```



#### 1720.解码异或后的数组

未知 整数数组 arr 由 n 个非负整数组成。经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1] 。例如，arr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。请解码返回原数组 arr 。可以证明答案存在并且是唯一的。

```c++
#include<iostream>
#include<vector>

using namespace std;

//思路：利用异或运算性质
//encoded[i] = arr[i] XOR arr[i+1]
//两边同时异或arr[i]：
//encoded[i] XOR arr[i] = arr[i] XOR arr[i+1] XOR arr[i] = arr[i+1]
//arr[i+1] = encoded[i] XOR arr[i]
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size();
        vector<int> arr(size+1);
        arr[0] = first;
        for(int i=1;i<size+1;i++)
            arr[i] = arr[i-1]^encoded[i-1];
        return arr;
    }
};
```



#### 1734.解码异或后的排列

给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。

```c++
#include<iostream>
#include<vector>

using namespace std;

//思路：和leetcode1720类似，只需求得原数组第一个元素即可解码原数组所有的元素
//total = perm[0]^perm[1]^perm[2]^...^perm[n-1]=1^2^3^...^n,n是奇数,容易计算total的值
//total = perm[0]^(perm[1]^perm[2])^(perm[3]^perm[4])^...^(perm[n-2]^perm[n-1])，由于n是奇数，total可以写成成对异或的写法
//total = perm[0]^encoded[1]^encoded[3]^...^encoded[n-2],encoded是已知的，可以求得perm[0]的值。
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total = 0;
        for(int i=1;i<=encoded.size()+1;i++)
            total ^= i;
        int result_1_n = calculate(encoded);
        vector<int> result(encoded.size()+1);
        result[0] = total ^ result_1_n;
        for(int i=1;i<result.size();i++)
            result[i] = result[i-1] ^ encoded[i-1];
        return result;
    }
private:
    int calculate(vector<int> encoded)
    {
        int result_1_n = 0;
        for(int i=1;i<encoded.size();i=i+2)
            result_1_n ^= encoded[i];
        return result_1_n;
    }
};
```



#### 1738.找出第K大的异或坐标值

给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。矩阵中坐标 (a, b) 的 值 可由对所有满足 $0\leq i\leq a<m$ 且 $0\leq j\leq b<n$ 的元素 $matrix[i][j]$（下标从 0 开始计数）执行异或运算得到。请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。

```c++
#include<iostream>
#include<vector>

using namespace std;

//二维前缀和数组，XOR[i+1][j+1]=(matrix[0][0]^matrix[0][1]^...^matrix[0][j])
//                            ^(matrix[1][0]^matrix[1][1]^...^matrix[1][j])
//                            ^...
//                            ^(matrix[i][0]^matrix[i][1]^...^matrix[i][j])
//XOR[i+1][j+1]=XOR[i][j]^XOR[i+1][j]^XOR[i][j+1]^matrix[i][j]
//在上面的递推式中，XOR[i][j]所在区域的元素被异或3次（XOR[i+1][j],XOR[i][j+1]以及XOR[i][j]本身），异或两次结果为0，所以最终的结果相当于只异或了一次
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> XOR(m+1, vector<int>(n+1));
        vector<int> result;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                XOR[i+1][j+1] = XOR[i][j]^XOR[i+1][j]^XOR[i][j+1]^matrix[i][j];
                result.push_back(XOR[i+1][j+1]);
            }
        //从小到大排序，再返回第result.size()-k+1个元素，或者直接从大到小排序返回第k个元素
        //sort(result.begin(), result.end(), greater<int>()); //从大到小排序
        //return result[k-1]
        //sort(result.begin(), result.end());
        //return result[result.size()-k];

        //使用快排函数nth_element
        //应用的范围由它的第一个和第三个参数指定。第二个参数是一个指向第 n 个元素的迭代器。
        //nth_dement() 的执行会导致第 n 个元素被放置在适当的位置。
        //这个范围内，在第 n 个元素之前的元素都小于第 n 个元素，而且它后面的每个元素都会比它大(n个元素两边都未必有序)。
        //算法默认用 < 运算符来生成这个结果，想从大到小排列，增加greater<int>()即可。
        nth_element(result.begin(), result.begin()+k-1, result.end(), greater<int>());
        return result[k-1];
    }
};
```

