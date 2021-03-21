# JianZhi_offer_67



**牛客网剑指offer中的题，面试手写代码基本上都是直接写类中的函数**

#### 1.二维数组查找，在一个二维数组中(每个一维数组的长度相同)，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
```c++
//二维数组查找
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <vector>

using namespace std;

class Solution { 
public:
	bool Find(int target,vector<vector<int> > array) {
		int rowCount = array.size();
		int colCount = array[0].size();
		int i,j;
		for(i=rowCount-1,j=0;i>=0&&j<colCount;)
		{
			if(target == array[i][j])
				return true;
			if(target < array[i][j])
			{
				i--;
				continue;
			}
			if(target > array[i][j])
			{
				j++;
				continue;
			}
		}
		return false;
	}
};


int main()
{
	vector<int> a;
	vector<int> b;
	vector<vector<int> >c;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	c.push_back(a);
	c.push_back(b);
	Solution s;
	cout<<s.Find(9,c);
	system("pause");
	return 0;
}
```



#### 2.替换空格，请实现一个函数，将一个字符串中的每个空格替换成“\%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We\%20Are\%20Happy。

```c++
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int num = 0;//空格总数
        for(int i = 0;i < length;i++)
        {
            if(str[i]==' ')
                num++;
        }
        int nindex = length + 2*num;//替换之后的字符总长度
        for(int i = length;i >= 0;i--){
            if(i == nindex)
                break;
            if(str[i]!=' ')
            {
                str[nindex] = str[i];
                nindex--;
            }   
            else
            {
                str[nindex] = '0';
                nindex--;
                str[nindex] = '2';
                nindex--;
                str[nindex] = '%';
                nindex--;
            }
        }
    }
};
```

```c++
//字符串替换
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	char * replaceSpace(string str)
	{
		int len = str.length();
		//先计算有多少个空格
		int count = 0;
		for(int i=0;i<len;i++)
		{
			if(str[i]==' ')
			{
				count++;
			}
		}
		char *new_str = new char[len+2*count];//新的字符串
		int N = 0;//记录当前有几个空格
		for(int i=0;i<len;i++)
		{
			if(str[i]!=' ')
			{
				new_str[i+2*N] = str[i];
			}
			else
			{
				new_str[i+2*N] = '%';
				new_str[i+2*N+1] = '2';
				new_str[i+2*N+2] = '0';
				N++;
			} 
		}
		return new_str;
	}
};

int main()
{
	Solution s;
	string str= "ab cd ds";
	char* new_str = s.replaceSpace(str);
	string t(new_str);
	cout<<t;
	system("pause");
}
```

此代码在网站中无法通过，但仍然是正确的，因为更改了类中的一些参数形式。



#### 3.从尾到头打印链表。输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
```c++
//从尾到头打印链表
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
#include <iostream>
#include <vector>

using namespace std;

//链表结构体
struct ListNode{
	int val;
	ListNode*next;
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> A;
		while(head!=NULL)
		{
			A.push_back(head->val);
			head = head->next;
		}
		int len = A.size();
		vector<int>B(len);
		for(int i=0;i<len;i++)
		{
			B[i] = A[len-i-1];
		}
		return B;
		}
};

ListNode *Create()
{
	ListNode *head = new ListNode;//构造头结点
	head->val = -1;
	head->next = NULL;//指向NULL
	ListNode *Cur = head;	//构造当前结点，用于记录当前链表构造的位置，初始位置为head

    int data;	//插入链表的数据
    while(1)
    {
	    cout << "请输入当前节点的数值：" << endl;
	    cin >> data;
	    if(data == -1)	//插入-1时结束链表构造
	    {
	    	break;
	    }

	    ListNode *New = new ListNode;	//构造新结点，用于循环插入链表
	    New->val = data;	//新结点数据
	    New->next = NULL;	  //新节点指向NULL
	    Cur->next = New;	//当前结点指向新构造的结点
	    Cur = New;	//当前结点顺移至新结点处，记录链表插入位置
    }
    return head;	//返回头结点
}
int main()
{
	ListNode*list = Create();
	while(list!=NULL)
	{
		cout<<list->val<<" ";
		list = list->next;
	}
	system("pause");
	return 0;
}
```




#### 4.重建二叉树。输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入先序遍历序列${1,2,4,7,3,5,6,8}$和中序遍历序列${4,7,2,1,5,3,8,6}$，则重建二叉树并返回。

```c++
//重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode*left;
	TreeNode*right;
};

//后序输出二叉树
void PostOrderBiTree(TreeNode*T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		PostOrderBiTree(T->left);
		PostOrderBiTree(T->right);
		cout<<T->val<<" ";
	}
}

class Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int len = vin.size();
		if (len==0)
		{
			return NULL;
		}
		TreeNode *head = new TreeNode;
		head->val = pre[0];
		vector<int>left_pre,left_vin,right_pre,right_vin;//分别存储左右子树的先序和中序

		//在中序里面寻找根节点的位置
		int gen = 0;
		for(int i=0;i<len;i++)
		{
			if(vin[i]==pre[0])
			{
				gen = i;
				break;
			}
		}
	
		//左子树的先序和中序
		for(int i=0;i<gen;i++)
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i+1]);
		}
	
		//右子树的先序和中序
		for(int i=gen+1;i<len;i++)
		{
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
	
		head->left = reConstructBinaryTree(left_pre,left_vin);
		head->right = reConstructBinaryTree(right_pre,right_vin);
		return head;
	}
};

int main()
{
	Solution s;
	vector<int>pre,vin;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(3);
	TreeNode*T = s.reConstructBinaryTree(pre,vin);
	PostOrderBiTree(T);//后序输出，验证构建的正确性

	system("pause");
	return 0;

}
```


递归操作。首先在先序中找出根节点，然后在中序中找出根节点的位置序号，该位置序号前面的是该根节点的左子树，后面的是根节点的左子树；然后将左右子树的先序中序遍历结果存起来，依次进行左右子树的递归。



#### 5.用两个栈实现队列。用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
```c++
//用两个栈实现队列
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
	stack1.push(node);
}

int pop() {
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			int p1 = stack1.top();
			stack1.pop();
			stack2.push(p1);
		}
	}
	int p2 = stack2.top();
	stack2.pop();
	return p2;
}

private:
	stack<int> stack1;
	stack<int> stack2;
};


int main()
{
	Solution S;
	S.push(3);
	S.push(4);
	cout<<S.pop()<<" "<<S.pop();
	system("pause");
	return 0;
}
```

