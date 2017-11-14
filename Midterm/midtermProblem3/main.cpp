

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::fixed;

int main(int argc, char** argv) {
int input, num, ones, tens, hundreds, thousands;
    
string date,payee,name;


  
cout<<"Please enter date: ";
getline(cin,date);

cout<<endl;
  
cout<<"Please enter payee name: ";
getline(cin,payee);
cout<<endl;

cout<<"Please enter account holder name: ";
getline(cin,name);
cout<<endl;

cout<<"Enter the amount paid."<<endl;
cout<<"The value should be an integer between $1 and $1999. No cents: ";
cin>> num;

cout<<name<<endl;
cout<<"STREET ADDRESS"<<endl;
cout<<"CITY, STATE, ZIP "<<"\t\t\t\tDate: "<<date<<endl;
cout<<endl;

cout<<"Pay to the order of: "<<payee<<" \t\t$ "<<num<<".00"<<endl;
cout<<"\n";

if (num==0)
cout<<"Zero";

thousands=num/1000%10;

switch (thousands)
{
case 1:
cout<<"One Thousand ";
break;
}


hundreds=num/100%10;

switch (hundreds)
{
case 1:
cout<<"One Hundred ";
break;

case 2:
cout<<"Two Hundred ";
break;

case 3:
cout<<"Three Hundred ";
break;

case 4:
cout<<"Four Hundred ";
break;

case 5:
cout<<"Five Hundred ";
break;

case 6:
cout<<"Six Hundred ";
break;

case 7:
cout<<"Seven Hundred ";
break;

case 8:
cout<<"Eight Hundred ";
break;

case 9:
cout<<"Nine Hundred ";
break;

}


tens=num/10%10;

switch (tens)
{
case 2:
cout<<"Twenty ";
break;

case 3:
cout<<"Thirty ";
break;

case 4:
cout<<"Forty ";
break;

case 5:
cout<<"Fifty ";
break;

case 6:
cout<<"Sixty ";
break;

case 7:
cout<<"Seventy ";
break;

case 8:
cout<<"Eighty ";
break;

case 9:
cout<<"Ninety ";
break;

}

ones=num%10;
if(ones>=1&&ones<=19)

{
switch (ones)
{
case 0:
cout<<" ";
break;

case 1:
cout<<"One";
break;

case 2:
cout<<"Two";
break;

case 3:
cout<<"Three";
break;

case 4:
cout<<"Four";
break;

case 5:
cout<<"Five";
break;

case 6:
cout<<"Six";
break;

case 7:
cout<<"Seven";
break;

case 8:
cout<<"Eight";
break;

case 9:
cout<<"Nine";
break;

case 10:
cout <<"Ten";
break;

case 11:
cout <<"Eleven";
break;

case 12:
cout <<"Twelve";
break;

case 13:
cout <<"Thirteen";
break;

case 14:
cout <<"Fourteen";
break;

case 15:
cout <<"Fifteen";
break;

case 16:
cout <<"Sixteen";
break;

case 17:
cout <<"Seventeen";
break;

case 18:
cout <<"Eighteen";
break;

case 19:
cout <<"Nineteen";
break;

default:
cout <<"Error ";
}
}
  
cout<<" and no/100s Dollars."<<endl;
cout<<"\n";
cout<<"BANK OF CIS5"<<endl;
cout<<"\n";
cout<<"FOR: GOTTA PAY THE RENT"<<"\t\t\t"<<name;
  
}


  

