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



#### 3.无重复字符的最长子串

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长子串** 的长度。

```c++
#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

//双循环，超时通过900/987
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;//返回的长度
        int size = s.size();
        for(int i=0;i<size;i++)
            for(int j=i;j<size;j++)
            {
                string tmp = s.substr(i,j-i+1);
                if(Isfit(tmp))
                    result = max(result, j-i+1);
            }
        return result;
    }
private:
    bool Isfit(string tmp)
    {
        //判断字符串tmp是否重复
        map<char, int> count;
        for(int i=0;i<tmp.size();i++)
        {
            count[tmp[i]]++;
            if(count[tmp[i]]>1)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        set<char> occ;
        int n = s.size();
        // 右指针，初始值为 0，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = 0, ans = 0;
        // 枚举左指针的位置，初始值为0
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk < n && !occ.count(s[rk])) {
                // 不断地移动右指针
                occ.insert(s[rk]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串，不包括rk
            ans = max(ans, rk - i);
        }
        return ans;
    }
};
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



#### 14.最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

 

**示例 1：**

```
输入：strs = ["flower","flow","flight"]
输出："fl"
```

**示例 2：**

```
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
```

```c++
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size==0)
            return "";
        if(size==1)
            return strs[0];
        string str = strs[0];
        for(int i=1;i<size;i++)
            str = longestCommonPrefix_for_two(str, strs[i]);
        return str;
    }
private:
    string longestCommonPrefix_for_two(string str1, string str2)
    {
        int size1 = str1.size();
        int size2 = str2.size();
        int size = size1<size2?size1:size2;
        for(int i=0;i<size;i++)
        {
            if(str1[i]!=str2[i])
                return str1.substr(0, i);
        }
        return size1<size2?str1:str2;
    }
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



#### 20.有效的括号

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

```c++
#include<iostream>
#include<string>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //哈希表
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        
        // map<char, char> m = {
        //     {')', '('},
        //     {']', '['},
        //     {'}', '{'}};

        int size = s.size();
        // cout<<size<<endl;
        if(size%2==1)
            return false;
        stack<char> stk;
        for(int i=0;i<size;i++)
        {
            if(stk.empty())
                stk.push(s[i]);
            else
            {
                if(m.count(s[i]))
                {
                    if(stk.top()==m[s[i]])
                        stk.pop();
                    else
                        return false;//如果s[i]是右括号且当前栈顶
                                     //元素不是相应的左括号，则返回false
                }
                else
                    stk.push(s[i]);
            }
        }

        return stk.empty();
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



#### 36.有效的数独

请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。

![36](E:\donkey\Documents\Computer_Algorithm\img\leetcode\36.png)

```c++
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true
```



```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9,0));//rows[i][index]表示board第i行数index+1出现的次数
        vector<vector<int>> columns(9, vector<int>(9,0));//columns[j][index]表示board第j列数index+1出现的次数
        //subboxes[i][j][index]表示board(i,j)处的子九宫格中，数index+1出现的次数
        vector<vector<vector<int>>> subboxes(3, vector<vector<int>>(3, vector<int>(9, 0)));
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                char c = board[i][j];
                if(c!='.')
                {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i/3][j/3][index]++;
                    if(rows[i][index]>1||columns[j][index]>1||subboxes[i/3][j/3][index]>1)
                        return false;
                }
            }
        return true;
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



#### 41.缺失的第一个正数

给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。


示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //对于遍历到的数x=nums[i]，如果x属于[1,n]，则交换nums[i]和nums[x-1]
        //如果交换后，nums[i]仍然属于[1,n]，则继续交换，直到nums[i]不属于[1,n]
        //同时防止死循环，应当保证交换的两个数不相等，即nums[x-1]!=nums[i]
        //如果都不符合上述条件，则跳出交换循环，遍历下一个数
        for(int i=0;i<n;i++)
        {
            //int x = nums[i];
            //如果x在[1,n]中且nums[x-1]!=x，则将x换到x-1位置上
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1], nums[i]);
        }
        //从头遍历，看那个位置上的值nums[i]!=i+1，则是没有出现的最小正数
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
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



#### 43.字符串相乘

给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。

```c++
#include<iostream>
#include<string>

using namespace std;

//拆分字符串求解，如"123"可以看成1*10^2+2*10^1+3*10^0
//两个字符串相乘，分别拆分多个数相加的的情形，然后根据10的次数进行对应数组位置值的计算
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m+n, 0);
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int exp = m-1-i+n-1-j;//10的次数
                result[exp] += a*b;//按照10的次数将乘积加到数组对应的位置上
            }
        }
        //扫描数组，计算每位的进位数
        for(int index=0;index<m+n-1;index++)
        {
            int flag = result[index]/10;
            result[index] %= 10;
            result[index+1] += flag;
        }
        //整合字符串
        string str = "";
        bool zero = false;//从后往前，遇到一个不为零的则将zero设置为true
        for(int index=m+n-1;index>=0;index--)
        {
            if(result[index]!=0)
                zero = true;
            if(zero)
                str += to_string(result[index]);
            //如果遍历到result第一位仍然是0，则最终结果为0
            if(index==0&&zero==false)
                str = "0";
        }
        return str;
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



#### 49.字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。可以按任意顺序返回结果列表。字母异位词指字母相同，但排列不同的字符串。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

```c++
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string str_tmp = strs[i];
            sort(str_tmp.begin(), str_tmp.end());
            m[str_tmp].push_back(strs[i]);
        }
        
        //输出map中的分组结果
        vector<vector<string>> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second);
        }
        return v;
    }
};
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
            vector<int> cur_interval = intervals[i];
            //如果当前区间在新区间的左侧，直接插入当前区间
            if(cur_interval[1]<left)
                ans.push_back(cur_interval);
            //如果当前区间在新区间右侧，需要先判断新区间是否已经插入了，如果不判断，会导致新区间重复插入
            //如果没插入，则插入新区间，且将flag置为true，再插入当前区间即可
            //如果已经插入，直接插入当前区间即可
            else if(cur_interval[0]>right)
            {
                if(!flag)
                {
                    ans.push_back({left,right});
                    flag = true;
                }
                ans.push_back(cur_interval);
            }
            //如果新区间和当前区间有交集，则将新区间更新为和当前区间的并集
            else
            {
                left = min(left,cur_interval[0]);
                right = max(right, cur_interval[1]);
            }
        }
        //最后再判断新区间是否已经插入了，如果还没有插入，则将新区间插到最后一个位置
        if(!flag)
            ans.push_back({left,right});
        return ans;
    }
};
```



#### 58.最后一个单词的长度

给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

示例 1：

```c+=
输入：s = "Hello World"
输出：5
```

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while(s[index]==' ')
            index--;
        int result = 0;
        while(index>=0&&s[index]!=' ')
        {
            index--;
            result++;
        }
        return result;
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



#### 62.不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。问总共有多少条不同的路径？

示例 1：


输入：m = 3, n = 7
输出：28
示例 2：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
示例 3：

输入：m = 7, n = 3
输出：28
示例 4：

输入：m = 3, n = 3
输出：6

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示从(0,0)到(i,j)的路径数
//dp[i][j] = dp[i-1][j]+dp[i][j-1]
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n,0));
//         for(int i=0;i<m;i++)
//             dp[i][0] = 1;
//         for(int j=0;j<n;j++)
//             dp[0][j] = 1;
//         for(int i=1;i<m;i++)
//             for(int j=1;j<n;j++)
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
//         return dp[m-1][n-1];
//     }
// };


//递推只涉及到相邻两行或两列的状态，可以使用滚动数组优化
//dp_row表示dp每一行的状态
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp_row(n,0);
        //边界条件
        for(int j=0;j<n;j++)
            dp_row[j] = 1;

        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(j>0)
                    dp_row[j] += dp_row[j-1];
            }
        
        return dp_row[n-1];
    }
};
```



#### 63.不同路径II

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

