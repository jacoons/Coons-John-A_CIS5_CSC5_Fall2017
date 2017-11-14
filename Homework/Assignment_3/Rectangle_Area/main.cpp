
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    int length1, length2, width1, width2, area1, area2;
    
    cout<<"What is the length of your first triangle?"<<endl;
    cin>> length1;
    
    cout<<"What is the width of your first triangle?"<<endl;
    cin>> width1;
    
    area1 = width1 * length1;
    
    cout<<"What is the length of your second triangle?"<<endl;
    cin>> length2;
    
    cout<<"What is the width of your second triangle?"<<endl;
    cin>> width2;
    
    area2 = width2 * length2; 
    
    if (area1 == area2)
        cout<<"The area of each triangle is the same"<<endl;
    
    if(area1 < area2)
        cout<<"The area of the second triangle is greater than the first."<<endl;
    
    if(area1 > area2)
        cout<<"The area of the first triangle is greater than the second."<<endl;    
    
    
    
    
    
    
    
    
    
    
    

    return 0;
}

