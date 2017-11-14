
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    short cookie_qty, cookie_cal, total_cal;
    
    cookie_cal=100;
    
    cout<<"How many cookies did you eat?";
    cin>>cookie_qty;
    
    total_cal=cookie_qty*cookie_cal;
    
    cout<<"You have consumed "<<total_cal<<" calories.";

            
            return 0;
}

