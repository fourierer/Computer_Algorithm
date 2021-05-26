class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> out;
        if(matrix.size()==0||matrix[0].size()==0)
            return out;
        
        int up = 0;
        int down = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;

        while(1)
        {
            for(int col=left;col<=right;col++)
            {
                out.push_back(matrix[up][col]);
            }
            up++;
            if(up>down)
                break;
            
            for(int row=up;row<=down;row++)
            {
                out.push_back(matrix[row][right]);
            }
            right--;
            if(left>right)
                break;
            
            for(int col=right;col>=left;col--)
            {
                out.push_back(matrix[down][col]);
            }
            down--;
            if(up>down)
                break;

            for(int row=down;row>=up;row--)
            {
                out.push_back(matrix[row][left]);
            }
            left++;
            if(left>right)
                break;
        }
        return out;
    }
};