这里用$C++$来写，牛客网上都是用$java$写的。思路是相同的，进队列时直接进$stack1$，出队列时需要把$stack1$中的所有元素压到$stack2$中，然后直接$pop $$stack2$中的元素，当$stack2$中的元素为空时，才能接着将$stack1$中的元素压到$stack2$中，否则要一直把$stack2 $$pop$空为止。不同的地方在于$C++$中栈的$pop$没有返回值，只是把第一个元素删除，所以要想达到取出栈顶的元素的效果，应该先用$top()$取出，再用$pop$删除栈顶元素。



#### 6.把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组[3,4,5,1,2]为[1,2,3,4,5]的一个旋转，该数组的最小值为1。NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
采用二分法解答这个问题，mid = low + (high - low)/2，需要考虑三种情况：
(1)array[mid] > array[high]:
出现这种情况的array类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边，low = mid + 1；
(2)array[mid] < array[high]:
出现这种情况的array类似[2,2,3,4,5,6,6],此时最小数字一定就是array[mid]或者在mid的左边，因为右边必然都是递增的，high = mid；
(3)array[mid] == array[high]:
出现这种情况的array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边，还是右边,这时只好一个一个试 ，high = high - 1。

```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length==0)
            return 0;
        int left = 0;
        int right = length - 1;

        while(left<right)
        {
            int mid = (left+right)/2;
            if(rotateArray[mid]<rotateArray[right])
                right = mid;//不能是mid-1
            else if(rotateArray[mid]>rotateArray[right])
                left = mid + 1;
            else
                right--;//此时rotateArray[mid]==rotateArray[right],无法判断最小值在哪边，只能缩小范围
        }
        return rotateArray[left];
    }
};
```



#### 7.斐波那契数列。要求输入一个整数$n$，请你输出斐波那契数列的第$n$项(从$0$开始，第$0$项为$0$)。$n<=39$。

```c++
//递归
class Solution1{
public:
	int Fibonacci(int n)
	{
		if(n<2)
		{
			return n;
		}
		else
		{
			return Fibonacci(n-1)+Fibonacci(n-2);
		}
	}
};

//数组
class Solution2{
public:
	int Fibonacci(int n)
	{
		int *F = new int[40];
		F[0] = 0;
		F[1] = 1;
		for(int i = 2;i<=n;i++)
		{
			F[i] = F[i-1]+F[i-2];
		}
		return F[n];
	}
};

//三个变量代替数组
class Solution3{
public:
	int Fibonacci(int n)
	{
		int pre1 = 0;
		int pre2 = 1;
		int cur = 0;//存储当前计算结果
		for(int i=2;i<=n;i++)
		{
			cur = pre1+pre2;
			pre1 = pre2;
			pre2 = cur;
		}
		if(n<2)
		{
			return n;
		}
		return cur;   
	}
};
```




#### 8.跳台阶。一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法(先后次序不同算不同的结果)。
跟上面一题思路一样：

```c++
class Solution{
public:
	int jumpFloor(int n)
	{
		int pre1 = 1;
		int pre2 = 2;
		int cur = 0;//当前计算结果
		for(int i=3;i<=n;i++)
		{
			cur = pre1+pre2;
			pre1 = pre2;
			pre2 = cur;
		}
		if(n<3)
		{
			return n;
		}
		return cur;
	}    
};
```



#### 9.变态跳台阶。一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
```c++
class Solution{
public:
	int jumpFloorII(int number)
	{
		if(number<2)
		{
			return number;
		}
		else
		{
			int pre = 0;
			int cur = 1;
			for(int i=2;i<=number;i++)
			{
				pre = cur;
				cur = 2*pre;                
			}
			return cur;
		}        
	}
};
```




#### 10.矩形覆盖。我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
(本质还是斐波那契数列和第八题一样的代码)



#### 11.二进制中的1的个数。输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

```c++
class Solution {
public:
	int  NumberOf1(int n) {
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


这道题要明白一个结论：一个二进制数$n$减$1$后与原二进制数进行$\&$运算(即$n\&(n-1)$)会消去最右边的$1$，实际上挺好想的，能做多少次与运算。就有多少个$1$。$C++$中负数默认转的就是补码形式，所以不需要$if$判断。



#### 12.数值的整数次方。给定一个$double$类型的浮点数$base$和$int$类型的整数$exponent$。求$base$的$exponent$次方。保证$base$和$exponent$不同时为$0$。
```c++
class Solution{
public:
	double Power(double base,int exponent)
	{
		if(base==0.0)
		{
			return 0.0;
		}
		else if(exponent==0)
		{
			return 1.0;
		}
		else
		{
			double result;
			int e = exponent>0?exponent:-exponent;
			for(int i=1;i<=e;i++)
			{
				result = result*base;
			}
			return exponent>0?result:1/result;
		}        
	}
};
```



#### 13.调整数组顺序使奇数位于偶数前面。输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len-1;j++)
			{
				if(array[j]%2==0&&array[j+1]%2==1)
				{
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	s.reOrderArray(array);
	for(int i=0;i<array.size();i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
```


使用双循环冒泡方法，遇到偶数与奇数相邻的情况就换两个数的位置。



#### 14.链表中倒数第k个结点。输入一个链表，输出该链表中倒数第k个结点。
```c++
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
};

//先将链表反转
ListNode* reverse(ListNode* head)
{
	ListNode*pre = NULL;
	ListNode*cur = NULL;
	while(head!=NULL)
	{
		cur = head->next;
		head->next = pre;
		pre = head;
		head = cur;
	}
	return pre;
}

class Solution {
public:
	int FindKthToTail(ListNode* pListHead, unsigned int k) {
		pListHead = reverse(pListHead);//先将链表反转
		int i = 1;
		while(i<k)
		{
			i++;
			pListHead = pListHead->next;
		}
		return pListHead->val;
	}
};

ListNode *Create()
{
	ListNode *head = new ListNode;//构造头结点
	head->val = -1;
	head->next = NULL;//指向NULL

	ListNode *Cur = head;	//构造当前结点，用于记录当前链表构造的位置，初始位置为head
	
	int data;	//插入链表的数据
	while(1)
	{
		cout << "请输入当前节点的数值：" << endl;
		cin >> data;
		if(data == -1)	//插入-1时结束链表构造
		{
			break;
		}
	
		ListNode *New = new ListNode;	//构造新结点，用于循环插入链表
		New->val = data;	//新结点数据
		New->next = NULL;	  //新节点指向NULL
		Cur->next = New;	//当前结点指向新构造的结点
		Cur = New;	//当前结点顺移至新结点处，记录链表插入位置
	}
	return head;	//返回头结点

}

int main()
{
	Solution s;
	ListNode*head = Create();
	int data = s.FindKthToTail(head,4);
	cout<<data;
	system("pause");
	return 0;
}
```

