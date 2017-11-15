#include <iostream>
#include <cmath>

using namespace std;


float futureValue(float,float,int);


int main(int argc, char** argv) {

    float p,i,t,f;
    
    cout<<"Please enter the amount of money currently in the account: ";
    cin>>p;
    
    cout<<"Please enter the monthly interest rate: ";
    cin>>i;
    
    cout<<"Please enter the numbers of month the money will be in the account: ";
    cin>>t;
    
    f=futureValue(p,i,t);
    
    cout<<"The account will have $"<<f<<" in it after "<<t<<" months.";
    
    return 0;
}

float futureValue(float p, float i, int t)
{
float f;
f=p*pow(1+i,t);
return f;
}

