# 牛客题霸



#### NC1.以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string solve(string s, string t) {
        int length_s = s.length();
        int length_t = t.length();
        int L = max(length_s, length_t);
        //保证s比t长
        if(length_s<length_t)
        {
            string temp = t;
            t = s;
            s = temp;
        }
        //填充一个新的字符串t1，使得比s短的部分填充为0，其余和t一致
        string t1(s.length(), '0');
        int l = s.length() - t.length();
        //cout<<l<<endl;
        for(int i=0;i<s.length();i++)
        {
            if(i<l)
                ;
            else
                t1[i] = t[i-l];
        }
        //cout<<s<<endl;
        //cout<<t1<<endl;
        int flag = 0;//进位标志
        string result(L + 1, '0');
        for(int i = L;i>=1;i--)
        {
            int r = (s[i-1]-'0')+(t1[i-1]-'0') + flag;
            if(r>=10)
            {
                flag = 1;
                result[i] = r%10 + '0';
            }
            else
            {
                flag = 0;
                result[i] = r + '0';
            }
        }
        //cout<<result<<endl;
        //处理result第一位
        if(flag==1)
        {
            result[0] = 1 + '0';
            return result;
        }
        else
        {
            string Result(s.length(), '0');
            for(int i=0;i<s.length();i++)
                Result[i] = result[i+1];
            return Result;
        }
    }
};


int main()
{
    string s = "99236";
    string t = "23444";
    Solution S;
    string result = S.solve(s,t);
    cout<<result<<endl;
    return 0;
}
```





#### NC3.对于一个给定的链表，返回环的入口节点，如果没有环，返回null。

```c++
#include<iostream>
#include<map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)
            return nullptr;
        map<ListNode*, int> ListNode_map;
        while(head)
        {
            ListNode_map[head]++;
            if(ListNode_map[head]==2)
                return head;
            head = head->next;
        }
        return nullptr;
    }
};
```







#### NC4.判断给定的链表中是否有环。如果有环则返回true，否则返回false。

```c++
#include<map>


// Definition for singly-linked list. 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullpter) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
            return false;
        map<ListNode*, int> ListNode_map;
        while(head)
        {
            ListNode_map[head]++;
            if(ListNode_map[head]==2)
                return true;
            head = head->next;
        }
        return false;
    }
};
```



#### NC5.二叉树根节点到叶子节点的所有路径

给定一个仅包含数字0−9 的二叉树，每一条从根节点到叶子节点的路径都可以用一个数字表示。例如根节点到叶子节点的一条路径是1→2→3,那么这条路径就用123 来代替。找出根节点到叶子节点的所有路径表示的数字之和，例如：

![img](https://uploadfiles.nowcoder.com/images/20200807/999991351_1596786228797_BC85E8592A231E74E5338EBA1CFB2D20)

这颗二叉树一共有两条路径，
根节点到叶子节点的路径 1→2 用数字12 代替
根节点到叶子节点的路径 1→3 用数字13 代替
所以答案为12+13=25

```c++
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
```



#### NC7.假设你有一个数组，其中第$i$个元素是股票在第$i$天的价格。

只有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        //维护一个历史最低点，把该历史最低点当成买入点
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



#### NC8.给定一个二叉树和一个值$sum$，请找出所有的根节点到叶子节点的节点值之和等于$sum$的路径。

```c++
#include<iostream>
#include<vector>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        find(root, sum);
        return result;
    }
private:
    vector<vector<int> > result;
    vector<int> path;
    void find(TreeNode* root, int sum)
    {
        if(root==nullptr)
            return;
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&root->val==sum)
            result.push_back(path);
        else
        {
            if(root->left!=nullptr)
                find(root->left, sum-root->val);
            if(root->right!=nullptr)
                find(root->right, sum-root->val);
        }
        path.pop_back();//将当前节点pop出来，维护当前路径数组
    }
};
```



#### NC13.二叉树的最大深度

求给定二叉树的最大深度，最大深度是指树的根结点到最远叶子结点的最长路径上结点的数量。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr).right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

//递归
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if(root==nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//非递归
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if(root==nullptr)
            return 0;
        q.push(root);
        int depth = 0;
        while(!q.empty())
        {
            int size = q.size();
            depth++;
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return depth;
    }
private:
    queue<TreeNode*> q;
};
```



#### NC14.二叉树的之字形程序遍历。

给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        queue<TreeNode*> q;
        q.push({root});
        int flag = 1;//1表示该层正序遍历，0表示该层逆序遍历
        while(!q.empty())
        {
            vector<int> layer;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flag==0)
                reverse(layer.begin(), layer.end());
            flag = 1 - flag;
            result.push_back(layer);
        }
        return result;
    }
};
```



#### NC15.给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> result;
        if(!root)
            return result;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            result.push_back(v);
        }
        return result;
    }
private:
    queue<TreeNode*> q;
};
```





#### NC16.给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）