上述方法先将列表反转，输出第$k$个节点的值。也可以设置两个快慢指针，起始位置相差$k$个节点，然后快慢一起走，当快指针到达链表末尾时，慢指针到达倒数第$k$个节点。
或者采用双指针，让第一个指针先走k步，然后第二个指针再走，当第一个指针走到末尾的时候，第二个指针就在倒数第k个节点处，此外要注意k和链表长度的比较，代码如下：

```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, int k) {
        ListNode* pre = NULL;
        ListNode* p = NULL;
        pre = pListHead;
        p = pListHead;
        int length = k;//记录k
        int count = 0;//记录节点个数，后续需要和k比较
        while(p!=NULL)
        {
            p = p->next;
            count++;
            if(k<=0)
                pre = pre->next;
            k--;
        }
        if(count<length)
            return NULL;
        return pre;
    }
};
```




#### 15.反转链表。输入一个链表，反转链表后，输出新链表的表头。

```c++
//反转链表
//输入一个链表，反转链表后，输出新链表的表头。

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode*next;
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *p = NULL;
        ListNode *pre = NULL;

        while(pHead!=NULL)
        {
            p = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = p;
        }
        return pre;
    }
};

ListNode *Create()
{
    ListNode *head = new ListNode;//构造头结点
    head->val = -1;
    head->next = NULL;//指向NULL

    ListNode *Cur = head;	//构造当前结点，用于记录当前链表构造的位置，初始位置为head
    
    int data;	//插入链表的数据
    while(1)
    {
        cout << "请输入当前节点的数值：" << endl;
        cin >> data;
        if(data == -1)	//插入-1时结束链表构造
        {
             break;
        }
    
        ListNode *New = new ListNode;	//构造新结点，用于循环插入链表
        New->val = data;	//新结点数据
        New->next = NULL;	  //新节点指向NULL
        Cur->next = New;	//当前结点指向新构造的结点
        Cur = New;	//当前结点顺移至新结点处，记录链表插入位置
    }
    return head;	//返回头结点

}

int main()
{
    Solution s;
    ListNode*head = Create();
    ListNode*phead = s.ReverseList(head);
    while(phead!=NULL)
    {
        cout<<phead->val<<" ";
        phead = phead->next;
    }
    system("pause");
    return 0;
}
```

关键在于类中的链表操作，定义两个链表指针$p,pre$，$pre$表示$p$的前一个节点，假设待反转的链表当前节点为$head$，首先用$p$记录$head$的下一个节点，然后将$head$与$p$断开，令$head$指向$pre$，再将$head$赋值给$pre$，最后将$p$赋值给$head$，进行下一次操作，当$head$到最后一个节点时，操作之后$pre$就是最后一个节点，而且前面的所有节点都已经反转地指向前驱节点。



#### 16.合并两个排序的链表。输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;//记录当前节点的位置

        while(pHead1!=NULL&&pHead2!=NULL)
        {
            if(pHead1->val<=pHead2->val)
            {
                ListNode* New = new ListNode(-1);
                New->val = pHead1->val;
                cur->next = New;
                cur = New;
                pHead1 = pHead1->next;
            }
            else
            {
                ListNode* New = new ListNode(-1);
                New->val = pHead2->val;
                cur->next = New;
                cur = New;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1!=NULL)
            cur->next = pHead1;
        if(pHead2!=NULL)
            cur->next = pHead2;
        return head->next;
    }
};
```



#### 17.树的子结构。输入两棵二叉树A，B，判断B是不是A的子结构。(ps：我们约定空树不是任意一个树的子结构)
```c++
//输入两棵二叉树A，B，判断B是不是A的子结构或者子树
//子树的意思是包含了一个结点，就得包含这个结点下的所有节点，一棵大小为n的二叉树有n个子树，就是分别以每个结点为根的子树;
//子结构的意思是包含了一个结点，可以只取左子树或者右子树，或者都不取。
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        bool result = false;
        //当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
        if (pRoot2 != NULL && pRoot1 != NULL)
        {
            //如果找到了对应Tree2的根节点的点
            //if(pRoot1->val == pRoot2->val)
                //以这个根节点为为起点判断是否包含Tree2
            result = doesTree1HaveTree2(pRoot1,pRoot2);

            //如果找不到，那么就再去root的左儿子当作起点，去判断是否包含Tree2
            if(!result)
                result = HasSubtree(pRoot1->left,pRoot2);
    
            //如果还找不到，那么就再去root的右儿子当作起点，去判断是否包含Tree2
            if(!result)
                result = HasSubtree(pRoot1->right,pRoot2);
        }
    return result;

}

private:
    bool doesTree1HaveTree2(TreeNode* node1,TreeNode* node2)
    {
        //如果Tree2已经遍历完了都能对应的上，返回true
        if(node2==NULL)
            return true;
        

        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if(node1==NULL)
            return false;
    
        //如果其中有一个点没有对应上，返回false
        if(node1->val!=node2->val)
            return false;
    
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return doesTree1HaveTree2(node1->left,node2->left)&&doesTree1HaveTree2(node1->right,node2->right);
    }

};
```


只写了如何判断子结构，还有判断子树待考究。



#### 18.二叉树的镜像。操作给定的二叉树，将其变换为源二叉树的镜像。

```c++
struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if(pRoot==NULL)
		{
			return;
		}
		TreeNode*temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};
