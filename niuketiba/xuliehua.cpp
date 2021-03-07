//序列化
#include<iostream>

using namespace std;

int main()
{
    long N, L;
    cin>>N>>L;
    for(int i=L;i<=100;i++)
    {
        double a = double(2*N - i*(i-1))/double(2*i);//这里用float会出问题
        //cout<<a<<endl;
        if(a-(long)a==0)
        {
            //cout<<a<<endl;
            for(int j=0;j<i-1;j++)
                cout<<long(a+j)<<" ";
            cout<<long(a+i-1);
            return 0;
        }
    }
    cout<<"No";
    return 0;
}