```c++
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//以下代码有问题
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->right==nullptr&&root->left==nullptr)
            return true;
        if(root->right!=nullptr&&root->left!=nullptr)
        {
            return (root->left->val==root->right->val)&&(isSymmetric(root->left))&&(isSymmetric(root->right));
        }
        return false;
    }
};
*/

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr&&right==nullptr)
            return true;
        if(left==nullptr||right==nullptr)
            return false;
        else
            return (left->val==right->val)&&symmetric(left->left, right->right)&&symmetric(left->right, right->left);
    }
};

//非递归，采用层次遍历来验证每层是否对称
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        if((root->left==nullptr)&&(root->right==nullptr))
            return true;
        if((root->left==nullptr)||(root->right==nullptr))
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            if(size%2==1&&size!=1)
                return false;
            vector<TreeNode* > v =  pop(q);
            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = v[i];
                if(node1->left)
                    q.push(node1->left);
                if(node1->right)
                    q.push(node1->right);
                TreeNode* node2 = v[size - i - 1];
                if(!symmetric(node1, node2))
                    return false;
            }
        }
        return true;
    }
private:
    bool symmetric(TreeNode* node1, TreeNode* node2)
    {
        bool flag1, flag2;
        flag1 = (node1->left!=nullptr)&&(node2->right!=nullptr);
        flag2 = (node1->right!=nullptr)&&(node2->left!=nullptr);
        if((node1->left==nullptr)&&(node2->right==nullptr)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag1&&(node1->left->val==node2->right->val)&&(node1->right==nullptr)&&(node2->left==nullptr))
            return true;
        if(flag2&&(node1->right->val==node2->left->val)&&(node1->left==nullptr)&&(node2->right==nullptr))
            return true;
        if(flag1&&flag2&&(node1->left->val==node2->right->val)&&(node1->right->val==node2->left->val))
            return true;
        return false;
    }

    vector<TreeNode*> pop(queue<TreeNode*> &q)
    {
        vector<TreeNode*> v;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node);
        }
        return v;
    }
};
```



#### NC17.最长回文子串

对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。给定字符串**A**以及它的长度**n**，请返回最长回文子串的长度。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//暴力求解
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int max_len = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                string sub_str = A.substr(i,j-i+1);
                //cout<<sub_str<<endl;
                if(IsPalindrome(sub_str)&&sub_str.size()>max_len)
                    max_len = sub_str.size();
            }
        return max_len;
    }
private:
    bool IsPalindrome(string s)
    {
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
};


//动态规划
//边界条件：(1)dp[i][i]=true;(2)dp[i][i+1]=(str[i]==str[i+1])?true:false;
//状态转移方程：dp[i][j]=true if(dp[i+1][j-1]&&str[i]==str[j]),dp[i][j]=false if(str[i]!=str[j])
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        string ans = "";
        //k = j-i
        for(int k=0;k<n;k++)
            for(int i=0;i+k<n;i++)
            {
                int j = i+k;
                if(k==0)
                    dp[i][j] = true;
                else if(k==1)
                    dp[i][j] = (A[i]==A[j]);
                else
                    dp[i][j] = (A[i]==A[j])&&dp[i+1][j-1];
                if(dp[i][j]&&k+1>ans.size())
                    ans = A.substr(i,k+1);
            }
        return ans.size();
    }
};


int main()
{
    string s = "babcaaccabab";
    Solution solu;
    int result = solu.getLongestPalindrome(s, 12);
    cout<<result<<endl;
    return 0;
}
```





#### NC18.有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于300。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        //先转置
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        //再根据竖直线中心对称
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
            {
                int tmp = mat[i][j];
                mat[i][j] = mat[i][n-1-j];
                mat[i][n-1-j] = tmp;
            }
        return mat;
    }
};
```



#### NC19.给定一个数组arr，返回子数组的最大累加和

例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.题目保证没有全为负数的数据

```c++
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int size = arr.size();
        //dp[i]表示以arr[i]为最后一个数字的最长无重复子串的长度
        vector<int> dp(size);
        dp[0] = arr[0];
        for(int i=0;i<size;i++)
        {
            dp[i] = max(dp[i-1] + arr[i], arr[i]);
        }
        //找dp中最大的数
        int M = INT_MIN;
        for(int i=0;i<size;i++)
            M = max(M, dp[i]);
        return M;
    }
};
```



#### NC22.给出两个有序的整数数组A和B，请将数组B合并到数组 A中，变成一个有序的数组。注意：可以假设A数组有足够的空间存放B数组的元素， A和 B中初始的元素数目分别为 m和 n。

```c++
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = m-1;
        int b = n-1;
        for(int index=m+n-1;index>=0;index--)
        {
            if(a>=0&&b>=0)
            {
                if(A[a]>B[b])
                    A[index] = A[a--];
                else
                    A[index] = B[b--];
            }
            else if(b>=0)
                A[index] = B[b--];
        }
    }
};
```



#### NC24.删除有序链表中重复出现的元素

给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1→2→3→3→4→4→5, 返回1→2→5.
给出的链表为1→1→1→2→3, 返回2→3.

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* fake_head = new ListNode(0);//创建一个指向head的伪节点
        fake_head->next = head;
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



#### NC25.删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次。

```c++
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==nullptr) return head;
        ListNode* q = head;
        while(q->next){
            if(q->next->val==q->val) q->next=q->next->next;
            else q=q->next;
        }
        return head;
    }
};
```





#### NC33.将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的，且合并后新链表依然有序。

```c++
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* fake_head = new ListNode(0);
        ListNode* cur = fake_head;
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
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return fake_head->next;
    }
};
```



#### NC34.一个机器人在m×n大小的地图的左上角（起点）。机器人每次向下或向右移动。机器人要到达地图的右下角（终点）。可以有多少种不同的路径从起点走到终点？

```c++
#include<iostream>
#include<vector>

using namespace std;

//数学方法，排列组合(不知道为什么会发生浮点错误)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        if(n==1)
            return 1;
        if(m==1)
            return 1;
        long count = J(m+n-2)/(J(m-1)*J(n-1));
        return count;
    }
private:
    long J(long n)
    {
        if(n<=1)
            return 1;
        return n*J(n-1);
    }
};


//数学方法，排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        if(m==1||n==1)
            return 1;
        long long result = 1;//防止溢出
        int N = m+n-2;
        int M = min(n-1,m-1);
        //cout<<M<<" "<<N<<endl;
        for(int i=1;i<=M;i++)
        {
            result = result*(N-i+1)/i;
        }
        return int(result);
    }
};


//动态规划,dp[i][j]表示从(0,0)元素出发，到(i,j)的路径有多少种
//dp[i][j] = dp[i-1][j]+dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        vector<vector<int>> dp(m, vector<int>(n,1));//生成m*n全1阵
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```



