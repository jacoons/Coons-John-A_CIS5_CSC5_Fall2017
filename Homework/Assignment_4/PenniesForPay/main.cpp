
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int days;
    float pay, total = 0;
    
    
    do
    {
        
    cout<<"How many days did you work? ";
    cin>> days;
    
    if (days < 0)
        
        cout<<"Invalid selection!"<<endl;  
        break;
    
    }   
    while (days > 0);
    
        cout<<"----------------------"<<endl;
        cout<<"DAY\t\tPAY"<<endl;
        cout<<"----------------------"<<endl;
        pay = 0.01;
    
    for (int count = 1; count <= days; count++)
    {
      
        
        cout<<count<<"\t\t$"<<pay<<endl;
         total = total + pay;
         pay = pay + pay;
        
        
        
    }
        cout<<"\nTotal pay for "<<days<<" days is $"<<total<<"."<<endl;
    
    
    return 0;
    }
    


