#include <iostream>
using namespace std;

float celcius(float f);

int main(int argc, char** argv) 
{
    cout<<"Celcius Temperature Table"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Fahrenheit \t Celcius"<<endl;
    cout<<"-------------------------"<<endl;
    
    for(int count=0; count<=20; count++ )
    {
        float cTemp = celcius(count);
        cout<<count<<"\t\t"<<cTemp<<endl;
    }
}
        
    float celcius(float f)
    {
        float celcius = (5*(f - 32))/9;
        return celcius;
    }
  
    
