#include <iostream>

using namespace std;

int main()
{
    float meal, tax, tip;
    
    meal=88.67;
    tax=0.0675*meal;
    tip=(meal+tax)*.2;
    
    cout<<"The meal cost $"<<(meal)<<"."<<endl;
    cout<<"The tax is $"<<(tax)<<"."<<endl;
    cout<<"The tip is $"<<(tip)<<"."<<endl;
      
           
    return 0;
}

