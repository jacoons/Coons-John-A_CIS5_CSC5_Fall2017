
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    float initial, dailyInc, days;
    
    cout<<"Enter the starting population of an organism: "<<endl;
    cin>> initial;
    
    if (initial < 2)
    {
        cout<<"INVALID INPUT ||| Please reenter: "<<endl;
        cin>> initial;        
    }
    
    cout<<"Enter the daily population percentage increase: "<<endl;
    cin>> dailyInc;
    
    if (dailyInc < 0)
    {
        cout<<"INVALID INPUT ||| Please reenter: "<<endl;
        cin>> dailyInc;
    }
    
    dailyInc = (dailyInc*initial)/100;
    
    cout<<"Enter the duration you would like the data for (in days): "<<endl;
    cin>> days;
    
    for (int counter = 0; counter <= days; counter++)
    {
        initial = initial + dailyInc;
        cout<<"Day "<<days<<" will have an increase of %"<<initial<<"."<<endl;
    }
        
    
    return 0;
}

