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