#### NC35.最小编辑代价

给定两个字符串str1和str2，再给定三个整数ic，dc和rc，分别代表插入、删除和替换一个字符的代价，请输出将str1编辑成str2的最小代价。

```c++
#include<iostream>
#include<vector>

using namespace std;

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
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            dp[i][0] = i*dc;
        for(int j=1;j<=n;j++)
            dp[0][j] = j*ic;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int Insert = dp[i][j-1] + ic;
                    int Delete = dp[i-1][j] + dc;
                    int Replace = dp[i-1][j-1] + rc;
                    dp[i][j] = min(min(Insert, Delete),Replace);
                }
            }
        return dp[m][n];
    }
};
```



#### NC37.给出一组区间，请合并所有重叠的区间，请保证合并后的区间按区间起点升序排列。

```c++
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval(): start(0),end(0){}
    Interval(int start, int end): start(start),end(end){}
};

class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        int size = intervals.size();
        if(size==0)
            return result;
        sort(intervals.begin(),intervals.end(),[&](Interval x, Interval y){
            return x.start<y.start;
        });//按照第一位从小到大排序
        for(int i=0;i<size-1;i++)
        {
            Interval I = intervals[i];
            Interval J = intervals[i+1];
            if(I.end<J.start)
                result.push_back(I);
            else
            {
                int left = min(I.start, J.start);
                int right = max(I.end, J.end);
                intervals[i] = Interval();
                intervals[i+1] = Interval(left, right);
            }
        }
        result.push_back(intervals[size-1]);//处理最后一个区间
        return result;
    }
};
```



#### NC38.螺旋矩阵

给定一个m x n大小的矩阵（m行，n列），按螺旋的顺序返回矩阵中的所有元素。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if(matrix.size()==0||matrix[0].size()==0)
            return result;
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



#### NC41.给定一个数组arr，返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)。

```c++
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        int size = arr.size();
        map<int, int> arr_count;
        arr_count[arr[0]] = 0;//初始哈希中只有第一个元素
        int ML = 1;//初始最大长度为1
        int i=0;
        int j=1;//j=1是即将要添加的元素
        while(i<=j&&j<size)
        {
            if(arr_count.count(arr[j]))//如果当前哈希中有要添加的元素，那么从i一直删到与要添加的arr[j]不重复为止
            {
                //删除元素
                while(arr[i]!=arr[j])
                {
                    arr_count.erase(arr[i]);
                    i++;
                }
                i++;//删除到重复元素之后要再加1
            }
            //如果当前哈希中没有要添加的元素，那么直接加上arr[j]
            arr_count[arr[j]] = j;
            ML = ML>arr_count.size()?ML:arr_count.size();
            j++;
        }
        return ML;
    }
};
```



#### NC45.分别按照二叉树先序，中序和后序打印所有的节点。

```c++
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};


class Solution
{
public:
    vector<vector<int>> threeOrders(TreeNode* root)
    {
        vector<vector<int>> result;
        Pre(root);
        result.push_back(pre);
        Mid(root);
        result.push_back(mid);
        Post(root);
        result.push_back(post);
        return result;
    }
private:
    vector<int> pre;
    vector<int> mid;
    vector<int> post;
    void Pre(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        pre.push_back(root->val);
        Pre(root->left);
        Pre(root->right);
    }
    void Mid(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        Mid(root->left);
        mid.push_back(root->val);
        Mid(root->right);
    }
    void Post(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
            return;
        Post(root->left);
        Post(root->right);
        post.push_back(root->val);
    }
};
```



#### NC46.加起来和为目标值的组合

给出一组候选数 C 和一个目标数 T ，找出候选数中起来和等于 T 的所有组合。C 中的每个数字在一个组合中只能使用一次。