```
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
```

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示从(0,0)到(i,j)的路径数
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));
//         //边界条件,如果其中有一个障碍，则后续路径数均为0
//         for(int i=0;i<m;i++)
//         {
//             if(obstacleGrid[i][0]==0)
//                 dp[i][0] = 1;
//             else
//                 break;
//         }
//         for(int j=0;j<n;j++)
//         {
//             if(obstacleGrid[0][j]==0)
//                 dp[0][j] = 1;
//             else
//                 break;
//         }

//         for(int i=1;i<m;i++)
//             for(int j=1;j<n;j++)
//             {
//                 if(obstacleGrid[i][j]==1)
//                     dp[i][j] = 0;
//                 else
//                 {
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                 }
//             }
        
//         return dp[m-1][n-1];
//     }
// };


//递推只涉及到相邻两行或两列的状态，可以使用滚动数组优化
//dp_row表示dp每一行的状态
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n,0));
        vector<int> dp_row(n,0);
        dp_row[0] = (obstacleGrid[0][0]==0);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp_row[j] = 0;
                if(j>0&&obstacleGrid[i][j]==0)
                {
                    dp_row[j] += dp_row[j-1];
                }
            }
        
        return dp_row[n-1];
    }
};
```



#### 64.最小路径和

给定一个包含非负整数的 $m*n$ 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明：**每次只能向下或者向右移动一步。

```c++
#include<iostream>
#include<vector>

using namespace std;


//dp[i][j]表示从[0,0]->[i,j]的最短路径和
//dp[i][j]=min{dp[i-1][j],dp[i][j-1]} + matrix[i][j]
class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int sum = 0;
        //给第一行赋值
        for(int i = 0;i<m;i++)
        {
            sum += matrix[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        //给第一列赋值
        for(int j=0;j<n;j++)
        {
            sum += matrix[0][j];
            dp[0][j] = sum;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + matrix[i][j];
        return dp[m-1][n-1];
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
            //使用第i个字符进行编码
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            //使用第i个和第i-1个字符进行编码
            if(i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10+s[i-1]-'0'<=26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
```



#### 97.交错字符串

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

示例 1：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
示例 2：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
示例 3：

输入：s1 = "", s2 = "", s3 = ""
输出：true

```c++
// @lc code=start
#include<iostream>
#include<string>
#include<vector>

using namespace std;


//使用动态规划求解：dp[i][j]表示s1的前i个字符和s2的前j个字符能否交错组成s3的前i+j个字符
//dp[0][0] = 1
//当s1[i]==s3[i+j]时，dp[i][j] = dp[i-1][j];
//当s2[j]==s3[i+j]时，dp[i][j] = dp[i][j-1];
//故dp[i][j]=dp[i][j]|dp[i-1][j]|dp[i][j-1];
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int size1 = s1.size();
//         int size2 = s2.size();
//         int size3 = s3.size();
//         if(size1+size2!=size3)
//             return false;
//         // if(size1==0&&size2==0)
//         //     return true;
//         // if(size1==0)
//         //     return s2==s3;
//         // if(size2==0)
//         //     return s1==s3;
//         vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
//         dp[0][0] = 1;
//         for(int i=0;i<=size1;i++)
//         {
//             for(int j=0;j<=size2;j++)
//             {
//                 if(i>0)
//                     dp[i][j] |= dp[i-1][j]&&(s1[i-1]==s3[i+j-1]);
//                 if(j>0)
//                     dp[i][j] |= dp[i][j-1]&&(s2[j-1]==s3[i+j-1]);
//             }
//         }
//         return dp[size1][size2];

//     }
// };


//考虑到该递推公式每次只涉及到两行或两列，故可以使用一个一维数组来进行递推
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int size1 = s1.size();
//         int size2 = s2.size();
//         int size3 = s3.size();
//         if(size1+size2!=size3)
//             return false;
//         vector<int> dp_row(size2+1, 0);//表示原始二维数组dp每一行的状态
//         dp_row[0] = 1;
//         for(int i=0;i<=size1;i++)
//             for(int j=0;j<=size2;j++)
//             {
//                 if(i>0)
//                     dp_row[j] &= s1[i-1]==s3[i+j-1];//首先利用上一行的dp_row[j]更新状态
//                 if(j>0)
//                     dp_row[j] |= dp_row[j-1]&&(s2[j-1]==s3[i+j-1]);//再利用当前行的dp_row[j-1]更新状态    
//             }
//         return dp_row[size2];
//     }
// };


//同样可以按照列状态来递推
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if(size1+size2!=size3)
            return false;
        vector<int> dp_col(size1+1, 0);//表示原始二维数组dp每一列的状态
        dp_col[0] = 1;
        for(int j=0;j<=size2;j++)
            for(int i=0;i<=size1;i++)
            {
                if(j>0)
                    dp_col[i] &= s2[j-1]==s3[i+j-1];//首先利用前一列的dp_col[i]更新状态
                if(i>0)
                    dp_col[i] |= dp_col[i-1]&&(s1[i-1]==s3[i+j-1]);//再利用当前列的dp_col[i-1]更新状态    
            }
        return dp_col[size1];
    }
};

// @lc code=end
```





#### 100.相同的树

给你两棵二叉树的根节点 `p` 和 `q` ，编写一个函数来检验这两棵树是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

```c++
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)
            return true;
        else if(p==nullptr||q==nullptr)
            return false;
        else
            return (p->val==q->val)&&isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
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

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。你只能选择 某一天 买入这只股票，并选择在未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

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

给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

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

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

```c++
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

//动态规划
//dp[k][i]表示在第i天结束后，经过k次交易(买入且卖出算一次交易)的收益

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

//一般思路：
//dp[k][i]表示前i天交易k次的最大收益

//百度面试的时候给了个更简单的方法，把卖出和买入分开计算，即共有2k次操作：
//dp[k][i] = max(dp[k][i-1], max_j(v[i]-v[j]+dp[k-1][j]))
//买
//dp[k][i] = max(dp[k][i-1], -v[i]+dp[k-1][j]))
//卖
//dp[k][i] = max(dp[k][i-1], v[i]+dp[k-1][j]))


int fun(vector<int> v, int k)
{
    int size = v.size();
    vector<vector<int>> dp(2*k+1, vector<int>(size+1,INT_MIN));
    
    for(int count=1;count<=2*k;count++)
        for(int i=1;i<=size;i++)
        {
            if(count%2==1)
                dp[count][i] = max(dp[count][i-1], -v[i]+dp[count-1][i]);
            else
                dp[count][i] = max(dp[count][i-1], v[i]+dp[count-1][i]);
        }
    return dp[2*k][size];
}

```



#### 124.二叉树中的最大路径和

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。给你一个二叉树的根节点 root ，返回其 最大路径和 

```c++
class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
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



#### 138.复制带随机指针的链表

给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。

```c++
#include<iostream>
#include<map>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        if(Cache_Node.count(head)==0)
        {
            Node* new_head = new Node(head->val);
            Cache_Node[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        return Cache_Node[head];
        
    }
private:
    map<Node*, Node*> Cache_Node;
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



#### 144.二叉树的前序遍历

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



#### 160.相交链表

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。

```c++
#include<iostream>
#include<map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

//哈希表存储节点，判断节点出现次数
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return nullptr;
        map<ListNode*, int> node;
        ListNode* curA = headA;
        while(curA)
        {
            node[curA]++;
            curA = curA->next;
        }
        
        ListNode* curB = headB;
        while(curB)
        {
            if(node.count(curB))
                return curB;
            else
                node[curB]++;
            curB = curB->next;
        }
        return nullptr;
    }
};

//双指针
//每步操作需要同时更新指针curA和curB；
//如果指针curA不为空，则将指针curA移到下一个节点；如果指针curB不为空，则将指针curB移到下一个节点。
//如果指针curA为空，则将指针curA移到链表headB的头节点；如果指针curB为空，则将指针curB移到链表headA的头节点。
//当指针curA和curB指向同一个节点或者都为空时，返回它们指向的节点或者null。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return nullptr;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA!=curB)
        {
            curA = (curA==nullptr?headB:curA->next);
            curB = (curB==nullptr?headA:curB->next);
        }
        return curA;
    }
};
```



#### 162.寻找峰值

峰值元素是指其值严格大于左右相邻值的元素。给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]<nums[mid+1])
                left = mid+1;//向上爬坡，高处必有峰值
            else
                right = mid;//向上爬坡，高处必有峰值
        }
        return left;
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



