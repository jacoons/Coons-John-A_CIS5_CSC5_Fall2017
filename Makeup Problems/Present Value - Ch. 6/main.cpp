#include<iostream>
#include<cmath>
using namespace std;

double presentValue(double F, double r, double n);

int main(int argc, char** argv) 
{
    double result, futureValue, annualRate, years;
    
    cout<<"Enter future value: ";
    cin>>futureValue;
    
    cout<<"Enter annual interest rate: ";
    cin>>annualRate;
    
    cout<<"Enter number of years: ";
    cin>>years;
    
    result = presentValue(futureValue,annualRate,years);
    
    cout<<"Need to deposit: $"<<result;
    
    
}

double presentValue(double F,double r, double n)
{
    double P;
    
    P=F/(pow((1+r),n));
    
    return P;
}