```



#### 19.顺时针打印矩阵。输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4x4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16，则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10。

```c++
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ssz;
		if(matrix.size()==0||matrix[0].size()==0)
		{
			return ssz;
		}
		int up = 0;
		int down = matrix.size()-1;
		int left = 0;
		int right = matrix[0].size()-1;

		while(true)
		{
			for(int col=left;col<=right;col++)
			{
				ssz.push_back(matrix[up][col]);
			}
			up++;
			if(up>down)
			{
				break;
			}
	
			for(int row=up;row<=down;row++)
			{
				ssz.push_back(matrix[row][right]);
			}
			right--;
			if(left>right)
			{
				break;
			}
	
			for(int col=right;col>=left;col--)
			{
				ssz.push_back(matrix[down][col]);
			}
			down--;
			if(up>down)
			{
				break;
			}
	
			for(int row=down;row>=up;row--)
			{
				ssz.push_back(matrix[row][left]);
			}
			left++;
			if(left>right)
			{
				break;
			}
		}
		return ssz;
	}
};
```




#### 20.定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
思路：用一个栈s保存数据，用另外一个栈smin保存依次入栈最小的数，即smin的栈顶元素是当前栈的最小元素。\\
比如s中依次入栈5,  4,  3, 8, 10, 11, 12, 1\\
则smin依次入栈5,  4,  3，no,no, no, no, 1\\
其中no代表此次不入栈，每次入栈的时候，如果入栈的元素比smin中的栈顶元素小或等于则入栈，否则不入栈，每次出栈的时候，判断s中出栈元素和smin栈顶元素是否相同，相同则smin出栈。

```c++
class Solution {
public:
    void push(int value) {
        s.push(value);
        if(s_min.empty())
            s_min.push(value);
        else if(value<=s_min.top())
            s_min.push(value);
    }
    void pop() {
        if(s.top()==s_min.top())
            s_min.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return s_min.top();
    }

private:
    stack<int> s;
    stack<int> s_min;
};
```



#### 21.输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int length = pushV.size();
        stack<int> s;
        int j=0;
        for(int i=0;i<length;i++)
        {
            s.push(pushV[i]);
            while((!s.empty())&&(s.top()==popV[j]))
            /*
            要是没有!s.empty()或者两个条件顺序调换，则当popV[j]已经指到最后一个元素的时候，再进行j++，popv[j]就没有指定的元素了，这样就会溢出，所以需要!s.empty()提前结束while，不让运行后面的popV[i]。
            */
            {
                s.pop();
                j++;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};
```



#### 22.从上往下打印二叉树。从上往下打印出二叉树的每个节点，同层节点从左至右打印。
基本思路，采用BFS算法，将已经遍历过的节点加入到队列当中，最后输出队列即可，和剑指offer60题一样的思路，不同的是返回的是一维数组。

```c++
struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> matrix;
        if(root==NULL)
            return matrix;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            matrix.push_back(p->val);
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
        }
        return matrix;
    }
};
```




#### 23.二叉搜索树的后序遍历序列，输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
基本思路：后续遍历的最后的输出值一定是根节点，根据根节点来划分左右子树的后序遍历结果。第一个大于根节点的值作为划分的界，然后判断后面的数是不是都大于根节点。如果满足，则继续递归调用左右子树的后序遍历结果。

```c++
class Solution{
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		int len = sequence.size();
		if(len==NULL)
		{
			return false;
		}
		return isBST(sequence,0,len-1);
	}
private:	
bool isBST(vector<int> sequence,int start,int end)
{
    if(start>=end)//这里一定是大于或者等于，等于对应的是叶子节点，大于对应的是空树
        return true;
    int val = sequence[end];//根节点
    int split;//划分的索引，第一个for循环为了找到划分的位置
    for(int i=start;i<end;i++)
        if(sequence[i]>val)
        {
            split = i;
            break;
        }
    //判断后面是否还有小于根节点的数，如果有，返回false
    for(int i=split;i<end;i++)
        if(sequence[i]<val)
            return false;
            

    return isBST(sequence,start,split-1)&&isBST(sequence,split,end-1);

};
```




#### 24.输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

```c++
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> path;
    void find(TreeNode* root, int sum)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if((root->left==NULL)&&(root->right==NULL)&&(sum==root->val))
            res.push_back(path);
        else
        {
            if(root->left!=NULL)
                find(root->left, sum-root->val);
            if(root->right!=NULL)
                find(root->right, sum-root->val);
        }
        path.pop_back();//某个节点左右孩子都遍历完了，需要pop出路径中的当前节点
    }
};

//变形，输出树中的所有路径
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root) {
        find(root);
        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> path;
    void find(TreeNode* root)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if((root->left==NULL)&&(root->right==NULL))
            res.push_back(path);
        else
        {
            if(root->left!=NULL)
                find(root->left);
            if(root->right!=NULL)
                find(root->right);
        }
        path.pop_back();//某个节点左右孩子都遍历完了，需要pop出路径中的当前节点
    }
};
```



#### 26.输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
解题思路：二叉搜索树的中序遍历结果是排好序的，所以按照中序遍历的方法，pRootOfTree代表当前节点，Head代表中序遍历前一个节点，realHead表示中序遍历第一个节点，即最左下角的节点。

```c++
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return NULL;
        ConvertSub(pRootOfTree);
        return realHead;
    }

private:
    TreeNode* Head = NULL;
    TreeNode* realHead = NULL;
    void ConvertSub(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return;
        ConvertSub(pRootOfTree->left);
        if(Head==NULL)
        {
            Head = pRootOfTree;
            realHead = pRootOfTree;
        }
        else
        {
            Head->right = pRootOfTree;
            pRootOfTree->left = Head;
            Head = pRootOfTree;
        }
        ConvertSub(pRootOfTree->right);
    }
};
```



#### 28.数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

解法一：利用vector的sort()
首先将vector中的数字排序，因为要求输出重复次数大于数组大小一般的数，排序结束后，相同的数字都在相邻位置，直接判断数组当前位置的数字与数组位置+数组一半长度位置的数字是否相等，相等则输出该数字，代码如下：

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int middle = numbers.size()/2;
        sort(numbers.begin(), numbers.end());
        for(int i=0;i+middle<numbers.size();i++)
        {
            if(numbers[i]==numbers[i+middle])
                return numbers[i];
        }
        return 0;
    }
};
```

解法二：空间换时间
使用c++中的hash数据结构map，保存vector中每个数字在数组中出现的次数，再找到次数超过一半的，代码如下（这里只是写了一个如何使用map的实例，将类中返回的$number\_map$换成num就是这题的另一种解法）：

```c++
#include<iostream>
#include<vector>
#include<map>//hash表的头文件
#include<iterator>//迭代器的头文件

