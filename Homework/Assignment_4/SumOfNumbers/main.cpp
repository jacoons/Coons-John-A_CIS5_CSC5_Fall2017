#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    int number, sum = 0;
    
    cout<<"Please enter a positive integer: ";
    cin>> number;
    
    while (number < 0)
    {    
        cout<<"Please enter a positive integer: ";
        cin>> number;
    }        
    
    for (int count = 1; count <= number; count++)
    {
        sum = sum + count;
    }    
      
    cout<<"The sum of all numbers up to "<<number<<" is "<<sum<<"."<<endl;
      
    
    
    
    return 0;
}

