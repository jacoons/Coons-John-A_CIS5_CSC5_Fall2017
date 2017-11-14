#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    float w, m;
    
    cout<<"Enter the mass of an object: "<<endl;
    cin>> m;   
    
    w = m * 9.8;
    
    if (w > 1000)
        cout<<"Object is too heavy.";
    if(w < 10)
        cout<<"Object is too light.";
    if(w >= 10 && w <= 1000)        
        cout<<"The object weighs "<<w<<"N."<<endl;
    
    
    
    
    
    return 0;
}