using namespace std;

class Solution {
public:
    map<int, int> MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> number_map;
        //构造hash表
        for(int i=0;i<numbers.size();i++)
        {
            number_map[numbers[i]] += 1;
        }
        int middle_size = numbers.size()/2;
        int num = 0;
        for(map<int, int>::iterator it=number_map.begin();it!=number_map.end();it++)
        {
            if(middle_size<(it->second))
            num = it->first;
        }
        return number_map;
    }
};


int main()
{
    int len = 10;
    vector<int> v(len);
    for(int i=0;i<len;i++)
    {
        v[i] = i;
    }
    Solution s;
    map<int, int> number_map;
    number_map = s.MoreThanHalfNum_Solution(v);
    for(map<int, int>::iterator it=number_map.begin();it!=number_map.end();it++)
    {
        cout<<it->first<<":"<<it->second<<endl;
    }
    return 0;
}
```



#### 29.最小的K个数，输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

```c++
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> v;
		if(k>input.size())
		{
			return v;
		}
		sort(input.begin(),input.end());
		for(int i=0;i<k;i++)
		{
			v.push_back(input[i]);
		}
		return v;
	}
};
```


具体的方法有两种：1.先排好序再取前$k$个元素，快速排序或者归并排序需要$O(nlogn)$的复杂度，再乘以常数$k$还是$O(nlogn)$的复杂度；1.循环$k$次，每次取第$i,i=1,...,k$小的元素(具体方法见该部分question6)，该方法时间复杂度为$O(n)$。这里采用了第一种方法。



#### 30.连续子数组的最大和，{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和(子向量的长度至少是1)。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int length = array.size();
        vector<int> dp(length);

        dp[0] = array[0];
        for(int i=0;i<length;i++)
        {
            if(dp[i-1]+array[i]>array[i])
                dp[i] = dp[i-1]+array[i];
            else
                dp[i] = array[i];
        }

        int Max = dp[0];
        for(int i=1;i<length;i++)
        {
            if(dp[i]>Max)
                Max = dp[i];
        }
        return Max;
    }
};
```


这里的$dp[i]$并不表示从$0$到$i$的最优连续子序列的和，而是$dp[i]=max\{dp[i-1]+array[i],array[i]\}$，表示以元素array[i]结尾的最大连续子数组和，最终整个数组里的最大连续子数组应该是dp中最大的那个数。



#### 32.输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

```c++
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool bigger_than(int a, int b)
    /*
    ab拼接是否比ba拼接大，字符串比较方式
    */
    {
        string A=to_string(a);//int转string
        string B=to_string(b);
        //return stoi(A+B)>stoi(B+A);//string转int
        return A+B>B+A;
    }

    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string result = "";
        //根据拼接大小顺序给数组排序
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(bigger_than(numbers[i], numbers[j]))
                {
                    int tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;
                }
            }
        }
        //将数组拼成一个字符串返回
        for(int i=0;i<len;i++)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};

int main()
{
    int a = 22;
    int b = 21;
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(32);
    v.push_back(321);
    cout<<s.bigger_than(a, b)<<endl;
    cout<<s.PrintMinNumber(v);
    return 0;
}


//可以改写sort函数简化代码
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string result = "";
        //根据拼接大小顺序给数组排序
        sort(numbers.begin(), numbers.end(),[&](int x, int y)
        {
            return to_string(x)+to_string(y)<to_string(y)+to_string(x);
        });

        //将数组拼成一个字符串返回
        for(int i=0;i<len;i++)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};
```



#### 34.在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1(需要区分大小写，从0开始计数)

```c++
#include<iostream>
#include<string>
#include<map>
#include<iterator>

using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.length();
        map<char, int> str_count;//存储各个字符出现的次数
        for(int i=0;i<len;i++)
            str_count[str[i]]++;

        for(int i=0;i<len;i++)
            if(str_count[str[i]]==1)
                return i;
        return -1;
    }

};


int main()
{
    //map<char, int> str_count;
    string str = "ababdeec";
    Solution s;
    int n = s.FirstNotRepeatingChar(str);
    /*
    for(map<char, int>::iterator it=str_count.begin();it!=str_count.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    */
    cout<<n;
    return 0;
}
```




#### 36.输入两个链表，找出它们的第一个公共结点。
假定List1长度：a+n，List2长度：b+n，且a<b.p1和p2同时走，那么p1会先到链表尾部，这时p2走到a+n位置，将p1换成List2头部，接着p2 再走b+n-(n+a) =b-a步到链表尾部,这时p1也走到List2的b-a位置，还差a步就到可能的第一个公共节点。将p2 换成 List1头部，p2走a步也到可能的第一个公共节点。如果恰好p1==p2,那么p1就是第一个公共节点；或者p1和p2一起走n步到达列表尾部，二者没有公共节点，退出循环。 同理a>=b.时间复杂度O(n+a+b)，代码如下：

```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1!=p2)
        {
            if(p1!=NULL)
                p1 = p1->next;
            if(p2!=NULL)
                p2 = p2->next;

            if(p1!=p2)
            {
                if(p1==NULL)
                    p1 = pHead2;
                if(p2==NULL)
                    p2 = pHead1;
            }
        }
        return p1;
    }

};
```




#### 37.数字在排序数组中出现的次数，统计一个数字在排序数组中出现的次数。
第一反应想到的是全部遍历一遍，但由于是排序数组，所以相邻两个不一样的时候就可以跳出循环，时间复杂度为$O(1)$.

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count=0;
        int len = data.size();
        for(int i=0;i<len;i++)
        {
             if(data[i]==k)
             {
                 count++;
             }
             if(data[i]==k&&data[i+1]!=k)
             {
                 break;
             }
        }
        return count;
    }
};
```



#### 38.二叉树的深度。输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

```c++
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归写法
// class Solution {
// public:
//     int TreeDepth(TreeNode* pRoot)
//     {
//         if(pRoot==NULL)
//         {
//             return 0;
//         }
//         else
//         {
//             int l = TreeDepth(pRoot->left);
//             int r = TreeDepth(pRoot->right);
//             return (l>r?l:r) + 1;
//         }
//     }
// };