#### 187.重复的DNA序列

所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例 1：

```
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
```

示例 2：

```
输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
```

```c++
#incldue<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int L = 10;
        if(s.size()<L)
            return result;
        map<string, int> str_count;
        for(int i=0;i<=s.size()-L;i++)
        {
            string sub = s.substr(i, L);
            str_count[sub]++;
            //只考虑出现两次的字串，防止重复计数
            if(str_count[sub]==2)
                result.push_back(sub);
        }
        return result;
    }
};
```







#### 188.买卖股票的最佳时机IV

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

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
            result = result | tmp<<(31 - i);//将最后一位左移31-i位，即移到反转的位置，随后和result做或运算
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



#### 203.移除链表元素

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

```c++
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
        //创建虚拟头节点
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* pre = fake_head;
        ListNode* cur = head;
        while(cur)
        {
            if(cur->val==val)
            {
                pre->next = cur->next;
                cur = cur->next;
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



#### 221.最大正方形

在一个由 `'0'` 和 `'1'` 组成的二维矩阵内，找到只包含 `'1'` 的最大正方形，并返回其面积。

![221_1](E:\donkey\Documents\Computer_Algorithm\img\leetcode\221_1.png)

![221_2](E:\donkey\Documents\Computer_Algorithm\img\leetcode\221_2.png)

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示以(i,j)为右下角的正方形的最大边长
//dp[i][j]=min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int result = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j]=='0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                result = max(result, dp[i][j]);
            }
        }
        return result*result;
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



#### 229.滑动窗口最大值

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>> q;//优先队列以vector第一个元素来排序优先级，leetcode官方使用的是pair<int, int>
        vector<int> result;
        //将前k个元素放入优先队列，包括他们的索引，索引是为了后续删除元素
        for(int i=0;i<k;i++)
            q.push({nums[i], i});
        //取队首元素放入result中
        result.push_back(q.top()[0]);
        //遍历剩余元素
        for(int i=k;i<n;i++)
        {
            q.push({nums[i], i});
            //去除不在滑动窗口中的队首元素
            while(q.top()[1]<=i-k)
                q.pop();
            result.push_back(q.top()[0]);
        }
        return result;
    }
};
```





#### 231.2的幂

给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;
        while(n>1)
        {
            if(n%2==1)
                return false;
            n /= 2;
        }
        if(n==1)
            return true;
        return false;
    }
};
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



#### 274. H指数

给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。

h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 N - h 篇论文每篇被引用次数 不超过 h 次。

例如：某人的 h 指数是 20，这表示他已发表的论文中，每篇被引用了至少 20 次的论文总共有 20 篇。

示例：

输入：citations = [3,0,6,1,5]
输出：3 
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        sort(citations.begin(),citations.end());
        for(int i = citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=h+1)
                h++;
            else
                return h;
        }
        return h;
    }
};
```



#### 275. H指数II

和274一样，不过数组变为有序的。

```c++
#include<isotream>
#include<vector>

using namespace std;

//可以依次遍历
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        //sort(citations.begin(),citations.end());
        for(int i = citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=h+1)
                h++;
            else
                return h;
        }
        return h;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int left = 0;
        int right = size - 1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(citations[mid]>=size-mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return size - left;
    }
};
```





#### 278.第一个错误的版本

你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    int firstBadVersion(long long int n) {
        return search(1,n);
    }
private:
    long long int search(long long int start, long long int end)
    {
        while(start<end)
        {
            long long int mid = (start+end)/2;//也可以使用int类型的，但是使用int mid = left + (right - left) / 2;写法，防止计算时溢出
            if(isBadVersion(mid))
                end = mid;
            else
                start = mid+1;
        }
        return start;
    }
};
```



#### 279.完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

```c++
#include<iostream>
#include<vector>

using namespace std;

//将和视为要凑成的金额数，完全平方数视为硬币，和零钱兑换一样的完全背包问题
//dp[i]表示组成和为n的最少完全平方和数
//dp[i] = min{dp[i], dp[i-square[j]]+1},j=0,1,...,n-1
class Solution {
public:
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++)
            square.push_back(i*i);
        //for(int i=0;i<square.size();i++)
            //cout<<square[i]<<endl;
        return pack(square, n);
    }
private:
    vector<int> square;
    int pack(vector<int> square, int n)
    {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<square.size();j++)
            {
                if(i>=square[j])
                    dp[i] = min(dp[i], dp[i-square[j]]+1);
            }
            //cout<<dp[i]<<endl;
        }
        if(dp[n]>=0&&dp[n]<=n)
            return dp[n];
        return -1;
    }
};


//双循环遍历
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
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



#### 292.Nim游戏

你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头。你们轮流进行自己的回合，你作为先手。
（1）每一回合，轮到的人拿掉 1 - 3 块石头。
（2）拿掉最后一块石头的人就是获胜者。
假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。

```c++
#include<iostream>

using namespace std;


//显而易见的是，如果石头堆中只有一块、两块、或是三块石头，那么在你的回合，你就可以把全部石子拿走，从而在游戏中取胜；
//如果堆中恰好有四块石头，你就会失败。因为在这种情况下不管你取走多少石头，总会为你的对手留下几块，他可以将剩余的石头全部取完，从而他可以在游戏中打败你。
//因此要想获胜，在你的回合中，必须避免石头堆中的石子数为 4 的情况。

//继续推理，假设当前堆里只剩下五块、六块、或是七块石头，你可以控制自己拿取的石头数，总是恰好给你的对手留下四块石头，使他输掉这场比赛。
//但是如果石头堆里有八块石头，你就不可避免地会输掉，
//因为不管你从一堆石头中挑出一块、两块还是三块，你的对手都可以选择三块、两块或一块，以确保在再一次轮到你的时候，你会面对四块石头。
//显然我们继续推理，可以看到它会以相同的模式不断重复 n = 4, 8, 12, 16, ...基本可以看出如果堆里的石头数目为 4 的倍数时，你一定会输掉游戏。

//如果总的石头数目为 4 的倍数时，因为无论你取多少石头，对方总有对应的取法，让剩余的石头的数目继续为 4 的倍数。
//对于你或者你的对手取石头时，显然最优的选择是当前己方取完石头后，让剩余的石头的数目为 4 的倍数。
//假设当前的石头数目为 x，如果 x 为 4 的倍数时，则此时你必然会输掉游戏；
//如果 x 不为 4 的倍数时，则此时你只需要取走 xmod4 个石头时，则剩余的石头数目必然为 4 的倍数，从而对手会输掉游戏。

class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
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



#### 322.零钱兑换

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



#### 326.3的幂

给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。整数 n 是 3 的幂次方需满足：存在整数 $x$ 使得 $n=3^x$

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        while(n%3==0)
           n /= 3;
        return n==1?true:false;
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



#### 342.4的幂

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;
        while(n>3)
        {
            if(n%4!=0)
                return false;
            n /= 4;
        }
        if(n==1)
            return true;
        return false;
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



#### 345.反转字符串中的元音字母

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1：

```
输入："hello"
输出："holle"
```

示例 2：

```
输入："leetcode"
输出："leotcede"
```

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int start = 0;
        int end = s.size() - 1;
        while(start<end)
        {
            while(start<n&&!IsVower(s[start]))
                start++;
            while(end>=0&&!IsVower(s[end]))
                end--;
            if(start<end)
            {
                swap(s[start], s[end]); //交换之后，当前start和end处都是元音，所以需要start++，end--
                start++;
                end--;
            }
        }
        return s;
    }
