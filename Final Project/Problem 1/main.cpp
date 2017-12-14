#include <iostream>
using namespace std;

int main() {
unsigned short int n;
short int reverse = 0;

cout << "Please enter an integer: ";
cin >> n;
if(n < 65535) 
{
while(n != 0) {
int remainder = n%10;
if((reverse*10 + remainder) > 32767)
{
cout << "no conversion possible"<< endl;
return 0;
}
reverse = reverse*10 + remainder;
n/=10;
}
cout << "Reversed number = " << reverse << endl;
}
else
{
cout << "no conversion possible"<< endl;
}
return 0;
}