//非递归写法
class Solution{
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        
        int length = 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty())
        {
            int tmp = q.size();
            length++;
            vector<TreeNode*> v = pop(q);
            for(int i = 0;i<tmp;i++)
            {
                if(v[i]->left)
                    q.push(v[i]->left);
                if(v[i]->right)
                    q.push(v[i]->right);
            }
        }
        return length;
    }
private:
    vector<TreeNode*> pop(queue<TreeNode*> &q)
    {
        vector<TreeNode*> v;
        while(!q.empty())
        {
            TreeNode* root = q.front();
            q.pop();
            v.push_back(root);
        }
        return v;
    }
};
```





#### 39.平衡二叉树。输入一棵二叉树，判断该二叉树是否是平衡二叉树。平衡二叉树的左右子树也是平衡二叉树，那么所谓平衡就是左右子树的高度差不超过1。

```c++
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if(TreeDepth(pRoot)==-1)
            return false;
        return true;
    }
private:
    //在计算树深度的同时，判断是否为平衡二叉树；
    //平衡二叉树要求树的每个节点，左右子树节点深度差不超过1;
    //如果不是平衡二叉树，返回-1，否则返回树的深度;
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int left = TreeDepth(pRoot->left);
        if(left==-1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if(right==-1)
            return -1;
        return abs(left-right)>1?-1:max(left, right) + 1;
    }
};
```




#### 40.一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

```c++
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
```

剑指offer上都是采用异或运算，这里给出一个使用hash数据结构来求解的方法，首先遍历数组，直接记录每个数字和qi出现的次数；然后遍历map，找出出现次数为1的数字。



#### 41.输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。
使用双指针，当双指针对应的和小于sum，则大指针右移；双指针和大于sum，小指针右移；双指针和等于sum，将双指针中的数进数组，同时小指针右移。

```c++
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > all_result;
        int start = 1;
        int end = 2;
        while(start<end)
        {
            int cur_sum = (start + end)*(end - start + 1) / 2;
            if(cur_sum<sum)
                end++;
            else if(cur_sum>sum)
                start++;
            else//cur_sum==sum
            {
                vector<int> result;
                for(int i=start;i<=end;i++)
                    result.push_back(i);
                all_result.push_back(result);
                start++;
            }
        }
        return all_result;
    }
};
```



#### 42.输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。
由均值不等式可知：当两个正整数越接近时，对应的乘积越大，所以乘积最小的两个数应该是递增数组中最边缘的两个数，所以有以下两种思路：\\
解法一：双循环搜索，时间复杂度为$O(n^2)$；\\
解法二：使用双指针，时间复杂度为$O(n)$；\\

```c++
/*
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> v;
        for(int i=0;i<length;i++)
            for(int j=i+1;j<length;j++)
                if(array[i]+array[j]==sum)
                {
                    v.push_back(array[i]);
                    v.push_back(array[j]);
                    return v;
                }
        return v;
    }
};
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> v;
        int start = 0;
        int end = length - 1;

        while(start<end)
        {
            if(array[start]+array[end]==sum)
            {
                v.push_back(array[start]);
                v.push_back(array[end]);
                return v;
            }
            else if(array[start]+array[end]<sum)
                start++;
            else
                end--;
        }
        return v;
    }
};
```




#### 43.汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。

```c++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        char* str1 = new char[len];//string无法指定长度，先定义char*，再转为string
        if(len==0)
            return "";
        else
        {
            for(int i=0;i<len;i++)
            {
                if(i<n)
                    str1[len-(n-i)] = str[i];
                else
                {
                    str1[i-n] = str[i];
                }
            }
        }

        string str_return = str1; //char*转string
        return str_return;
    }

};


int main()
{
    Solution S;
    string s = "12345";
    cout<<S.LeftRotateString(s, 2);
    return 0;
}
```




#### 44.牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
采用的思路是先遍历字符串，遇到空格记录单词的起始位置，依次将单词进栈；然后根据栈是否为空进行while循环，将每个单词依次放置到字符串中，代码如下：

```c++
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        stack<string> stk;
        int start = 0;//记录当前单词开始位置
        int end = 0;//记录当前单词结束位置

        for(int i=0;i<len;i++)
        {
            if(str[i]==' ')
            {
                end = i-1;
                string word = str.substr(start, end-start+1);
                stk.push(word);
                start = i+1;
            }
        }
        stk.push(str.substr(start, len-start));//最后一个空格到结尾的单词入栈
    
        //栈中单词放置到char*中
        char* str_return = new char[len];
        int position = 0;
        while(!stk.empty())
        {
            string str_tmp = stk.top();
            stk.pop();
            int tmp_len = str_tmp.length();
            //cout<<tmp_len<<endl;
            for(int i=0;i<tmp_len;i++)
            {
                str_return[i+position] = str_tmp[i];
            }
            if(tmp_len+position<len)
                str_return[tmp_len+position] = ' ';//防止最后一个单词的后面还有空格
            position += (tmp_len+1);       
        }
        string str_return1 = str_return;//char*转string
        return str_return1;
    }

};

int main()
{
    Solution s;
    string str = "student. a am I";
    string str_return1 = s.ReverseSentence(str);
    cout<<str_return1.size()<<endl;
    cout<<str_return1<<endl;
    return 0;
}
```




#### 45.LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
解题思路：首先对数组排序，计算所有相邻数字的间隔总数以及0的个数，判断是否有对子（有对子则不是顺子），如果0的个数大于等于所有相邻数字的间隔总数，则认为是顺子。

```c++
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int numOfZero = 0;
        int numOfInterval = 0;
        int length = numbers.size();
        if(length==0)
            return false;
        sort(numbers.begin(), numbers.end());
        for(int i=0;i<length-1;i++)
        {
            //计算0的数量
            if(numbers[i]==0)
            {
                numOfZero++;
                continue;//这句话不能省，防止后续判断对子会误判0,0为对子
            }
            //判断相邻的是否为对子
            if(numbers[i]==numbers[i+1])
                return false;
            numOfInterval += numbers[i+1]-numbers[i]-1;
        }
        if(numOfZero>=numOfInterval)
            return true;
        return false;
    }
};
```




#### 48.写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
首先看十进制是如何做的： 5+7=12，三步走：
第一步：相加各位的值，不算进位，得到2；
第二步：计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果；
第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12；

同样我们可以用三步走的方式计算二进制值相加： 5-101，7-111

第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111；
第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1；
第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1；
继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。

```c++
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2!=0) //当进位为0时，不带进位的结果就是相加的结果
        {
            int tmp = num1^num2; //计算不带进位的结果，相当于异或运算
            num2 = (num1&num2)<<1; //计算进位结果，相当于与运算再左移一位
            num1 = tmp;
        }
        return num1;//返回不带进位的结果
    }
};
```




#### 50.在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
```c++
class Solution {
public:
// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int* hash = new int[length];
        for(int i=0;i<length;i++)
            hash[i] = 0;
        for(int i=0;i<length;i++)
            hash[numbers[i]]++;
        for(int i=0;i<length;i++)
        {
            if(hash[i]>1)
            {
                duplication[0] = i;
                return true;
            }
        }
        return false;
    }
};
```




#### 51.给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。

```c++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> B;
        for(int i=0;i<length;i++)
        {
            B.push_back(1);//每一位的初始值都为1
            for(int j=0;j<length;j++)
            {
                if(j==i)
                    continue;
                else
                {
                    B[i] *= A[j];
                }
            }
        }
        return B;
    }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    Solution s;
    vector<int> B = s.multiply(A);
    cout<<B.size()<<endl;
    cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<" "<<B[3]<<endl;
    return 0;
}
```




#### 54.请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回井字符。

```c++
class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        str_count[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(str_count[s[i]]==1)
                return s[i];
        }
        return '#';
    }
private:
    string s;
    map<char,int> str_count;
};
```



#### 55.给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast = pHead;
        ListNode* low = pHead;

        while(fast!=NULL&&fast->next!=NULL)
        {
            fast = fast->next->next;
            low = low->next;
            if(fast==low)
                break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;//fast为NULL，则不存在环
        low = pHead;
        while(fast!=low)
        {
            fast = fast->next;
            low = low->next;
        }
        return low;
    }

};
//第一个while和if中的判断条件，fast和fast->next缺一不可
```

注：代码中while和if中的判断条件，fast和fast->next两个缺一不可，while中加上fast->next!=NULL使得fast每次可以成功走两步，如果只有fast!=NULL，则当fast是尾节点时，走两步会报错，因为fast->next为NULL，而NULL->next会报错。while循环之后，如果有环，则fast和fast->next为正常的节点，如果没有环，会出现fast为NULL或者fast为尾节点(即fast->next为NULL)，所以是否为环需要判断两种情况，即if(fast==NULL||fast->next==NULL)。\\
上述的解法是剑指offer中别人的解法，特别难想，这里提出使用map哈希数据结构来记录每个节点出现的次数，当某个节点出现两次的时候，返回该节点即可，如果都是出现一次，则返回NULL，代码如下：\\

```c++
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;
        map<ListNode*, int> node_count;
        ListNode* p = pHead;
        while(p!=NULL)
        {
            node_count[p]++;
            if(node_count[p]==2)
                return p;
            p = p->next;
        }
        return NULL;
    }
};
```




56.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5.

```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//删除重复的元素，如1,2,3,3,4,4,5-->1,2,3,4,5
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode* p = pHead;
        while(p!=NULL&&p->next!=NULL)
        {
            if(p->val==p->next->val)
            {
                ListNode* post = p->next->next;
                p->next = post;
                p = post;
            }
            else
                p = p->next;
        }
        return pHead;
    }
};



//删除所有重复的元素，如1,2,3,3,4,4,5-->1,2,5
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode* newHead = new ListNode(-1);
        newHead->next = pHead;//创建新的头结点，防止头结点是重复的被删除
        ListNode* pre = newHead;
        ListNode* p = pHead;
        while(p!=NULL&&p->next!=NULL)
        {
            ListNode* pnext = p->next;//用于搜索重复的节点
            if(p->val==pnext->val)
            {
                //开始搜索重复的节点
                while(pnext!=NULL&&pnext->val==p->val)
                    pnext = pnext->next;
                //删除重复的节点
                pre->next = pnext;
                //删除之后，再重新从下一个不重复的节点开始
                p = pnext;
            }
            else
            {
                //继续搜索
                pre = p;
                p = p->next;
            }
        }
        return newHead->next;
    }
};
```




#### 57.给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

```c++
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //首先判断是否为空
        if(pNode==NULL)
            return NULL;

        //其次考虑是否有右孩子，因为中序遍历下一个节点在右孩子一侧，右孩子的最左孩子
        if(pNode->right!=NULL)
        {
            pNode = pNode->right;
            while(pNode->left!=NULL)
                pNode = pNode->left;
            return pNode;
        }
    
        //如果没有右孩子，中序遍历要考虑父节点，所以需要先判断是否为根节点，如果是根节点直接返回NULL
        if(pNode->next==NULL)
            return NULL;
    
        //不是根节点，即该节点有父节点，需要一直寻找父节点，直到某个父节点也是它的父节点的左孩子时，返回该父节点的父节点
        //如果没找到，说明一直是父节点的右孩子，则直接返回NULL
        while(pNode->next!=NULL)
        {
            if(pNode==pNode->next->left)
                return pNode->next;
            pNode = pNode->next;
        }
        return NULL;
    }
};
```



#### 58.请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
1.递归解法，需要判断pRoot->left和pRoot->right是否对称，即pRoot->left->left==pRoot->right->right且pRoot->left->right==pRoot->right->left;
2.非递归解法，使用DFS和BFS，分别对应栈和队列;

```c++
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        else if(pRoot->left==NULL&&pRoot->right==NULL)
            return true;
        else if(pRoot->left==NULL||pRoot->right==NULL)
            return false;
        else
            return (pRoot->left->val==pRoot->right->val)&&isSymmetrical(pRoot->left)&&isSymmetrical(pRoot->right);
    }
};
*/

