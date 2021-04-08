### 一、二叉树

#### 1.二叉树的三序遍历，递归与非递归，实际上就是树的DFS遍历就是先序遍历

```c++
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
};

//递归遍历
vector<int> v;
void MidOrder(TreeNode *T)
{
	if(T==NULL)
	{
		return;
	}
	MidOrder(T->left);
	v.push_back(T->val);//此处改变顺序就得到先序和后序
	MidOrder(T->right); 
}
//或者
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

//非递归先序遍历
vector<int> PreOrder(TreeNode *T)
{
	vector<int> v;
    if(T==NULL)
        return v;
	stack<TreeNode*> s;
	while(T||!s.empty())
	{
		while(T!=NULL)//先输出当前的节点值，如果当前的T不为空，则一直要到最左边
		{
			v.push_back(T->val);
			s.push(T);
			T = T->left;
		}
		if(!s.empty())
		{
			T = s.top();
			s.pop();
			T = T->right;
		}
	}
	return v;
}

//非递归中序遍历
vector<int> MidOrder(TreeNode *T)
{
	vector<int> v;
	stack<TreeNode*> s;
	while(T||!s.empty())
	{
		while(T!=NULL)//如果当前的T不为空，则一直要到最左边
		{
			s.push(T);
			T = T->left;
		}
		if(!s.empty())
		{
			T = s.top();
			s.pop();
			v.push_back(T->val);
			T = T->right;
		}
	}
	return v;    
}

//非递归后序遍历，只需将先序遍历的左右交换，同时将打印部分改为压入另一个栈，最后打印这个栈中的元素即得到后序
vector<int> PostOrder(TreeNode *T)
{
	vector<int> v;
	stack<TreeNode*> s;
	stack<TreeNode*> ss;
	while(T||!s.empty())
	{
		while(T!=NULL)//先输出当前的节点值，如果当前的T不为空，则一直要到最左边
		{
			ss.push(T);//按照根-右-左进栈
			s.push(T);
			T = T->right;
		}
		if(!s.empty())
		{
			T = s.top();
			s.pop();
			T = T->left;
		}
	}
	while(!ss.empty())
	{
		T = ss.top();
		ss.pop();
		v.push_back(T->val);
	}
	return v;    
}
```



#### 2.二叉树BFS（层次遍历）

```c++
 vector<int> BFS(TreeNode* root)
 {
     vector<int> v;
     if(root==NULL)
         return v;
 	 queue<TreeNode*> q;//队列
 	 q.push(root);//根节点入队
 	 while(!q.empty())//队不空
 	 {
 	     TreeNode* node=q.front();//队首元素
 		 v.push_back(node->val);
 		 q.pop();//处理完出队
 		 if(node->left)//左儿子存在
 		     q.push(node->left);
 		 if(node->right)//右儿子存在
 		     q.push(node->right);
 	 }
     return v;
  }
```



### 二、排序方法以及应用

#### 1.归并排序

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void MergeOrder(vector<int>& v)
    {
        vector<int> tool_v(v.size(),0);
        solve(v, 0, v.size()-1, tool_v);
    }
private:
    void solve(vector<int>& a, int left, int right, vector<int>& b)
    {
        if(right>left)
        {
            int mid = (left+right)/2;
            solve(a, left, mid, b);
            solve(a, mid+1, right, b);
            merge(a, left, mid, right, b);
        }
    }
    void merge(vector<int>& a, int left, int mid, int right, vector<int>& b)
    {
        int i = left;
        int j = mid+1;
        int k = 0;
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i<=mid)
            b[k++] = a[i++];
        while(j<=right)
            b[k++] = a[j++];
        for(int i=0;i<k;i++)
            a[left+i] = b[i];
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    Solution s;
    s.MergeOrder(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}

//其中用到了一个工具数组tool_v，实际上这个数组只在二路归并的时候起到作用，所以可以简化如下：
class Solution
{
public:
    void MergeOrder(vector<int>& v)
    {
        solve(v, 0, v.size()-1);
    }
private:
    void solve(vector<int>& a, int left, int right)
    {
        if(right>left)
        {
            int mid = (left+right)/2;
            solve(a, left, mid);
            solve(a, mid+1, right);
            merge(a, left, mid, right);
        }
    }
    void merge(vector<int>& a, int left, int mid, int right)
    {
        int i = left;
        int j = mid+1;
        int k = 0;
        //在merge函数中定义工具数组b
        vector<int> b(right-left+1);
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i<=mid)
            b[k++] = a[i++];
        while(j<=right)
            b[k++] = a[j++];
        for(int i=0;i<k;i++)
            a[left+i] = b[i];
    }
};
```



##### 使用归并排序求解逆序数（或者显著逆序数）问题

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int>& v) {
        vector<int> tool_v(v.size(), 0);
        int count = solve(v,0,v.size()-1,tool_v);
        return count;
    }
private:
    int solve(vector<int>& a, int left, int right, vector<int>& b)
    {
        int cnt = 0;
        if(right>left)
        {
            int mid = (right+left)/2;
            cnt += solve(a, left, mid, b);
            cnt += solve(a, mid+1, right, b);
            cnt += merge(a, left, mid, right, b);
        }
        return cnt;
    }
    int merge(vector<int>& a,int left, int mid, int right, vector<int>& b)
    {
        int i = mid;
        int j = right;
        int merge_count = 0;
        while(i>=left&&j>=mid+1)
        {
            if(a[i]>a[j])//此处是计算显著逆序数，具有一般性
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

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    Solution s;
    int count = s.InversePairs(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    cout<<"count:"<<count<<endl;
    return 0;
}



//和归并排序一样，可以对工具数组进行简化
class Solution {
public:
    int InversePairs(vector<int>& v) {
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
            if(a[i]>a[j])//此处是计算显著逆序数，具有一般性
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



##### 使用归并排序求解区间和问题（leetcode327题）

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
            for(int j = i;j<nums.size();j++)
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
        //这里相加之后，后续计算i,j之间的和时，只需要计算sum[j]-sum[i]即可，便于使用归并排序
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



#### 2.快速排序

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void QuickSortOrder(vector<int>& v)
    {
        solve(v, 0, v.size()-1);
    }
private:
    void solve(vector<int>& a, int start, int end)
    {
        if(start>=end)
            return;
        
        int i = start;
        int j = end;
        int pivot = a[i];

        while(i<j)
        {
            while(a[j]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);

            while(a[i]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        solve(a, start, i-1);
        solve(a, j+1, end);
    }
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    Solution s;
    s.QuickSortOrder(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}
```