private:
    bool IsVower(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
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



#### 374.猜数字大小

猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1：我选出的数字比你猜的数字小 pick < num
1：我选出的数字比你猜的数字大 pick > num
0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
返回我选出的数字。

```c++
class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while(start<end)
        {
            int mid = start + (end - start)/2;//防止溢出
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};
```



#### 401.二进制手表

二进制手表顶部有 4 个 LED 代表 **小时（0-11）**，底部的 6 个 LED 代表 **分钟（0-59）**。每个 LED 代表一个 0 或 1，最低位在右侧。给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。

小时不会以零开头：

例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
分钟必须由两位数组成，可能会以零开头：

例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int h=0;h<12;h++)
        {
            for(int m=0;m<60;m++)
            {
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn)
                    result.push_back(to_string(h) + ":" + (m<10?"0":"") + to_string(m));
            }
        }
        return result;
    }
};



//__builtin_popcount函数计算某个数二进制表示下1的个数
int main()
{
    int a = 4;
    int cnt = __builtin_popcount(a);
    cout<<cnt<<endl;
    return 0;
}
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



#### 413.等差数列划分

如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。

给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。子数组 是数组中的一个连续序列。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0;
        if(n<=2)
            return 0;
        for(int i = 2; i < n; i++)
        {
            //以最后一个数来遍历
            //如果当前数和前两个数构成等差数列，则当前数也可以和前两个数往前的数构成等差数列，所以l表示当前数增加的等差数列的个数
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
            {
                l++;
                ans += l;
            }
            //如果当前数和前两个数不构成等差数列，则l中断增加，重新寻找可以构成等差数列的序列
            else
                l = 0;
        }
        return ans;
    }
};
```



#### 437.路径总和III

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

```c++
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        //遍历root，同时计算以root为起点来计算等于路径和等于targetSum的路径数
        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
private:
    //以root为起点来计算等于路径和等于targetSum的路径数
    int rootSum(TreeNode* root, int targetSum)
    {
        if(!root)
            return 0;
        
        int ret = 0;
        if(root->val==targetSum)
            ret++;
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }
};
```



#### 447.回旋镖的数量

给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。返回平面上所有回旋镖的数量。

示例 1：

```c++
输入：points = [[0,0],[1,0],[2,0]]
输出：2
解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
```

```c++
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        //遍历作为回旋镖顶点的点
        for(auto p:points)
        {
            map<int, int> m;
            for(auto q:points)
            {
                int dis = (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]);
                m[dis]++;
            }
            //对相同距离的点进行排列组合计算回旋镖数量
            for(auto it=m.begin();it!=m.end();it++)
                result += it->second*(it->second-1);
            //或者
            // for(auto [_, x]:m)
            //     result += x*(x-1);
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



#### 461.汉明距离

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。给出两个整数 x 和 y，计算它们之间的汉明距离。注意：$0 ≤ x,y < 2^{31}$.

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming_distance = 0;
        for(int i=0;i<31;i++)
        {
            int flag = 1<<i;
            if((x&flag)!=(y&flag))
                hamming_distance++;
        }
        return hamming_distance;
    }
};

//或者
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};
```



#### 470.用Rand7()实现Rand10()

已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。不要使用系统的 Math.random() 方法。

```c++
#include<iostream>

using namespace std;

//用两个rand7()构造[1,49]中的随机整数，idx = col + (row - 1)*7；
//取前40个数构造[1,40]中的随机整数(40是为了取10的倍数，实际上取30，20，10也可，不过越小整体耗费的时间复杂度越高)
//idx对10取余数(需要对10进行特殊处理)，可以获得[1,10]的随机整数

class Solution {
public:
    int rand10() {
        int idx = 41;
        int row, col;
        while(idx>40)
        {
            row = rand7();
            col = rand7();
            idx = col + (row-1)*7;
        }
        //idx是[1,40]中的随机整数
        return 1 + (idx-1)%10;//为了将10映射到10，其余数和(idx%10)保持一致
    }
};

//这一题可以推广至两个任意区间的随机整数生成函数的转换，当有负整数的时候加一个正整数到1即可。

```





#### 474.一和零

给你一个二进制字符串数组 strs 和两个整数 m 和 n 。请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

```c++
#include<iostream>
#include<string>
#include<map>

using namespace std;

//思路：三维背包问题，第一维度为字符串个数，第二维度为0的个数，第三维度为1的个数
//dp[i][j][k]表示在0容量为j，1容量为k，前i个字符串最多包含的字符串的个数
//则dp[i][j][k]=max{dp[i-1][j][k],dp[i-1][j-zeros][k-ones]+1}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=1;i<=size;i++)
        {
            map<int, int> count = count_zero_one(strs[i-1]);
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(j<count[0]||k<count[1])
                        dp[i][j][k] = dp[i-1][j][k];
                    else
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count[0]][k-count[1]]+1);
                }
            }
        }
        return dp[size][m][n];
    }
private:
    map<int, int> count_zero_one(string str)
    {
        map<int, int> count;
        count[0] = 0;
        count[1] = 0;
        for(int i=0;i<str.size();i++)
            count[str[i]-'0']++;
        return count;
    }
};
```



#### 477.汉明距离总和

两个整数的 [汉明距离](https://baike.baidu.com/item/汉明距离/475174?fr=aladdin) 指的是这两个数字的二进制数对应位不同的数量。计算一个数组中，任意两个数之间汉明距离的总和。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        //统计第i位的汉明距离，已知所有数小于2^30
        //10^9<1000^3<1024^3<2^30
        for(int i=0;i<30;i++)
        {
            int count_c = 0;
            for(int j = 0;j<size;j++)
            {
                if(nums[j]&(1<<i))
                    count_c++;
            }
            result += count_c*(size-count_c);
        }
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



#### 494.目标和

给你一个整数数组 nums 和一个整数 target 。向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示前i个元素组成j的方案数
//dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j+nums[i-1]]，即nums第i个元素为+或者-
//该递推式中某一项的计算涉及到更后面的项，无法求解
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int target_max = target;
        for(int i=0;i<size;i++)
            target_max = max(target_max, target+nums[i])
        vector<vector<int>> dp(size+1, vector<int>(target_max+1,0));
        //初始化
        dp[0][0] = 1;
        for(int i=1;i<=size;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(j>nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j+nums[i-1]];
            }
        }
        return dp[size][target];
    }
};


//设sum为所有整数的和，neg为所有负号对应的整数和，则sum-neg为所有正号对应的整数和
//(sum-neg)-neg = target，neg = (sum-target)/2，故neg必须是偶数，否则方案数为0
//问题转化成在数组nums中选取若干元素，使得这些元素之和等于neg，计算选取元素的方案数
//设dp[i][j]表示nums中前i个元素组成若干元素，使得这些元素之和等于j的方案数
//dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]]，nums[i-1]选或者不选
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int sum = 0;
        for(int i=0;i<size;i++)
            sum += nums[i];
        if(((sum-target)<0)||(((sum-target)%2)!=0))
            return 0;
        int neg = (sum-target)/2;
        vector<vector<int>> dp(size+1, vector<int>(neg+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=size;i++)
        {
            for(int j=0;j<=neg;j++)
            {
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[size][neg];
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



#### 516.最长回文子序列

给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;


//dp[i][j]表示s[i]到s[j]中最长回文子序列的长度
//k=0，dp[i][j]长度一定为1
//k=1，dp[i][j]取决于s[i]与s[j]是否相等
//k>1，dp[i][j]取决于dp[i+1][j-1]:
//(1)如果s[i]==s[j]，则dp[i][j] = dp[i+1][j-1] + 2
//(2)如果s[i]!=s[j]，则s[i]和s[j]不可能同时为回文子序列的首尾，dp[i][j] = max(dp[i+1][j], dp[i][j+1])
//最终返回dp[0][n-1]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        //k = j - i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = 1;
                else if(k==1)
                {
                    if(s[i]==s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    if(s[i]==s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        return dp[0][n-1];
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



#### 523.连续的子数组和

给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ；

子数组元素总和为 k 的倍数。

如果存在，返回 true ；否则，返回 false 。如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//计算前缀和数组sum，sum[i]表示nums中从nums[0]加到nums[i-1]的和
//则，nums[i]+nums[i+1]+...+nums[j]=sum[j+1]-sum[i]
//使用前缀和，然后双循环遍历，通过93/94个测试案例，超时
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)
            return false;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //计算连续子数组的和
        for(int i=0;i<n;i++)
            for(int j = i+1;j<n;j++)
            {
                int tmp_sum = sum[j+1] - sum[i];
                if(tmp_sum%k==0)
                    return true;
            }
        return false;
    }
};

//使用前缀和+哈希表存储k的余数
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)
            return false;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }

        //for(int i=0;i<=n;i++)
            //cout<<sum[i]<<endl;
        //对sum中每个值计算除以k的余数，并将余数和索引存于map中
        //如果
        map<int, int> mod;
        for(int i=0;i<=n;i++)
        {
            int m = sum[i]%k;
            if(mod.count(m)==1)
            {
                if((i-mod[m])>=2)
                    return true;
            }
            else
                mod[m] = i;
        }
        return false;
    }
};
```