```c++
#include<iostream>
#include<vector>

using namespace std;

//超时，思路应该没问题
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



#### NC48.在转动过的有序数组中寻找目标值

给出一个转动过的有序数组，你事先不知道该数组转动了多少(例如,0 1 2 4 5 6 7可能变为4 5 6 7 0 1 2).在数组中搜索给出的目标值，如果能在数组中找到，返回它的索引，否则返回-1。假设数组中不存在重复项。

```c++
class Solution {
public:
    int search(int* A, int n, int target)
    {
        if(n==0)
            return -1;
        int left = 0;
        int right = n - 1;
        int mid;
        while(left<right)
        {
            int mid = (left + right) / 2;
            //左边有序
            if(A[left]<A[mid])
            {
                if(A[left]<=target&&target<=A[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            //右边有序
            else
            {
                if(A[mid+1]<=target&&target<=A[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        if(A[left]==target)
            return left;
        else
            return -1;
    }
};
```



#### NC50.将给出的链表中的节点每\ k *k* 个一组翻转，返回翻转后的链表如果链表中的节点数不是\ k *k* 的倍数，将最后剩下的节点保持原样。你不能更改节点中的值，只能更改节点本身，要求空间复杂度 $O(1)$。

例如：给定的链表是

1→2→3→4→5→null

对于k = 2，你应该返回2→1→4→3→5→null

对于k = 3，你应该返回3→2→1→4→5→null

对于k = 5，你应该返回5→4→3→2→1→null

```c++
#include<iostream>

using namespace std;

struct ListNode
{
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};
 

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(small_than_k(head, k))
            //长度小于k的链表直接返回
            return head;
        ListNode* head_copy = head;
        int count = 0;
        while(count<k-1)
        {
            count += 1;
            head_copy = head_copy->next;
        }
        //此时head_copy刚好到达第k个节点
        ListNode* new_head = head_copy->next;
        if(new_head==nullptr)
            //如果链表长度恰好为k，则直接反转链表
            return reverseList(head);
        //否则进行递归
        else
        {
            //断开第k个节点和第k+1个节点
            head_copy->next = nullptr;
            reverseList(head);
            //此时前k个节点中头结点为head_copy,尾节点为head
            head->next = reverseKGroup(new_head, k);
            return head_copy;
        }
    }
private:
    bool small_than_k(ListNode* head, int k)
    {
        //判断一个链表长度是否小于k
        int length = 0;
        while(head)
        {
            length += 1;
            head = head->next;
        }
        return length<k;
    }
    ListNode* reverseList(ListNode* head)
    {
        //反转链表(迭代写法，还有数组写法和递归写法，见leetcode206题)
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
```



#### NC51.合并$k$个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。 

```c++
//Definition for singly-linked list.
#include<iostream>
#include<vector>


struct ListNode
{     
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.size()==0)
            return nullptr;
        ListNode* L = lists[0];
        for(int i=1;i<lists.size();i++)
            L = merge2list(L, lists[i]);
        return L;
    }
private:
    ListNode* merge2list(ListNode* l1, ListNode* l2)
    {
        ListNode* fake_head = new ListNode(0);
        ListNode* cur = fake_head;
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
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return fake_head->next;
    }
};
```



#### NC52.给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
```c++
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*
//以下这种写法不正确，会漏判"([)]"这种案例
class Solution {
public:
    bool isValid(string s)
    {
        if(s.length()==0)
            return true;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
                s1.push(s[i]);
            if((s[i]==')')||(s[i]==']')||(s[i]=='}'))
                s2.push(s[i]);
        }
        if(s1.size()!=s2.size())
            return false;
        else
            while(!s1.empty())
            {
                char s1_ele = s1.top();
                char s2_ele = s2.top();
                if((s1_ele=='(')&&(s2_ele!=')'))
                    return false;
                if((s1_ele=='[')&&(s2_ele!=']'))
                    return false;
                if((s1_ele=='{')&&(s2_ele!='}'))
                    return false;
                s1.pop();
                s2.pop();
            }
            return true;
    }
private:
    stack<char> s1;
    stack<char> s2;
};
*/

//下面代码还是会段溢出，比如"()))"
class Solution {
public:
    bool isValid(string s)
    {
        if(s.length()==0)
            return true;
        if((s.length()%2==1))
            return false;//不加会发生sk溢出，比如"())"
        if((s[0]==')')||(s[0]==']')||(s[0]=='}'))
            return false;
        //cout<<"run here"<<endl;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
                sk.push(s[i]);
            else
            {
                // cout<<sk.top()<<endl;
                // cout<<s[i]<<endl;
                if((sk.top()=='(')&&(s[i]!=')'))
                    return false;
                else if((sk.top()=='[')&&(s[i]!=']'))
                    return false;
                else if((sk.top()=='{')&&(s[i]!='}'))
                    return false;
                else
                    sk.pop();
            }
        }
        if(sk.empty())
            return true;
        else
            return false;
    }
private:
    stack<char> sk;
};


class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        stack<char> st;
        for(int i=0;i<l;i++)
        {
        	if(s[i] == '(')
        		st.push(')');
        	else if(s[i] == '[')
        		st.push(']');
        	else if(s[i] == '{')
        		st.push('}');
        	else if(st.empty())
        		return false;
        	else if(st.top() != s[i])
        		return false;
        	else
        		st.pop();
		}
		return st.empty();
    }
};


int main()
{
    Solution s;
    string str = "()))";
    cout<<s.isValid(str)<<endl;
    return 0;
}
```



#### NC53.给定一个链表，删除链表的倒数第 n个节点并返回链表的头指针

例如，给出的链表为: 1→2→3→4→5, n= 2.删除了链表的倒数第 n个节点之后,链表变为1→2→3→5.

```c++
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



#### NC54.给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。

注意：

1. 三元组（a、b、c）中的元素必须按非降序排列。（即a≤b≤c）
2. 解集中不能包含重复的三元组。

```c++
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
```



#### NC55.最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

输入：

```
["abca","abc","abca","abc","abcc"]
```

输出：

```
"abc"
```

```c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int size = strs.size();
        if(size==0)
            return "";
        if(size==1)
            return strs[0];
        string result = strs[0];
        for(int i=1;i<size;i++)
        {
            result = match(result, strs[i]);
        }
        return result;
    }
private:
    string match(string s1, string s2)
    {
        int size = min(s1.size(), s2.size());
        int length;
        for(length = size;length>=0;length--)
        {
            if(s1.substr(0,length)==s2.substr(0,length))
                return s1.substr(0,length);
        }
        return "";
    }
};
```



#### NC57.反转数字

将给出的32位整数x翻转。
例1:x=123，返回321
例2:x=-123，返回-321

你有注意到翻转后的整数可能溢出吗？因为给出的是32位整数，则其数值范围为$[−2^{31}, 2^{31} − 1]$。翻转可能会导致溢出，如果反转后的结果会溢出就返回 0。

```c++
class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int reverse(int x) {
        // write code here
        long tmp = 0;
        //用一个long型的数表示翻转后的x，可能会溢出int
        long sum = 0;
        while(x!=0)
        {
            tmp = x%10;
            sum = sum*10 + tmp;
            x /=10;
        }
        if(sum>INT_MAX||sum<INT_MIN)
            return 0;
        return sum;
    }
};
```



#### NC59.矩阵的最小路径和

给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。

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



#### NC60.判断一棵树是否为搜索二叉树和完全二叉树

给定一棵二叉树，已经其中没有重复值的节点，请判断该二叉树是否为搜索二叉树和完全二叉树。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 $1$~$2^h$ 个节点。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode()
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        if(!root)
            return {true,true};
        vector<bool> result;
        result.push_back(IsSearch(root));
        result.push_back(IsComplete(root));
        return result;
    }
