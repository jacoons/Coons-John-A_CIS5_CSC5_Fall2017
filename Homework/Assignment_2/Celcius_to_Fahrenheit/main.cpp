
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    float celcius, fahrenheit;
          
    cout<<"What is the temperature in Celsius?"; 
    cin>>celcius;
    
    fahrenheit=9.0/5.0*celcius+32.0;
    
    
    cout<<"The temperature in Fahrenheit is "<<fahrenheit<<" degrees.";
            
    
            
    return 0;
}

