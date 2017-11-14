#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    float fee = 2500;
    
    cout<<"Membership fees for the next 6 years: "<<endl;
    cout<<"--------------------------------------"<<endl;
    
    for (int year =1; year <= 6; year++)
    {    
        cout<<"The annual fee for year "<<year<<" is $"<<fee<<"."<<endl;
        fee = fee * 1.04;
        
    }    
   
    
            
            
    
    
    
    

    return 0;
}