private:
    vector<int> v;
    void MidOrder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        MidOrder(root->left);
        v.push_back(root->val);
        MidOrder(root->right);
    }
    bool IsSearch(TreeNode* root)
    {
        MidOrder(root);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>v[i+1])
                return false;
        }
        return true;
    }

    //计算“如果是完全二叉树”的节点个数
    int count_node(TreeNode* root)
    {
        int count = 0;
        vector<int> node;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            node.push_back(tmp->val);
            //遇到空树，将队列中的树节点和当前已遍历过的节点个数相加之后之后再结束遍历
            if(tmp->left)
                q.push(tmp->left);
            else
            {
                count = node.size()+q.size();
                break;
            }
            if(tmp->right)
                q.push(tmp->right);
            else
            {
                count = node.size()+q.size();
                break;
            }
        }
        return count;
    }
    bool IsComplete(TreeNode* root)
    {
        int count = count_node(root);
        if(v.size()==count)
            return true;
        return false;
    }
};
```



#### NC61.给出一个整数数组，请在数组中找出两个加起来等于目标值的数。

给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的。

假设给出的数组中只存在唯一解，例如：给出的数组为 {20, 70, 110, 150},目标值为90，输出 index1=1, index2=2。

```c++
#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> v_map;
        vector<int> result;
        for(int i=0;i<numbers.size();i++)
        {
            int diff = target - numbers[i];
            if(v_map.count(diff)==1)
            {
                result.push_back(v_map[diff]);
                result.push_back(i+1);
                return result;
            }
            else
                v_map[numbers[i]]=i+1;
        }
        return result;
    }
};
```



#### NC69.输入一个链表，输出该链表中倒数第k个结点。如果该链表长度小于k，请返回空。

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

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here 
        ListNode* cur = pHead;
        ListNode* pre = pHead;
        k = k+1;//这样下面的while循环可以走k个节点
        while(k=k-1)
        {
            if(cur==nullptr)
                return nullptr;
            cur = cur->next;
        }
        while(cur)
        {
            pre = pre->next;
            cur = cur->next;
        }
        //此时pre指向倒数第k个节点
        return pre;
    }
};
```



#### NC72.操作给定的二叉树，将其变换为源二叉树的镜像。

```c++
#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x),left(left), right(right){}
};

class Solution
{
public:
    TreeNode* Mirror(TreeNode* pRoot)
    {
        if(pRoot==nullptr||(pRoot->left==nullptr&&pRoot->right==nullptr))
            return pRoot;
        mirror(pRoot);
        return pRoot;
    }
private:
    void mirror(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return;
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        mirror(pRoot->left);
        mirror(pRoot->right);
    }
};
```



#### NC78.输入一个链表，反转链表后，输出新链表的表头。

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



#### NC83.子数组的最大乘积

给定一个double类型的数组arr，其中的元素可正可负可0，返回子数组连续累乘的最大乘积。

```c++
#include<iostream>
#include<vector>

using namespace std;

//动态规划：
//dp[i]表示以arr[i]为结尾的连乘结果最大值
//dp[i] = max{dp[i-1]*arr[i], arr[i]}
//该思路和求连续子数组的和最大是一样的，通过73/100组用例，因为乘法会因为符号的差异导致漏算，比如[-3,4,-5]，
//dp结果为[-3,4,-5]，但实际上-3和-5的符号可以相互抵消，使得乘积结果更大，所以需要考虑数值的正负。
class Solution {
public:
    double maxProduct(vector<double> arr) {
        int size = arr.size();
        vector<double> dp(size);
        dp[0] = arr[0];
        double M = dp[0];
        for(int i=1;i<size;i++)
        {
            dp[i] = max(dp[i-1]*arr[i], arr[i]);
            M = max(dp[i], M);
        }
        // for(int i=0;i<size;i++)
        // {
        //     cout<<dp[i]<<endl;
        // }
        return M;
    }
};

//沿着乘法的特性看，如果a[i]为负数，那么考虑dp[i]时，dp[i-1]越大dp[i]结果越小，dp[i-1]越小dp[i]结果越大。
//所以只需要同时保存最大值和最小值，就可以写出状态转移方程了。
//a[i] > 0时：
//dp_max[i] = max(a[i], a[i]*dp_max[i-1])
//dp_min[i] = min(a[i], a[i]*dp_min[i-1])
//a[i] < 0时：
//dp_max[i] = max(a[i], a[i]*dp_min[i-1])
//dp_min[i] = min(a[i], a[i]*dp_max[i-1])
//a[i]=0时，max和min肯定是0。
class Solution {
public:
    double maxProduct(vector<double> arr) {
        int size = arr.size();
        vector<double> dp_max(size);
        vector<double> dp_min(size);
        dp_max[0] = arr[0];
        dp_min[0] = arr[0];
        double M = dp_max[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i]>0)
            {
                dp_max[i] = max(dp_max[i-1]*arr[i], arr[i]);
                dp_min[i] = min(dp_min[i-1]*arr[i], arr[i]);
            }
            else
            {
                dp_max[i] = max(dp_min[i-1]*arr[i], arr[i]);
                dp_min[i] = min(dp_max[i-1]*arr[i], arr[i]);
            }
            M = max(dp_max[i], M);
        }
        // for(int i=0;i<size;i++)
        // {
        //     cout<<dp[i]<<endl;
        // }
        return M;
    }
};
```



