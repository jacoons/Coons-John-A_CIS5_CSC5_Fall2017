#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int X;
    
    cout<<"Enter an integer between the values of 1 and 10:"<<endl;
    cin>> X;
    
    if (X<1 || X>10)
    {
        cout<<"Please enter a valid option:"<<endl;
        cin>> X;
       
    }
    
    switch (X)
    {
        case 1: cout<<X<<" in Roman Numeral form is I."<<endl;
                break;
        case 2: cout<<X<<" in Roman Numeral form is II."<<endl;
                break;        
        case 3: cout<<X<<" in Roman Numeral form is III."<<endl;
                break;
        case 4: cout<<X<<" in Roman Numeral form is IV."<<endl;
                break;
        case 5: cout<<X<<" in Roman Numeral form is V."<<endl;
                break;
        case 6: cout<<X<<" in Roman Numeral form is VI."<<endl;
                break;        
        case 7: cout<<X<<" in Roman Numeral form is VII."<<endl;
                break;
        case 8: cout<<X<<" in Roman Numeral form is VIII."<<endl;
                break;    
        case 9: cout<<X<<" in Roman Numeral form is IX."<<endl;
                break;
        case 10: cout<<X<<" in Roman Numeral form is X."<<endl;
                break;        
                
                
    }
    return 0;
}

