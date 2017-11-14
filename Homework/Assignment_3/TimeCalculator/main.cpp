
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    int sec, min, hour, day;
    
       
    cout<<"Enter a quantity of seconds: "<<endl;
    cin>> sec;
        
    if (sec >= 60 && sec < 3600)
    {    
        min = sec / 60;
        cout<<"There are/is "<<min<<" minute(s) in "<<sec<<" seconds."<<endl;
    }    
            
    else if (sec >= 3600 && sec < 86400)
    {    
        hour = sec / 3600;
        cout<<"There are/is "<<hour<<" hours(s) in "<<sec<<" seconds."<<endl;
    }    
    else if (sec >= 86400)
    {    
        day = sec / 86400;
        cout<<"There are/is "<<day<<" days(s) in "<<sec<<" seconds."<<endl;    
    }    
        
    
    

    return 0;
}