#### NC86.矩阵元素查找

已知int一个有序矩阵**mat**，同时给定矩阵的大小**n**和**m**以及需要查找的元素**x**，且矩阵的行和列都是从小到大有序的。设计查找算法返回所查找元素的二元数组，代表该元素的行号和列号(均从零开始)。保证元素互异。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        for(int i=n-1,j=0;i>=0&&j<m;)
        {
            if(mat[i][j]==x)
                return {i,j};
            else if(mat[i][j]<x)
                j++;
            else
                i--;
        }
        return {-1,-1};
    }
};
```



#### NC88.有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKth(vector<int> v, int n, int k) {
        // write code here
        int result = solve(v, 0, v.size()-1, k);
        return result;
    }
private:
    int solve(vector<int>& a, int start, int end, int k)
    {
        int mid = divide(a, start, end);
        int length_of_right = end - mid;
        if(length_of_right==k-1)
            return a[mid];
        else if(length_of_right>k-1)
            return solve(a, mid+1, end, k);
        else
            return solve(a, start, mid-1, k-length_of_right-1);
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
            while(a[j]>=pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<=pivot&&i<j)
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
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    Solution s;
    int result = s.findKth(v,5,3);
    cout<<result<<endl;
    return 0;
}
```



#### NC90.实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

```c++
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> getMinStack(vector<vector<int> >& op) {
        vector<int> result;
        for(int i=0;i<op.size();i++)
        {
            if(op[i][0]==1)
                Push(op[i][1]);
            else if(op[i][0]==2)
                Pop();
            else
                result.push_back(getMin());
        }
        return result;
    }
private:
    stack<int> s;
    stack<int> s_min;
    void Push(int x)
    {
        s.push(x);
        if(s_min.empty()||s_min.top()>=x)
            s_min.push(x);
    }
    void Pop()
    {
        if(s.top()==s_min.top())
            s_min.pop();
        s.pop();
    }
    int getMin()
    {
        return s_min.top();
    }
};
```



#### NC91.给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）