#### 525.连续数组

给定一个二进制数组 `nums` , 找到含有相同数量的 `0` 和 `1` 的最长连续子数组，并返回该子数组的长度。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//首先将数组中的0全部设置为-1，然后和523题类似使用前缀和，连续子数组和为0说明-1和1的数目一样多
//随后使用双循环遍历满足题意的数组长度，求最大值，通过31/564超时
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i] = -1;
        }
        //for(int i=0;i<n;i++)
            //cout<<nums[i]<<endl;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //for(int i=0;i<=n;i++)
            //cout<<sum[i]<<endl;
        //计算连续子数组的和
        for(int i=0;i<n;i++)
            for(int j = i+1;j<n;j++)
            {
                int tmp_sum = sum[j+1] - sum[i];
                if(tmp_sum==0)
                    result = max(result, j-i+1);
            }
        return result;
    }
};


//使用前缀和+哈希表
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i] = -1;
        }
        //for(int i=0;i<n;i++)
            //cout<<nums[i]<<endl;
        //前缀和数组
        vector<int> sum(n+1, 0);
        sum[0] = 0;
        int s = 0;
        for(int i=1;i<=n;i++)
        {
            s += nums[i-1];
            sum[i] = s;
        }
        //for(int i=0;i<=n;i++)
            //cout<<sum[i]<<endl;
        //使用哈希表记录前缀和第一次出现的下标
        //如果前缀和相同，则相减的结果一定为0
        map<int, int> value_first;
        for(int i=0;i<=n;i++)
        {
            if(value_first.count(sum[i]))
            {
                result = max(result, i-value_first[sum[i]]);
            }
            else
                value_first[sum[i]] = i;
        }
        return result;
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



#### 551.学生出勤记录I

给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：

```
'A'：Absent，缺勤
'L'：Late，迟到
'P'：Present，到场
```


如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：按 总出勤 计，学生缺勤（'A'）严格 少于两天。学生 不会 存在 连续 3 天或 3 天以上的迟到（'L'）记录。如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        for(auto c:s)
        {
            if(c=='A')
            {
                absent++;
                if(absent==2)
                    return false;
            }
            if(c=='L')
            {
                late++;
                if(late==3)
                    return false;
            }
            else
                late = 0;
        }
        return true;
    }
};
```



#### 565.数组嵌套

索引从`0`开始长度为`N`的数组`A`，包含`0`到`N - 1`的所有整数。找到最大的集合`S`并返回其大小，其中 `S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }`且遵守以下的规则。

假设选择索引为`i`的元素`A[i]`为`S`的第一个元素，`S`的下一个元素应该是`A[A[i]]`，之后是`A[A[A[i]]]...` 以此类推，不断添加直到`S`出现重复的元素。

**示例 1:**

```
输入: A = [5,4,0,3,1,6,2]
输出: 4
解释: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
```

```c++
#include<iostream>
#include<vector>

using namespace std;

//从i向nums[i]连线，可以得到一个有向图；
//由于nums中元素不重复，故有向图由一个环或多个环组成；
//可以遍历nums，使用一个标记数组，找到节点个数最大的环；
// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int result = 0;
//         int n = nums.size();
//         vector<int> flag(n);
//         for(int i=0;i<n;i++)
//         {
//             int count_tmp = 0;
//             while(flag[i]==0)
//             {
//                 flag[i] = 1;//i节点已经访问
//                 count_tmp++;//当前环中节点数加1
//                 i = nums[i];//指向下一个节点
//             }
//             result = max(result, count_tmp);
//         }

//         return result;
//     }
// };

//优化空间，对原数组进行原地标记，节省标记数组的空间
//由于数组中的数都是小于n的，可以使用n来标记已经遍历过的节点
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int count_tmp = 0;
            while(nums[i]<n)
            {
                int num = nums[i];//标记之前先保存数值
                nums[i] = n;//标记
                count_tmp++;
                i = num;
            }
            result = max(result, count_tmp);
        }

        return result;
    }
};
```





#### 576.出界的路径数

给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 $10^9 + 7$ 取余 后的结果。

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j][k]表示移动i次后位置在(j,k)的路径数
//边界：dp[0][startRow][startColumn]=0,dp[0][j][k]=1,j!=startRow,k!=startColumn
//假设从(j,k)->(j',k'):
//(1)如果(j',k')未出界，则dp[i+1][j'][k'] += dp[i][j][k];
//(2)如果(j',k')出界，则result += dp[i][j][k]
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 0;
        int MOD = 1000000007;
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n)));
        //边界
        dp[0][startRow][startColumn] = 1;
        for(int i=0;i<maxMove;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<n;k++)
                {
                    for(auto dir:direction)
                    {
                        int j1 = j+dir[0];
                        int k1 = k+dir[1];
                        if(j1>=0&&j1<m&&k1>=0&&k1<n)
                            dp[i+1][j1][k1] = (dp[i+1][j1][k1] + dp[i][j][k]) % MOD;
                        else
                            result = (result + dp[i][j][k]) % MOD;
                    }
                }
        return result;
    }
};
```



#### 583.两个字符串的删除操作

给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

示例：

```
输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
```

```c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//求最长子序列的长度，两个字符串到最长子序列要删除的字符数之和就是最少操作步数
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<m+1;i++)
        {
            char w1 = word1[i-1];
            for(int j=1;j<n+1;j++)
            {
                char w2 = word2[j-1];
                if(w1==w2)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int loss = m - dp[m][n] + n - dp[m][n];
        return loss;
    }
};
```





#### 611.有效三角形的个数

给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

示例 1:

