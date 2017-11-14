#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{

int sub,hours;
float save,bill;

cout<<fixed<<setprecision(2);

cout <<"Please choose a monthly package from below: "<<endl;
cout<<"\n";
cout << "Monthly Packages"<<endl;
cout<<"\n";
cout << "1 - $16.75 per month for 5 hours of access"<<endl;
cout << "2 - $23.75 per month for 15 hours of access"<<endl;
cout << "3 - $29.95 per month for unlimited access"<<endl;

cout<<"\n";
cin>>sub;
cout<<"\n";

cout<<"How many hours per month do you use data? ";
cin>>hours;

switch (sub)
{
    
case 1:
if (hours>20)
{
bill = (hours-20)*1 +(15)*0.85+16.75;
cout <<"Your bill will be: $"<<bill<<endl;
}

if (hours>5 && hours<=20)
{
bill = (hours-5)*0.85 + 16.75;
cout <<"Your bill will be: $"<<bill<<endl;
}

if(hours<=5)
{
bill = 16.75;
cout <<"Your bill will be: $"<<bill<<"."<<endl;
}
break;

case 2:    
if (hours>25)
{
bill = (hours-25)*0.75 +(10)*0.65+23.75;
cout <<"Your bill will be: $"<<bill<<endl;
}

if (hours>15 && hours<=25)
{
bill = (hours-15)*0.75 + 23.75;
cout <<"Your bill will be: $"<<bill<<endl;
}

if(hours<=15)
{
bill = 23.75;
cout <<"Your bill will be: $"<<bill<<endl;
}
break;

case 3:
bill=29.95;
cout <<"Your bill will be: $"<<bill<<endl;
break;
default:
    
cout <<"Your choice is invalid."<<endl;
}

if (hours>25 && (sub==1 || sub==2)){
    
cout<<"Your most cost efficient option is package 3."<<endl;
save = bill - 29.95;
cout<<"This option will save you: $"<<save;

}
else if ((hours>=15 && hours<= 25 )&& (sub==3||sub==1)){
cout<<"Your most cost efficient option is package 2."<<endl;

if(sub==3)
save = bill - ((hours-15)*0.65 + 23.75);

else if(sub==1)
save = bill - ((hours-20)*1 +(15)*0.85+16.75);

cout<<"This option will save you: $"<<save;
}

else if ((hours>5 && hours< 15 )&& (sub==3||sub==2)){
    
cout<<"Your most cost efficient option is package 1."<<endl;
save = bill - ((hours-5)*0.85 + 16.75);
cout<<"This option will save you: $"<<save;

}
else if (hours<=5 && (sub==3||sub==2)){
    
cout<<"Your most cost efficient option is package 1."<<endl;
save = bill - (16.75);
cout<<"This option will save you: $"<<save;

}
else{
    
cout<<"Your current selections are of optimal financial efficiency.";

}
return 0;
}