这一题没有AC，但思路应该没问题，先求该数组最长递增子序列的长度M，再找长度为M且字典序最小的子序列数组。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        // write code here
        int size = arr.size();
        //dp[i]表示以第i个元素结尾的最长的递增子序列长度
        vector<int> dp(size, 1);
        int M = 1;//全局最长递增子序列长度
        for(int i=1;i<size;i++)
        {
            for(int j=0;j<i;j++)
                if(arr[i]>arr[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    M = max(M, dp[i]);
                }
        }
        
        vector<int> result;
        //依次计算dp中数值为M,M-1,,M-2,...,1，且在arr最小的数，保证对应的索引值可以依次递减
        int up = dp.size();
        int index = up;
        for(int m = M;m>=1;m--)
        {
            int value = INT_MAX;
            //只在[0,up]中寻找，因为长度为m的为up,当寻找长度为m-1的时候可以限定范围[0,up]
            for(int i=0;i<up;i++)
            {
                if(dp[i]==m&&arr[i]<value)
                {
                    index = i;
                    value = arr[i];
                }
            }
            up = index;
            result.push_back(value);
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
```



#### NC101.从0,1,2,...,n这n+1个数中选择n个数，组成有序数组，请找出缺失的那个数，要求O(n)尽可能小。

```c++
class Solution {
public:
    /**
     * 找缺失数字
     * @param a int整型一维数组 给定的数字串
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        for(int i=0;i<aLen-1;i++)
        {
            if(a[i+1]-a[i]!=1)
                return a[i] + 1;
        }
        return a[aLen-1] + 1;
    }
};
```



#### NC102.最近公共祖先

给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。 

```c++
#include<iostream>

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
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return dfs(root, o1, o2)->val;
    }
private:
    TreeNode* dfs(TreeNode* root, int o1, int o2)
    {
        //如果当前节点为空，或者节点值等于o1或者o2，则直接返回该节点
        if(root==nullptr||root->val==o1||root->val==o2)
            return root;
        //遍历左子树
        TreeNode* left = dfs(root->left, o1, o2);
        //遍历右子树
        TreeNode* right = dfs(root->right, o1, o2);
        //如果左右子树不为空，说明左右子树(或者左右子树下面的子节点)分别包含o1或者o2
        if(left!=nullptr&&right!=nullptr)
            return root;
        //如果左右子树均为空，则返回空
        //如果左右子树有一个不空，则返回不空的那个，不空的(或者其下面的子节点)一定包含o1或者o2，空的(及其下面的子节点)一定不包含o1或者o2
        return left!=nullptr?left:right;
    }
};
```



#### NC103.写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

```c++
class Solution {
public:
    string solve(string str) {
        // write code here
        int length = str.size();
        if(length==0)
            return str;
        int i = 0;
        int j = length - 1;
        while(i<j)
        {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i++;
            j--;
        }
        return str;
    }
};
```



#### NC105.请实现有重复数字的升序数组的二分查找。给定一个 元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

这道题是返回最左边的索引，参考leetcode34题，还可以返回最右边的索引。

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size()-1;
        int ans = 0;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]>=target)
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        if(ans>=0&&ans<nums.size()&&nums[ans]==target)
            return ans;
        return -1;
    }
};
```



#### NC107.寻找峰值

山峰元素是指其值大于或等于左右相邻值的元素。给定一个输入数组nums，任意两个相邻元素值不相等，数组可能包含多个山峰。找到索引最大的那个山峰元素并返回其索引。假设 nums[-1] = nums[n] = -∞。

```c++
class Solution {
public:
    /**
     * 寻找最后的山峰
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here
        if(a[aLen-1]>a[aLen-2])
            return aLen-1;
        for(int i=aLen-2;i>=1;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])
                return i;
        }
        if(a[0]>a[1])
            return 0;
        //不会运行，为了通过编译
        return 0;
    }
};
```



#### NC109.给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。岛屿: 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。

```c++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//递归
class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i, j, grid.size(), grid[0].size(), grid);
                    count++;
                }
            }
            return count;
    }
private:
    int DFS(int i, int j, int m, int n, vector<vector<char>>& grid)
    {
        if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0')
            return 0;
        grid[i][j] = '0';
        DFS(i-1,j,m,n,grid);
        DFS(i+1,j,m,n,grid);
        DFS(i,j-1,m,n,grid);
        DFS(i,j+1,m,n,grid);
        return 0;
    }
};


//非递归(超时)
class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                    count++;
                    zeros(grid,q);
                }
            }
        return count;
    }
private:
    queue<vector<int>> q;
    int zeros(vector<vector<char>>& grid, queue<vector<int>>& q)
    {
        while(!q.empty())
        {
            vector<int> index = q.front();
            q.pop();
            int i = index[0];
            int j = index[1];
            grid[i][j]=='0';
            if(!fit(i-1,j,grid.size(),grid[0].size(),grid))
                q.push({i-1,j});
            if(!fit(i+1,j,grid.size(),grid[0].size(),grid))
                q.push({i+1,j});
            if(!fit(i,j-1,grid.size(),grid[0].size(),grid))
                q.push({i,j-1});
            if(!fit(i,j+1,grid.size(),grid[0].size(),grid))
                q.push({i,j+1});
        }
        return 0;
    }
    bool fit(int i, int j, int m, int n, vector<vector<char>> grid)
    {
        return (i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0');
    }
};
```



#### NC119.给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。如果K>数组的长度，那么返回一个空的数组。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.size()<k)
            return result;
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
        int length_of_right = end - mid;
        if(length_of_right==k-1)
            return a[mid];
        else if(length_of_right>k-1)
            return solve(a, mid+1, end, k);
        else
            return solve(a, start, mid-1, k-length_of_right-1);
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
            while(a[j]>=pivot&&j>i)
                j--;
            swap(a[i], a[j]);
            while(a[i]<=pivot&&i<j)
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
```



#### NC129.阶乘末尾0的数量

给定一个非负整数 $N$，返回 $N!$ 结果的末尾为 $0$ 的数量。$N!$ 是指自然数 $N$ 的阶乘,即:$N!=1*2*3…(N-2)*(N-1)*N$。

```c++
//观察阶乘结果可知，n!末尾0的数量就是看n!中可以拆出多少个5，拆出的2的个数肯定比5多，所以不用考虑2
//5中可以拆出1个5,25可以拆出两个5,125中可以拆出3个5，可以类推出前125个数阶乘中5的个数
//5->1,10->2,15->3,20->4,25->6
//30->7,35->8,40->9,45->10,50->12
//55->13,60->14,65->15,70->16,75->18
//80->19,85->20,90->21,95->22,100->24
//105->25,110->26,115->27,120->28,125->31,...以此类推
//可以发现有代码中的规律
class Solution {
public:
    /**
     * the number of 0
     * @param n long长整型 the number
     * @return long长整型
     */
    long long thenumberof0(long long n) {
        // write code here
        long long count = 0;
        while(n>0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};
```



#### NC134.假定你知道某只股票每一天价格的变动。你最多可以同时持有一只股票。但你可以无限次的交易（买进和卖出均无手续费）。请设计一个函数，计算你所能获得的最大收益。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            int diff = prices[i+1]-prices[i];
            if(diff>0)
                max_profit += diff;
        }
        return max_profit;
    }
};
```





#### NC135.假定你知道某只股票每一天价格的变动。你最多可以同时持有一只股票。但你最多只能进行**两次**交易（一次买进和一次卖出记为一次交易。买进和卖出均无手续费）。请设计一个函数，计算你所能获得的最大收益。

```c++
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

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



#### NC136.输出二叉树的右视图

请根据二叉树的前序遍历，中序遍历恢复二叉树，并打印出二叉树的右视图。（右视图是二叉树每层的最右边的节点）

```c++
#include<iostream>
#include<vector>
#include<queue>

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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        //先重建二叉树
        TreeNode* head = reconstruct(xianxu, zhongxu);
        //再输出该二叉树的右视图，即每一层最右边的节点
        vector<int> result = rightview(head);
        return result;
    }
private:
    //二叉树所有节点的值互不相同才可以用下面的函数重建
    TreeNode* reconstruct(vector<int>& pre, vector<int>& mid)
    {
        int size = pre.size();
        if(size==0)
            return nullptr;
        //创建根节点
        TreeNode* head = new TreeNode(0);
        head->val = pre[0];
        //在中序遍历中寻找根节点
        int index = 0;
        for(int i=0;i<size;i++)
        {
            if(mid[i]==pre[0])
            {
                index = i;
                break;
            }
        }
        //根据找到的根节点划分左右子树的先序和中序数组
        vector<int> l_pre, l_mid, r_pre, r_mid;
        for(int i=0;i<index;i++)
        {
            l_pre.push_back(pre[i+1]);
            l_mid.push_back(mid[i]);
        }
        for(int i=index+1;i<size;i++)
        {
            r_pre.push_back(pre[i]);
            r_mid.push_back(mid[i]);
        }
        //递归重建当前节点的左右子树
        head->left = reconstruct(l_pre,l_mid);
        head->right = reconstruct(r_pre, r_mid);
        
        return head;
    }

    vector<int> rightview(TreeNode* head)
    {
        vector<int> result;
        if(head==nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(head);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* root = q.front();
                q.pop();
                if(i==(size-1))
                    result.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return result;
    }
};
```



#### NC140.排序

给定一个数组，请你编写一个函数，返回该数组排序后的形式。

```c++
#include<iostream>
#include<vector>

using namespace std;

//暴力冒泡
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        int size = arr.size();
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
            {
                if(arr[i]>arr[j])
                    swap(arr[i], arr[j]);
            }
        return arr;
    }
private:
    void swap(int& x, int& y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};

//归并排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        solve(arr, 0, arr.size()-1);
        return arr;
    }
private:
    void solve(vector<int>& a, int left, int right)
    {
        if(left<right)
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


//快速排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        solve(arr, 0, arr.size()-1);
        return arr;
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
            while(a[j]>=pivot&&j>i)
                j--;
            swap(a[i],a[j]);
            while(a[i]<=pivot&&i<j)
                i++;
            swap(a[i], a[j]);
        }
        solve(a, start, i-1);
        solve(a, j+1, end);
    }
    void swap(int& x, int& y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};
