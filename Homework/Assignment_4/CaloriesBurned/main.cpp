#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    const int MINUTE_INC = 5,
              END = 30;   
    
    float burned = 3.6;
    int min = 0;
    
    for (min; min <= END; min+=MINUTE_INC)
    {    
        
        float min2, cal;
        cal = burned * min;
        cout<<"After running for "<<min2<<" minutes you have burned "<<cal<<
                " calories!"<<endl;
        
        min2 = min + MINUTE_INC;
        
    }            
                
                
    return 0;
}