```
输入: [2,2,3,4]
输出: 3
解释:
有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
```

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int left = j+1;
                int right = n-1;
                int k = j;
                while(left<=right)
                {
                    int mid = left + (right-left)/2;
                    if(nums[mid]<nums[i]+nums[j])
                    {
                        k = mid;
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                count += k-j;//k算，j不算
            }
        return count;
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



#### 650.只有两个键的键盘

最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

（1）Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
（2）Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

```c++
#include<iostream>
#include<vector>

using namespace std;

//设dp[i]表示打出i个'A'最少需要多少操作
//dp[i] = min{dp[j]+i/j}，其中j|i；即在i的因子j中进行动态规划，当有j个'A'时，可以先复制，再粘贴i/j-1次，共i/j次操作
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, n);//n个'A'最多操作n次
        dp[0] = 0;
        dp[1] = 0;
        for(int i=0;i<=n;i++)
        {
            //遍历i的因子
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    dp[i] = min(dp[i], min(dp[j]+i/j, dp[i/j]+j));//考虑因子i/j和因子j
                }
            }
        }
        return dp[n];
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



#### 669.修剪二叉搜索树

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



#### 673.最长递增子序列的个数

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

```
输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
```


示例 2:

```
输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
```

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i]表示以nums[i]结尾的最长上升子序列的长度，cnt[i]表示以nums[i]结尾的最长上升子序列的个数；
//dp的递推为：dp[i] = max(dp[j]+1)，其中0<=j<i且nums[j]<nums[i]；
//对于cnt[i]，其等于所有满足dp[j]+1=dp[i]的cnt[j]之和，可以在计算dp[i]的同时统计cnt[i]的值；
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int ans = 0;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];//重置计数
                    }
                    else if(dp[j]+1==dp[i])
                        cnt[i] += cnt[j];
                }
            }
            if(dp[i]>maxLen)
            {
                maxLen = dp[i];
                ans = cnt[i];//重置计数
            }
            else if(dp[i]==maxLen)
                ans += cnt[i];
        }
        return ans;
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



#### 704.二分查找

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

```c++
#include<iostream>
#include<vector>

using namespace std

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left]==target?left:-1;
    }
};
```



#### 725.分割链表

给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。

这可能会导致有些部分为 null 。这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。返回一个由上述 k 部分组成的数组。

```c++
#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        //计算链表长度
        while(temp!=nullptr)
        {
            n++;
            temp = temp->next;
        }
        //计算商和余数
        //则在分隔成的k个部分中，前remainder个部分的长度各为quotient+1其余每个部分的长度各为quotient
        int quotient = n/k;
        int remainder = n%k;

        vector<ListNode*> parts(k, nullptr);
        ListNode* curr = head;
        for(int i=0;i<k&&curr!=nullptr;i++)
        {
            parts[i] = curr;
            int partSize = quotient + (i<remainder?1:0);//前remainder个部分的长度各为quotient+1其余每个部分的长度各为quotient
            for(int j=1;j<partSize;j++)
            {
                curr = curr->next;
            }
            //第i个分割的链表，断开curr和curr->next;
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return parts;
    }
};
```



#### 735.行星碰撞

给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

示例 1：

输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
示例 2：

输入：asteroids = [8,-8]
输出：[]
解释：8 和 -8 碰撞后，两者都发生爆炸。
示例 3：

输入：asteroids = [10,2,-5]
输出：[10]
解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。

```c++
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        stk.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            if(stk.empty())
            {
                stk.push(asteroids[i]);
            }
            else
            {
                if((stk.top()*asteroids[i]>0)||(stk.top()<0&&asteroids[i]>0))
                    //当前行星和栈中行星同方向 或者 栈中行星往左，当前行星往右
                    stk.push(asteroids[i]);
                else//当前行星和栈中行星不同向
                {
                    if(abs(stk.top())==abs(asteroids[i]))
                    {    
                        stk.pop();
                        continue;
                    }
                    else if(abs(stk.top())>abs(asteroids[i]))
                        continue;
                    else
                    {
                        stk.pop();
                        i = i-1;//保持i不变，执行结束i会自动加1
                    }
                }
            }
        }

        //将栈转换为数组
        vector<int> result;
        while(!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(),result.end());//反转数组
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
        //如果要求返回x向上取整的数，即返回x+(x-1)/x
    }
};
```



#### 783.二叉搜索树节点最小距离

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



#### 797.所有可能的路径

给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。

译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a 。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(stk);
            return;
        }
        for (auto& y : graph[x])//遍历x能到达的下一个节点
        {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();//遍历完再pop出当前节点y
        }
    }
};
```



#### 852.山脉数组的峰顶索引

符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

```c++

//题目保证是一个山脉数组，且长度大于等于3
//遍历
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        for(int i=1;i<size;)
        {
            if(arr[i]>arr[i-1])
                i++;
            else
                return i-1;
        }
        return -1;
    }
};


//二分
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        int start = 0;
        int end = arr.size() - 1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid]>arr[mid+1])
            {
                ans = mid;//已经记录下mid的位置
                end = mid - 1;
            }
            else
                start = mid + 1;                
        }
        return ans;
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



#### 863.二叉树中所有距离为K的结点

给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //从root出发DFS，记录每个结点的父结点
        findParenets(root);

        //从target出发DFS，寻找所有深度为k的结点
        findAns(target, nullptr, 0, k);

        return ans;
    }

private:
    map<int, TreeNode*> parenets;
    vector<int> ans;

    void findParenets(TreeNode* node)
    {
        if(node->left!=nullptr)
        {
            parenets[node->left->val] = node;
            findParenets(node->left);
        }
        if(node->right!=nullptr)
        {
            parenets[node->right->val] = node;
            findParenets(node->right);
        }
    }

    void findAns(TreeNode* node, TreeNode* from, int depth, int k)
    {
        //from表示当前遍历过程中节点node的上一个节点，depth表示当前节点node的深度
        if(node==nullptr)
            return;
        if(depth==k)
        {
            ans.push_back(node->val);
            return;
        }

        //防止向下遍历时又回到遍历过程中当前节点上一个节点
        if(node->left!=from)
            findAns(node->left, node, depth+1, k);
        if(node->right!=from)
            findAns(node->right, node, depth+1, k);
        
        //防止向上遍历时又回到遍历过程中当前节点上一个节点
        if(parenets[node->val]!=from)
            findAns(parenets[node->val], node, depth+1, k);
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



#### 877.石子游戏

亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

```c++
//将偶数堆（1,2,...,2k）石头分组，奇数索引堆为1组，偶数索引堆为一组，计算这两组的石头个数的多少
//先手的那个人可以控制自己选哪一组，比如先选第1堆，那么后面那个人只能选第2或者第2k堆，都是偶数索引；
//假设后手那个人选了第2k堆，则先手那个人可以再选第2k-1堆，以此类推。
//即先手那个人可以控制自己选那一组，选择石头数目多的那一组即可
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```



#### 881.救生艇

第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

```c++
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



#### 1046.最后一块石头的重量

有一堆石头，每块石头的重量都是正整数。每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

```
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
```

最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //创建优先队列，即大顶堆
        priority_queue<int> q;
        for(int i=0;i<stones.size();i++)
            q.push(stones[i]);
        
        //模拟粉碎过程
        while(q.size()>1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a>b)
                q.push(a-b);
        }
        return q.size()==1?q.top():0;
    }
};
```



#### 1074.元素和为目标值的子矩阵数量

给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int row1 = 0;row1<m;row1++)
        {
            //列和数组
            vector<int> sum_col(n, 0);
            for(int row2 = row1;row2<m;row2++)
            {
                for(int col=0;col<n;col++)
                {
                    sum_col[col] += matrix[row2][col];//每次row2增加，sum_col都会更新
                }
                /*
                cout<<"当前sum_col为:";
                for(int col=0;col<n;col++)
                    cout<<sum_col[col]<<" ";
                cout<<endl;
                */
                //计算区域和
                for(int start=0;start<n;start++)
                {
                    //sum_col中从start到end之间的和
                    int sum_local = 0;
                    for(int end=start;end<n;end++)
                    {
                        sum_local += sum_col[end];
                        if(sum_local==target)
                        {
                            //cout<<row1<<" "<<row2<<" "<<start<<" "<<end<<endl;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
```



#### 1109.航班预定统计

这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。请你返回一个长度为 n 的数组 answer，其中 answer[i] 是航班 i 上预订的座位总数。

```
输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
解释：
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
```

```c++
#include<iostream>
#include<vector>

using namespace std;

//差分数组：对于原数组nums[i]，差分数组nums1[i] = nums[i]-nums[i-1];nums1[0] = num[0];
//对差分数组求前缀和数组即得到原数组即：nums[i] = num1[0]+nums1[1]+...+nums[i]
//对于原数组nums某个区间[l,r]添加一个增量inc时，对应的差分数组nums1的改变是：nums1[l]+inc,nums1[r+1]-inc
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);//初始差分数组元素全0
        for(auto book:bookings)
        {
            int inc = book[2];
            nums[book[0]-1] += inc;//差分数组nums1[l]+inc
            if(book[1]<n)
                nums[book[1]] -= inc;//差分数组nums1[r+1]-inc
        }
        //对差分数组求前缀和得到原数组
        for(int i=1;i<n;i++)
            nums[i] += nums[i-1];
        return nums;
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



#### 1221.分割平衡字符串

在一个 平衡字符串 中，'L' 和 'R' 字符的数量是相同的。给你一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

注意：分割得到的每个字符串都必须是平衡字符串。返回可以通过分割得到的平衡字符串的 最大数量 。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int length = s.size();
        int L = 0;
        int R = 0;
        int result = 0;
        for(int i=0;i<length;i++)
        {
            if(s[i]=='L')
                L++;
            if(s[i]=='R')
                R++;
            if(L==R)
                result++;
        }
        return result;
    }
};
```