```



#### NC144.不相邻最大子序列和

给你一个$n（1\leq n\leq10^5）$，和一个长度为n的数组，在不同时选位置相邻的两个数的基础上，求该序列的最大子序列和（挑选出的子序列可以为空）。

```c++
#include<iostream>
#include<vector>

using namespace std;

//动态规划，类似于leetcode中的打家劫舍问题
//dp[i]表示i索引元素及之前的不相邻子序列最大和
//dp[i] = max{dp[i-1],dp[i-2]+array[i]},当前索引i取或者不取
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算
     * @param n int整型 数组的长度
     * @param array int整型vector 长度为n的数组
     * @return long长整型
     */
    long long subsequence(int n, vector<int>& array) {
        // write code here
        //dp[i]表示i索引元素及之前的不相邻子序列最大和
        vector<long long> dp(n+1);
        dp[0] = max(0,array[0]);
        dp[1] = max(dp[0],(long long)array[1]);
        for(int i=2;i<=n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+array[i]);
        }
        return dp[n-1];
    }
};
```



#### NC145.01背包

已知一个背包最多能容纳物体的体积为$V$，现有$n$个物品第$i$个物品的体积为$v_i$第$i$个物品的重量为$w_i$。求当前背包最多能装多大重量的物品。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        int k = vw.size();//k个物品
        //dp[i][v]表示包空v时，前i个物品的最大重量
        //dp[i][v]=max{dp[i-1][v], dp[i-1][v-vi] + wi}
        vector<vector<int>> dp(k+1, vector<int>(V+1,0));
        for(int i=1;i<=k;i++)
            for(int v=1;v<=V;v++)
            {
                //如果当前空的空间小于当前物品的重量，那么不放当前的物品
                if(v-vw[i-1][0]<0)
                    dp[i][v] = dp[i-1][v];
                else
                    dp[i][v] = max(dp[i-1][v], dp[i-1][v-vw[i-1][0]] + vw[i-1][1]);
            }
        return dp[k][V];
    }
};
```



#### NC151.最大公约数

我们用辗转相除法（又称欧几里得算法）来计算两个数的最大公约数 (Greatest Common Divisor)所以下文用gcd(a,b)表示a和b的最大公约数。

先举一个例子：
假如需要求 434 和 652 的最大公约数,用欧几里得算法，是这样进行的：
434 / 652 = 0 (余 434)
652 / 434 = 1(余218)
434 / 218 = 216(余2)
216 / 2 = 108 (余0)
以除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数，所以就得出了 434 和 652 的最大公约数 2。

**算法的核心其实是** ：![img](https://www.nowcoder.com/equation?tex=gcd(a%2Cb)%20%3D%20gcd(b%2Ca%20%5Cbmod%20b)&preview=true)

然后我们考虑，对于两个数 ![img](https://www.nowcoder.com/equation?tex=a%E3%80%81b&preview=true) ， 如果![img](https://www.nowcoder.com/equation?tex=a%5C%25b%3D%3D0&preview=true)的话,那这两个数的最大公约数是 ![img](https://www.nowcoder.com/equation?tex=b&preview=true)

```c++
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求出a、b的最大公约数。
     * @param a int 
     * @param b int 
     * @return int
     */
    int gcd(int a, int b) {
        // write code here
        if(a%b==0)
            return b;
        else
            return gcd(b, a%b);
    }
};
```



#### NC156.数组中只出现一次的数（其他数出现k次）

给定一个整型数组 arr 和一个整数 k(k>1)。已知 arr 中只有 1 个数出现一次，其他的数都出现 k 次。请返回只出现了 1 次的数。

```c++
#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr intvector 
     * @param k int 
     * @return int
     */
    int foundOnceNumber(vector<int>& arr, int k) {
        // write code here
        map<int, int> arr_count;
        for(int i=0;i<arr.size();i++)
            arr_count[arr[i]]++;
        for(map<int, int>::iterator it = arr_count.begin();it!=arr_count.end();it++)
            if(it->second==1)
                return it->first;
        return 0;
    }
};
```