//使用递归解法
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return IsSymmetrical(pRoot->left, pRoot->right);
    }
private:
    bool IsSymmetrical(TreeNode* left, TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        else if(left==NULL||right==NULL)
            return false;
        return (left->val==right->val)&&IsSymmetrical(left->left, right->right)&&IsSymmetrical(left->right, right->left);
    }
};


//DFS深度优先遍历，使用数据结构栈stack
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        stack<TreeNode*> s;
        //成对进入栈
        s.push(pRoot->left);
        s.push(pRoot->right);
        while(!s.empty())
        {
            TreeNode* left = s.top();
            s.pop();
            TreeNode* right = s.top();
            s.pop();
            if(left==NULL&&right==NULL)
                continue;
            else if(left==NULL||right==NULL)
                return false;
            else if(left->val!=right->val)
                return false;
            //成对进入栈
            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);                
        }
        return true;
    }
};


//BFS广度优先遍历，使用数据结构队列queue
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        queue<TreeNode*> q;
        //成对进入队列
        q.push(pRoot->left);
        q.push(pRoot->right);
        while(!q.empty())
        {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if(left==NULL&&right==NULL)
                continue;
            else if(left==NULL||right==NULL)
                return false;
            else if(left->val!=right->val)
                return false;
            //成对进入队列
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
```




#### 59.请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

```c++
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if(pRoot==NULL)
		return result;
		stack1.push(pRoot);//stack1放根节点（奇数行节点）
		while(!stack1.empty()||!stack2.empty())
		{
			vector<int> ret1,ret2;
			TreeNode* cur = NULL;
			//偶数行放stack2中
			while(!stack1.empty())
			{
				cur = stack1.top();
				if(cur->left!=NULL)
				stack2.push(cur->left);
				if(cur->right!=NULL)
				stack2.push(cur->right);
				ret1.push_back(cur->val);
				stack1.pop();
			}
			if(ret1.size()!=0)
			result.push_back(ret1);
			

			//奇数行放stack1
			while(!stack2.empty())
			{
				cur = stack2.top();
				if(cur->right!=NULL)
				stack1.push(cur->right);
				if(cur->left!=NULL)
				stack1.push(cur->left);
				ret2.push_back(cur->val);
				stack2.pop();
			}
			if(ret2.size()!=0)
			result.push_back(ret2);
		}
		return result;
	}
	private:
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;

};
```




#### 60.从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
广度优先遍历BFS，使用数据结构队列，代码如下：

```c++
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> > matrix;
        if(pRoot==NULL)
            return matrix;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty())
        {
            int cur = 0;
            int len = q.size();
            vector<int> row;
            while(cur<len)
            {
                cur++;
                TreeNode* p = q.front();
                q.pop();
                row.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            matrix.push_back(row);
        }
        return matrix;
    }
};
```




#### 62.给定一棵二叉搜索树，请找出其中的第k小的结点。例如，（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
解题思路：二叉搜索树中序遍历结果就是该树从小到大的排序结果，直接输出索引为k-1的节点即可。

```c++
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k<=0)
            return NULL;
        MidOrder(pRoot);
        int length = v.size();
        if(k>length)
            return NULL;
        return v[k-1];
}