快排一般用在求解最小的第k个数中，当题目中出现这样的字眼时，可以考虑使用快排，如剑指offer第29题以及leetcode973题。

寻找第k大数可以用快排的思想：

```c++
//使用快速排序寻找第k大的数
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int find_max_k(vector<int>& v, int k)
    {
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }
private:
    int solve(vector<int>& a, int start, int end, int k)
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
    int divide(vector<int>& a, int start, int end)
    {
        if(start>=end)
            return start;

        int i = start;
        int j = end;
        int pivot = a[start];

        while(i<j)
        {
            while(a[j]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        return i;//此时i==j
    }
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    Solution s;
    int result = s.find_max_k(v, 2);
    cout<<result<<endl;
    //由于s.find_max函数中的v写的引用，所以会对原数组的顺序产生影响
    //去除引用就会输出原数组
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}
```



也可以用上述的寻找第k大数代码来寻找一个数组前k小的数：

```c++
#include<iostream>
#include<vector>

using namespace std;

//只需依次寻找最小的k个数即可
class Solution {
public:
    vector<int> smallestK(vector<int> input, int k) {
        vector<int> result;
        for(int i=0;i<k;i++)
        {
            int index = input.size() - i;
            int ith_min = find_max_k(input, index);
            result.push_back(ith_min);
        }
        return result;
    }
private:
    int find_max_k(vector<int> v, int k)
    {
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }

    int solve(vector<int>& a, int start, int end, int k)
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

    int divide(vector<int>& a, int start, int end)
    {
        if(start>=end)
            return start;

        int i = start;
        int j = end;
        int pivot = a[start];

        while(i<j)
        {
            while(a[j]>pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        return i;//此时i==j
    }

    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    vector<int> result = s.smallestK(v, 4);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}
```



### 三、c++中字符串，字符和int的相互转换

#### 1.char和int的转换

（1）char转int

```c++
char c = '0';

int i1 = c;                    // 48
int i2 = c - 0;                // 48
int i3 = c - '0';              // 0
int i4 = c + '0';              // 96
```

（2）int转char

```c++
int i = 5;
char c4 = i + '0';            // '5'
```



#### 2.string和int的转换

（1）int转string

```c++
int a = 7;
float b = 3.14;
double c = 1.415649363;
string a_str = to_string(a);
string b_str = to_string(b);
string c_str = to_string(c);
```

（2）string转int

```c++
int stoi (string str);
float stof(string str);
long stol(string str);
long long stoll(string str);

string a_str = "123";
string b_str = "23.4";
int a = stoi(a_str);
int b = stof(b_str);
```



#### 3.string与char*的转换

（1）string转char*

```c++
string str="world";
//使用char * p=(char*)str.c_str()效果相同
const char *p = str.c_str();
```

（2）char*转string

```c++
string s;
char *p = "helloworld";
s = p;
```



#### 4.string与char[]的转换

（1）string转char[]

```c++
string pp = "helloworld";
char p[20];
int i;
for( i=0;i<pp.length();i++)
    p[i] = pp[i];
p[i] = '\0';                  //添加结束符
```

（2）char[]转string

```c++
string s;
char p[20] = "helloworld";
s = p;
```



#### 5.char[]与char*的转换

（1）char[]转char*

```c++
char pp[20] = "helloworld";
char* p = pp;
```

（2）char*转char[]

```c++
char arr[20];
char* tmp = "helloworld";
strcpy(arr, tmp);
```



#### 6.char与string的转换

（1）char转string

```c++
char a = 'd';
string s(1,a);//1代表字符的长度
cout<<s<<endl;//"d"
```

（2）string转char（string中任意一个元素就是char）

```c++
string str = "abc";
char a = str[0];
```



### 四、初始化vector等数据结构

#### 1.初始化vector

```c++
vector<int> v(n);//v中有n个元素，默认为0；
vector<int> v(n,1);//v中有n个元素，全为1；
vector<int> v{2};//v中有一个元素，为2；

vector<vector<int>> v;
v.push_back({i,j});//一次性进一个vector数组{i,j}；
vector<vector<int>> v(n);//v中有n个二维数组，不过没有赋值，可以使用push_back进行赋值
vector<vector<int>> flag(m, vector<int>(n, 0)); //定义m*n全0二维数组
```



#### 2.初始化string

```c++
//初始化一个string，指定长度，每个位置上都是空字符
string result(10, ' ');
```



### 五、string相关操作

#### 1.string求子串

```c++
int main()
{
    string s = "abcdefg";
    string sub_s = s.substr(0,3); //从0开始数3个字符
    cout<<sub_s<<endl; // "abc"
    return 0;
}
```

