#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int num, big, sml;
    
    cout<<"Please enter the desired positive integers.\n";
    cout<<"Enter the value of -99 to quit: "<<endl;
    cin>> num;
    
    big = sml = num;
    
    while (num != -99)
    {
        
        if (num < sml)
            sml = num;
        
        if (num >big)
            big = num;
        
        cin>> num;
       
    }   
    
    cout<<"The largest number is "<<big<<"."<<endl;
    cout<<"The smallest value is "<<sml<<"."<<endl;
    
    
    return 0;
}

