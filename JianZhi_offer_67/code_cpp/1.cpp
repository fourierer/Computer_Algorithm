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
	return 0;
}