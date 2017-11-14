#include<iostream>

using namespace std;
int main(int argc, char** argv) {
    
int hours;
double pay;

cout <<"How many hours did the employee work?";
cin >> hours;

cout <<"What is the employees rate of pay? ";
cin >> pay;

double gross_pay = 0;

if(hours<=40) 
gross_pay = hours*pay;

else if(hours>40 && hours<=50) 
gross_pay = 40*pay + pay*1.5*(hours-40);

else if(hours>50) 
gross_pay = 40*pay + pay*1.5*10+pay*2*(hours-50);


cout <<"The employees gross pay is: $" << gross_pay << endl;
return 0;
}