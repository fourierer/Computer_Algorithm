class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length-1;j++)
            {
                if((array[j]%2==0)&&(array[j+1]%2==1))
                {
                    int tmp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = tmp;
                }
            }
        }
    }
};
