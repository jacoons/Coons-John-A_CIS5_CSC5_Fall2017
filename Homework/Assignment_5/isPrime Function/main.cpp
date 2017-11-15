#include <iostream>

using namespace std;

bool isPrime(int);

int main(int argc, char** argv) {
    
    int number;
    
    cout<<"Please enter a number for evaluation: ";
    cin>>number;
    
    if(isPrime(number))
        cout<<"The number you entered is not a prime number."<<endl;
    else
        cout<<"The number you entered is not a prime number."<<endl;
}

bool isPrime(int num)
{
    int count = 0;
    for(int i=2; i<=num/2; i++)
    {
        if(num%i==0)
            count++;
    }
    if(count>0)
        return false;
    else
        return true;
}