private:
    vector<TreeNode*> v;
    void MidOrder(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return;
        MidOrder(pRoot->left);
        v.push_back(pRoot);
        MidOrder(pRoot->right);
    }
};
```



#### 63.如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

```c++
class Solution {
public:
    void Insert(int num)
    {
        v.push_back(num);
        sort(v.begin(),v.end());
    }

double GetMedian()
{
    int len = v.size();
    if(len%2==1)
        return double(v[len/2]);
    else
        return double(v[len/2-1]+v[len/2])/2;
}
private:
    vector<int> v;
};
```




#### 64.给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}，{2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。窗口大于数组长度或者窗口长度为0的时候，返回空。
1.遍历搜索

```c++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        unsigned int len = num.size();
        vector<int> v;
        if(size>len||size==0)
            return v;
        for(unsigned int i=0;i<=len-size;i++)
        {
            int max = num[i];
            for(unsigned int j=i;j<i+size;j++)
                if(num[j]>max)
                    max = num[j];
            v.push_back(max);
        }
        return v;
    }
};
```




#### 66.地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

```c++
class Solution {
public:
    int count = 0;
    int movingCount(int threshold, int rows, int cols)
    {
        int* pass = new int[rows*cols];
        moving_count(threshold, 0, 0, rows, cols, pass);
        //delete[]pass;
        return count;
    }

private:
    void moving_count(int threshold, int i, int j, int rows, int cols, int* pass)
    {
        int index = i*cols + j;
        if(i<0||j<0||i>=rows||j>=cols||pass[index]==1)
            return;
        if(helper(i,j)<=threshold)
        {
            count++;
            pass[index] = 1;
        }
        else
        {
            //pass[index] = 0;
            return;
        }

        moving_count(threshold, i-1, j, rows, cols, pass);
        moving_count(threshold, i+1, j, rows, cols, pass);
        moving_count(threshold, i, j-1, rows, cols, pass);
        moving_count(threshold, i, j+1, rows, cols, pass);
    }
    int helper(int i, int j)
    {
        int sum = 0;
        sum = sum + i%10;
        sum = sum + j%10;
        while((i = i/10)>0)
            sum = sum + i%10;
        while((j = j/10)>0)
            sum = sum + j%10;
        return sum;
    }

};
```



#### 67.给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

* 题目分析：

* 先举几个例子，可以看出规律来。

* 4 ： 2*2

* 5 ： 2*3

* 6 ： 3*3

* 7 ： 2*2*3 或者4*3

* 8 ： 2*3*3

* 9 ： 3*3*3

* 10：2*2*3*3 或者4*3*3

* 11：2*3*3*3

* 12：3*3*3*3

* 13：2*2*3*3*3 或者4*3*3*3
  *

* 下面是分析：

* 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。

* 当然也可能有4，但是4=2*2，我们就简单些不考虑了。

* 5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。

* 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。

* 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。

* 由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回就行了。
  *

* 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。

  ```c++
  //贪心
  class Solution {
  public:
      int cutRope(int number) {
          if(number==2||number==3)
              return number==3?2:1;
          int x = number % 3;
          int y = number /3;
          if(x==0)
              return pow(3, y);
          else if(x==1)
              return 2*2*pow(3, y-1);
          else
              return 2*pow(3, y);
      }
  };
  
  //动态规划
  /*
  f[i]表示长度为i的绳子的最大乘积
  for j=1,2,...,i-1
  f[i] = max{f[i],f[j]*f[i-j]}
  */
  ```