#### 1252.奇数值单元格的数目

给你一个 `m x n` 的矩阵，最开始的时候，每个单元格中的值都是 `0`。

另有一个二维索引数组 `indices`，`indices[i] = [ri, ci]` 指向矩阵中的某个位置，其中 `ri` 和 `ci` 分别表示指定的行和列（**从 `0` 开始编号**）。

对 `indices[i]` 所指向的每个位置，应同时执行下述增量操作：

1. `ri` 行上的所有单元格，加 `1` 。
2. `ci` 列上的所有单元格，加 `1` 。

给你 `m`、`n` 和 `indices` 。请你在执行完所有 `indices` 指定的增量操作后，返回矩阵中 **奇数值单元格** 的数目。

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/06/e1.png)

```
输入：m = 2, n = 3, indices = [[0,1],[1,1]]
输出：6
解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
```

```c++
/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

//方法一：直接模拟
// class Solution {
// public:
//     int oddCells(int m, int n, vector<vector<int>>& indices) {
//         int res = 0;
//         vector<vector<int>> matrix(m, vector<int>(n));
//         for (int I=0;I<indices.size();I++) {
//             vector<int> index = indices[I];
//             for (int i = 0; i < n; i++) {
//                 matrix[index[0]][i]++;
//             }
//             for (int i = 0; i < m; i++) {
//                 matrix[i][index[1]]++;
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] & 1) {
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };


//方法二
//使用两个数组记录每一行和每一列增加的次数，如rows[i]表示第i行增加的次数
// class Solution {
// public:
//     int oddCells(int m, int n, vector<vector<int>>& indices) {
//         int result = 0;
//         vector<int> rows(m);
//         vector<int> cols(n);
//         for(int i=0;i<indices.size();i++)
//         {
//             vector<int> index = indices[i];
//             rows[index[0]]++;
//             cols[index[1]]++;
//         }
//         //遍历整个矩阵
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if((rows[i]+cols[j])%2==1)
//                     result++;
//             }
//         }
//         return result;
//     }
// };


//方法三
//进一步考虑数组rows和cols，最终矩阵matrix[i][j]为奇数的充分必要条件是rows[i]
//和cols[j]中必定一个为奇数一个为偶数。
//假设rows数组中有oddx个奇数，cols数组有oddy个奇数，
//则rows[i]为奇数的那些行对应的列为偶数情况下，才可以使得matrix[i][j]为奇数，即有oddx*(n-oddy)个奇数；
//同理，则rows[i]为偶数的那些行对应的列为奇数情况下，才可以使得matrix[i][j]为奇数，即有oddy*(m-oddx)个奇数；
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int result = 0;
        vector<int> rows(m);
        vector<int> cols(n);
        for(int i=0;i<indices.size();i++)
        {
            vector<int> index = indices[i];
            rows[index[0]]++;
            cols[index[1]]++;
        }
        //计算oddx和oddy
        int oddx = 0;
        int oddy = 0;
        for(int i=0;i<m;i++)
        {
            if(rows[i]%2==1)
                oddx++;
        }
        for(int i=0;i<n;i++)
        {
            if(cols[i]%2==1)
                oddy++;
        }

        return oddx*(n-oddy)+oddy*(m-oddx);
    }
};

// @lc code=end
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



#### 1277.统计全为1的正方形子矩阵

给你一个 `m * n` 的矩阵，矩阵中的元素不是 `0` 就是 `1`，请你统计并返回其中完全由 `1` 组成的 **正方形** 子矩阵的个数。

解体思路和221最大正方形一样。

![221_1](E:\donkey\Documents\Computer_Algorithm\img\leetcode\221_1.png)

![221_2](E:\donkey\Documents\Computer_Algorithm\img\leetcode\221_2.png)

```c++
#include<iostream>
#include<vector>

using namespace std;

//dp[i][j]表示以(i,j)为右下角的正方形的最大边长，同时dp[i][j]=x也表示以(i,j)为右下角的正方形的数目为x，即变成为1，2，...，x的正方形各一个
//dp[i][j]=min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
//最终结果是所有dp[i][j]之和
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int result = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                
                result += dp[i][j];
            }
        }
        return result;
    }
};
```





#### 1291.顺次数

我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 1 的整数。请你返回由 [low, high] 范围内所有顺次数组成的 有序 列表（从小到大排序）。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<=9;i++)
        {
            //第一个for循环决定第一位数字，假设为4
            int num = i;
            for(int j=i+1;j<=9;j++)
            {
                //第二个for循环遍历以4开头的顺位加一的数字，如45,456,4567,...
                num = num*10 + j;
                if(low<=num&&num<=high)
                    result.push_back(num);
            }
        }
        sort(result.begin(),result.end());
        return result;
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



#### 1411.给 N x 3 网格图涂色的方案数

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



#### 1456.定长子串中元音的最大数目

给你字符串 s 和整数 k 。请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。英文中的 元音字母 为（a, e, i, o, u）。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int Vowel_Count = 0;
        //统计前k个字符中元音字母数
        for(int i=0;i<k;i++)
            Vowel_Count += IsVowel(s[i]);
        int result = Vowel_Count;
        //滑动窗口，考虑新进的字符和出去的字符
        for(int i=k;i<s.size();i++)
        {
            Vowel_Count += IsVowel(s[i]) - IsVowel(s[i-k]);
            result = max(result, Vowel_Count);
        }
        return result;
    }
private:
    int IsVowel(char c)
    {
        return (c=='a'||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
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



#### 1588.所有奇数长度子数组的和

给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。子数组 定义为原数组中的一个连续子序列。请你返回 arr 中 所有奇数长度子数组的和 。

```c++
#include<iostream>
#include<vector>

usign namespace std;


//思路：计算每个元素可以组成多少个奇数长度子数组
//arr[i]左边有left_count=i个元素，右边right_count=n-i-1个元素；
//如果arr[i]在某个奇数长度的子数组中，则arr[i]左右元素个数应当同奇同偶；
//(1)当arr[i]两边的个数都为奇数时，左边可以选择{arr[i-1]},{arr[i-1],arr[i-2],arr[i-3]},...有(left_count+1)/2种选择，右边有(right_count+1)/2种选择；
//(2)当arr[i]两边的个数都为偶数时，左边可以选择{},{arr[i-1],arr[i-2]},...有left_count/2+1种，不选则表示0个，也算偶数所以要加1，右边有right_count/2+1种选择；
//(3)所以arr[i]可以组成(x_odd*y_odd+x_even*y_even)个奇数长度子序列
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int left_count = i;
            int right_count = n-i-1;
            int x_odd = (left_count+1)/2;
            int y_odd = (right_count+1)/2;
            int x_even = left_count/2+1;//0也算偶数，所以后面+1
            int y_even = right_count/2+1;
            result += arr[i]*(x_odd*y_odd + x_even*y_even);
        }
        return result;
    }
};
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



#### 1736.替换隐藏数字得到的最晚时间

给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        if(time[0]=='?')
        {
            if(time[1]=='?')
            {
                time[0] = '2';
                time[1] = '3';
            }
            else if(time[1]-'0'<=3)
                time[0] = '2';
            else
                time[0] = '1';
        }
        if(time[0]=='2')
        {
            if(time[1]=='?')
                time[1] = '3';
        }
        else
        {
            if(time[1]=='?')
                time[1] = '9';
        }
        if(time[3]=='?')
            time[3] = '5';
        if(time[4]=='?')
            time[4] = '9';
        return time;
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



#### 1743.从相邻元素还原数组

