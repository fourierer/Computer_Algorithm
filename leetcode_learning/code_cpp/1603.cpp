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