存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> result(adjacentPairs.size()+1);
        
        //记录每个元素和对应邻接元素
        map<int, vector<int>> mp;
        for(auto v: adjacentPairs)
        {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        //第一个元素
        for(auto [e, adj]: mp)
        {
            if(mp[e].size()==1)
            {
                result[0] = e;
                break;
            }
        }

        //最后一个元素
        // for(auto [e, adj]: mp)
        // {
        //     if(mp[e].size()==1&&e!=result[0])
        //     {
        //         result[adjacentPairs.size()] = e;
        //         break;
        //     }
        // }
        
        //提前确定第二个元素，后续需要用到i-2
        result[1] = mp[result[0]][0];
        for(int i=2;i<adjacentPairs.size()+1;i++)
        {
            vector<int> adj = mp[result[i-1]];
            result[i] = result[i-2]==adj[0]?adj[1]:adj[0];
        }
        return result;
    }
};
```



#### 1785.构成特定和需要添加的最少元素

给你一个整数数组 nums ，和两个整数 limit 与 goal 。数组 nums 有一条重要属性：abs(nums[i]) <= limit 。返回使数组元素总和等于 goal 所需要向数组中添加的 最少元素数量 ，添加元素 不应改变 数组中 abs(nums[i]) <= limit 这一属性。

示例1：

```c++
输入：nums = [1,-1,1], limit = 3, goal = -4
输出：2
解释：可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
```

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        double sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        sum = fabs(sum - goal);
        return int((sum+limit-1)/limit);//取sum/limit向上取整的数
        //return ceil(temp / (double)limit);//使用ceil函数向上取整
    }
};
```





#### 1818.绝对差值和

给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0 开始）。

你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 109 + 7 取余 后返回。

```c++

//思路：
//我们使用sum记录所有的差值和，用maxn记录最大的改变前后的差值，
//这样答案即为sum−maxn。

//官方题解
class Solution {
public:
    static constexpr int mod = 1'000'000'007;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int sum = 0, maxn = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            //lower_bound函数查找目标中第一个比nums2[i]大的数，如果找不到返回n
            int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
            //j<n，说明找到了第一个比nums2[i]大的数，计算此时的差值，但不一定是最大差值
            if (j < n) {
                maxn = max(maxn, diff - (rec[j] - nums2[i]));
            }
            //j>0有两个作用
            //(1)j==n，则最接近nums2[i]的数就是rec[j-1]
            //(2)0<j<n，还需要比较下最接近nums2[i]的数是不是rec[j-1]，因为小于nums2[i]的数也可以是最接近nums2[i]的数
            if (j > 0) {
                maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};

//个人写法
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int sum = 0, maxn = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            //lower_bound函数查找目标中第一个比nums2[i]大的数，如果找不到返回n
            //可二分查找，也可直接遍历（超时）
            int j = search(rec, nums2[i]);
            //没找到比nums2[i]大的数，最接近nums2[i]的数是rec[n-1]
            if(j==n)
                maxn = max(maxn, diff - (nums2[i]-rec[j-1]));
            else if(j==0)
                maxn = max(maxn, diff - (rec[j]-nums2[i]));
            else
                maxn = max(maxn, diff - min(nums2[i]-rec[j-1], rec[j]-nums2[i]));
        }
        return (sum - maxn + mod) % mod;
    }
private:
    int mod = 1'000'000'007;
    //直接遍历可能超时
    int search(vector<int> vec, int target)
    {
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>target)
                return i;
        }
        return vec.size();
    }
    //二分法找vec数组中第一个大于target的索引，如果没有返回vec.size()，无法AC
    // int search(vector<int> vec, int target)
    // {
    //     int left = 0;
    //     int right = vec.size() - 1;
    //     while(left<right)
    //     {
    //         int mid = (right-left)/2 + left;
    //         if(vec[mid]<=target)
    //             left = mid + 1;
    //         else
    //             right = mid;
    //     }
    //     return right<vec.size()?right:vec.size();
    // }
};
```



#### 1838.最高频元素的频数

元素的 频数 是该元素在一个数组中出现的次数。给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

示例 1：

输入：nums = [1,2,4], k = 5
输出：3
解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。4 是数组中最高频元素，频数是 3 。

```c++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //先给数组排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int left = 0, res = 1;
        for (int right = 1; right < n; ++r)
        {
            //每次移动右边界增加的操作次数
            total += (long long)(nums[right] - nums[right - 1]) * (right - left);
            //如果当前的操作次数超过k，需要改变左边界
            while (total > k)
            {
                //每次移动左边界减少的操作次数
                total -= nums[right] - nums[left];
                ++left;
            }
            //计算当前滑动窗口的长度，更新res
            res = max(res, right - left + 1);
        }
        return res;
    }
};
```


#### 1846.减小和重新排列数组后的最大元素

给你一个正整数数组 arr 。请你对 arr 执行一些操作（也可以不进行任何操作），使得数组满足以下条件：

```
1.arr 中 第一个 元素必须为 1 。
2.任意相邻两个元素的差的绝对值 小于等于 1 ，也就是说，对于任意的 1 <= i < arr.length （数组下标从 0 开始），都满足 abs(arr[i] - arr[i - 1]) <= 1 。abs(x) 为 x 的绝对值。
```


你可以执行以下 2 种操作任意次：

```
1.减小 arr 中任意元素的值，使其变为一个 更小的正整数 。
2.重新排列 arr 中的元素，你可以以任意顺序重新排列。
```


请你返回执行以上操作后，在满足前文所述的条件下，arr 中可能的最大值 。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size  = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i=1;i<size;i++)
            arr[i] = min(arr[i], arr[i-1] + 1);
        return arr[size-1];
    }
};
```



#### 1877.数组中最大数对和的最小值

一个数对 (a,b) 的 数对和 等于 a + b 。最大数对和 是一个数对数组中最大的 数对和 。比方说，如果我们有数对 (1,5) ，(2,3) 和 (4,4)，最大数对和 为 max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8 。
给你一个长度为 偶数 n 的数组 nums ，请你将 nums 中的元素分成 n / 2 个数对，使得：nums 中每个元素 恰好 在 一个 数对中，且最大数对和 的值 最小 。请你在最优数对划分的方案下，返回最小的 最大数对和 。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<size/2;i++)
        {
            result = max(result, nums[i]+nums[size-1-i]);
        }
        return result;
    }
};
```



#### 1893.检查是否区域内所有整数都被覆盖

给你一个二维整数数组 ranges 和两个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从 starti 到 endi 的 闭区间 。如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti <= x <= endi ，那么我们称整数x 被覆盖了。

```c++
#include<iostream>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        bool result = true;
        for(int index=left;index<=right;index++)
        {
            int flag = 0;
            for(auto range: ranges)
            {
                if(index>=range[0]&&index<=range[1])
                    flag=1;
            }
            if(flag==0)
                result = false;
        }
        return result;
    }
};
```



#### 1894.找到需要补充粉笔的学生编号

一个班级里有 n 个学生，编号为 0 到 n - 1 。每个学生会依次回答问题，编号为 0 的学生先回答，然后是编号为 1 的学生，以此类推，直到编号为 n - 1 的学生，然后老师会重复这个过程，重新从编号为 0 的学生开始回答问题。

给你一个长度为 n 且下标从 0 开始的整数数组 chalk 和一个整数 k 。一开始粉笔盒里总共有 k 支粉笔。当编号为 i 的学生回答问题时，他会消耗 chalk[i] 支粉笔。如果剩余粉笔数量 严格小于 chalk[i] ，那么学生 i 需要 补充 粉笔。

请你返回需要 补充 粉笔的学生 编号 。

```c++
#include<iostream>
#include<vector>

using namespace std

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        //对数组元素求和
        long long total = 0;
        for(int i=0;i<n;i++)
            total += chalk[i];
        
        k = k % total;//避免遍历多次
        
        int index = 0;
        while(true)
        {
            if(k<chalk[index])
                return index;
            else
            {
                k = k - chalk[index];
                index = (index + 1) % n;
            }
        }
    }
};
```





